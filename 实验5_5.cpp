#include <iostream>
using namespace std;

bool isPalindrome(const string &s){
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        if(s.at(i) != s.at(len-i-1)){
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "12321";
    string s2 = "asdf";
    cout << isPalindrome(s1) << endl;
    cout << isPalindrome(s2) << endl;
}
