#include <string>
#include<iostream>
#include <fstream>
using namespace std;

void myfilecopy(const string &str1, const string &str2)
{
    ifstream infile(str1);
    ofstream out(str2, ios::out);
    if (infile)
    {
        string buf;
        while (getline(infile, buf))
            out << buf << endl;
    }
    else
        cerr << "open the file fail: " << str1;
}

int main(int argc, char **argv)
{
    string str1 = "s.txt", str2 = "d.txt";
    myfilecopy(str1, str2);
    return 0;
}