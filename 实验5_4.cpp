#include <iostream>
#include<string>
#include <sstream>
using namespace std;

string commonChars(const string& s1, const string& s2){
    int len1 = s1.length();
    int len2 = s2.length();
    string ans = "";
    int min = len1 < len2 ? len1 : len2;
    for(int i = 0; i < min; i++){
        if(s1.at(i) == s2.at(i)){
            ans.append(s1, i, 1);
        }
    } 
    return ans;
}



int main(){
    string s1;
    cout << "enter a string s1: ";
    cin >> s1;
    string s2;
    cout << "enter a string s2: ";
    cin >> s2;
    cout << "the common characters are " <<commonChars(s1, s2);
}