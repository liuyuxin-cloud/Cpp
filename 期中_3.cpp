#include<iostream>
using namespace std;

class CArray{
    //本来打算写成链表的形式，但是时间不太够用就开辟了一个大数组；
    private:
        int len = 0;
        int a[100];
    public:
        int length(){
            return len;
        }    
        void push_back(int i){
            a[len++] = i;
        }
        int& operator[](int i){
            return a[i];
        }
};

int main(){
    CArray a;
    for(int i = 0; i < 5; i++){
        a.push_back(i);
    }
    CArray a2,a3;
    a2 = a;
    for(int i = 0; i < a2.length(); ++i){
        cout << a2[i] <<" ";
    }
    a2 = a3;
    for(int i = 0; i < a2.length(); ++i){
        cout << a2[i] << " ";
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for(int i = 0; i < a4.length(); ++i){
        cout << a4[i] << " ";
    }
    return 0;
}