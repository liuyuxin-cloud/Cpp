#include <iostream>
#include<math.h>
using namespace std;

class Line;

class Point {
private:
    int x;
    int y;
public:
    Point(){}
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }    
friend class Line;
};

class Line {
private:
    Point sp;   // start point
    Point ep;   // end point

public:
    Line(Point p1, Point p2){
        sp = p1;
        ep = p2;
    }
    double len() const{
        return sqrt(pow((sp.x - ep.x) ,2) + pow((sp.y - ep.y), 2));
    }  // 计算线段长度
};


int main() {
    Point p1(1, 3), p2(5, 6);
    Line li(p1, p2);
    cout << "Line len = " << li.len() << endl;
    return 0;
}
