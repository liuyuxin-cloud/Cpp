 #include <iostream>
 #include "实验3_1.cpp"
 #include "实验3_2.cpp"
 using namespace std;

int main(){
    MyInteger test = MyInteger(120);
    MyInteger t = MyInteger(2);
    StackOfIntegers s = StackOfIntegers();
    while(test.isPrime(test.getValue()) != true){  //还不是质数时继续分解
        for(int i=2 ; i<test.getValue() ; i++){
        	t.setValue(i);
            if(test.getValue() % i == 0 &&  t.isPrime(t.getValue()) == true){  
                s.push(i);
                test.setValue(test.getValue() / i);
                break;
            }
        }
    }
    s.push(test.getValue());
    while(s.getSize() > 0){
        cout << s.pop() << endl;
    }
}