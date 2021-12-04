#include<iostream>
using namespace std;

template<class T>
class Stack{
    private:
        int size = 0;
        T elements[100];
    public:
        Stack(){}
        
        bool empty(){
            if(size == 0)   return true;
            return false;
        }    

        T peek(){
            return elements[size-1];
        }

        void push(T value){
            if(size < 100){
                size++;
                elements[size-1] = value;
            }else{
                cout <<"Stack is full!"<<endl;
            }
        }

        T pop(){
            if(size > 0){
                return elements[--size];
            }else{
                cout << "Stack is empty!"<< endl;
            }
        }

        int getSize(){
            return size;
        }
};

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << " " << s.getSize() << " "<< s.empty() << endl;
    cout << s.pop() << " " << s.peek() << endl;

    Stack<double> s1;
    s1.push(1.1);
    s1.push(2.2);
    s1.push(3.3);
    cout << s1.peek() << " " << s1.getSize() << " "<< s1.empty() << endl;
    cout << s1.pop() << " " << s1.peek() << endl;

}