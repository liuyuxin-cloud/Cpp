#include <iostream>
using namespace std;

class StackOfIntegers{
private:
    int elements[100];
    int size;
public:
    StackOfIntegers(){
        size = 0;
    }
    bool empty(){
        if(size == 0){
            return true;
        }
        return false;
    }    
    int peek(){
        return elements[size-1];
    }
    int push(int value){
        if(size <= 100){
            elements[size] = value;
            size++;
            return value;
        }
        else    return -1;
    }
    int pop(){
        size--;
        return elements[size];
    }
    int getSize(){
        return size;
    }
};

int main(){
    StackOfIntegers s = StackOfIntegers();
    cout << s.empty() << endl;
    cout << s.push(1) << endl;
    cout << s.push(2) << endl;
    cout << s.getSize() << endl;
    cout << s.peek() << endl;
    cout << s.empty() << endl;
    cout << s.pop() << endl;
    cout << s.push(1) << endl;
    cout << s.push(1) << endl;
    cout << s.getSize() << endl;
    cout << s.empty() << endl;
}