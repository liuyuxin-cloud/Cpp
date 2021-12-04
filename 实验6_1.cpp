#include<iostream>
using namespace std;

template <class T>
bool isSorted(T* start, T* end){
    T* p = start;
    for(; p < end; p++){
        if(*(p-1) >= *p){
            return false;
        }
    }
    return true;
}

int main(){
    int test1[5] = {1,2,3,4,5};
    int test2[5] = {1,5,2,4,8};
    double test3[5] = {1.2,2.3,3.4,4.5,5.6};
    double test4[5] = {5.1,4.2,8.5,4.6,9.7};
    cout << isSorted(test1, test1+5) << endl;
    cout << isSorted(test2, test2+5) << endl; 
    cout << isSorted(test3, test3+5) << endl;
    cout << isSorted(test4, test4+5) << endl;
}