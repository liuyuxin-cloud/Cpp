#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
	
	void setXY(int coordinateX,int coordinateY){
		x = coordinateX;
		y = coordinateY;
	} 
	
    double distance(const Point &p){
        return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
    }
};