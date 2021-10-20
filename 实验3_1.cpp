#include <iostream>
#include <math.h>
using namespace std;

class MyInteger{
private:
    int value;
public:
    MyInteger(int v){
        value = v;
    }
    int getValue(){
        return value;
    }
    /*
    我认为以下两个判断函数可以不传参数的，直接判断对象的value值即可.
    */
    bool isEven(int v){
        value = v;
        if(value % 2 == 0){
            return true;
        }
        return false;
    } 
    bool isPrime(int v){
        value = v;
        for(int i=2 ; i<sqrt(value) ; i++){
            if(value % i == 0){
                return false;
            }
        }
        return true;
    }
    bool equals(int anotherV){
        if(value == anotherV)   return true;
        return false;
    }
    bool equals(MyInteger& anotherO){
        if(value == anotherO.value)  return true;
        return false;
    }
};

int main(){
    MyInteger m = MyInteger(7);
    MyInteger m1 = MyInteger(2);
    
    cout << m.getValue() <<endl;
    cout << m.isEven(m.getValue()) <<endl;
    cout << m.isPrime(m.getValue()) <<endl;
    cout << m.equals(10) <<endl;
    cout << m.equals(m1) <<endl;
}