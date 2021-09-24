#include <iostream>
#include <math.h>
using namespace std;

class Ctriangle
{
private:
    int sideA;
    int sideB;
    int sideC;
public:
    void setSide(int a,int b,int c){
        if(a+b>c && b+c>a && a+c>b){
            sideA = a;
            sideB = b;
            sideC = c;
        }else{
            cout << "error";
            sideA = 0;
            sideB = 0;
            sideC = 0;
        }
        
    }

    int circunference(){
        return sideA + sideB + sideC;
    }

    double area(){
        double p = (sideA + sideB + sideC) / 2;
        return sqrt(p * (p-sideA) * (p-sideB) * (p-sideC));
    }
};
