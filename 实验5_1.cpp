#include<iostream>
#include<math.h>
using namespace std;
const double PI = 3.14159;

class shape{
    public:
        virtual double area() const = 0;
};

class Rctangle : public shape{
    private:
        double sideA, sideB, sideC;
    public:
        Rctangle(double a, double b, double c){
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
        double area() const{
            double p = (sideA + sideB + sideC) / 2;
            return sqrt(p * (p-sideA) * (p-sideB) * (p-sideC));
        }    
        bool operator==(const Rctangle c){
            if(sideA == c.sideA && sideB == c.sideB && sideC == c.sideC){
                return true;
            }
            else if(sideA == c.sideA && sideB == c.sideC && sideC == c.sideB){
                return true;
            }
            else if(sideA == c.sideB && sideB == c.sideA && sideC == c.sideC){
                return true;
            }
            else if(sideA == c.sideB && sideB == c.sideC && sideC == c.sideA){
                return true;
            }
            else if(sideA == c.sideC && sideB == c.sideA && sideC == c.sideB){
                return true;
            }
            else if(sideA == c.sideC && sideB == c.sideB && sideC == c.sideA){
                return true;
            }
            else{
                return false;
            }
        }
};

class Circle : public shape{
    private:
        double r;
    public:
        Circle(double _r){
            r = _r;
        }    
        double area() const{
            return PI * r * r;
        }
};