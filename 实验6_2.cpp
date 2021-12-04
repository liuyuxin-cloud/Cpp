#include<iostream>
#include<string>
using namespace std;
template <class T>
T ArraySum(T* start, T* end){
    T ans;
    T* p = start;
    for(; p < end; p++){
        ans += *p;
    }
    return ans;
}

int main(){
    string array[4] = {"Tomy", "Jacy", "Mary", "John"};
    cout << ArraySum(array, array+4) << endl;
    int a[4] = {1, 2, 3 ,4};
    cout << ArraySum(a, a+4) << endl;
    return 0;
}