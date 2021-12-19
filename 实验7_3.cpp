#include <iostream>
#include <string>
#include <fstream>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;

void ReadFileByMap(const string &str, map<string, size_t> &word_count)
{
    ifstream infile(str);
    if (infile)
    {
        string word;
        while (infile >> word)
            ++word_count[word];
    }
}

bool cmp_up(const pair<string, size_t> &x, const pair<string, size_t> &y)
{
    if(x.second > y.second)
        return true;
    else
        return false;
}

int main(int argc, char **argv)
{
    string str = "string.txt";
    map<string, size_t> word_count;
    ReadFileByMap(str, word_count);

    vector<pair<string, size_t> > vMap;
    for (auto it = word_count.begin(); it != word_count.end(); it++)
        vMap.push_back(make_pair(it->first, it->second));

    sort(vMap.begin(), vMap.end(),cmp_up);

    for (auto it = vMap.begin(); it != vMap.end(); it++)
        cout << it->first << ':' << it->second << endl;
    return 0;
}