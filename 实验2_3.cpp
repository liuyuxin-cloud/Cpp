#include <iostream>
#include <math.h>
using namespace std;
const float PI = 3.14159;

class Circle
{
private:
    /* data */
    int r;
public:
	
	void setR(int radius){
		r = radius;
	}
	
    double area(){
        return r*PI;
    }

    double sum(Circle circleArray[],int size){
        double sum;
        for(int i=0 ; i<size ; i++){
            sum += circleArray[i].area();
        }
        return sum;
    }
};