#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point{
    int x;
    int y;
};

class Rule1{
    public:
    bool operator()(const int &a, const int &b){
        if(a % 10 > b % 10 || a % 10 == b % 10 && a > b) return false;
        else return true; 
    }
};

class Rule2{
    public:
    bool operator()(const Point &a, const Point &b){
        double dis1 = sqrt(a.x*a.x + a.y*a.y);
        double dis2 = sqrt(b.x*b.x + b.y*b.y);
        if(dis1 < dis2 || dis1 == dis2 && a.x < b.x || dis1 == dis2 && a.x == b.x && a.y < b.y)   return true;
        else return false;
    }
};

int main(){
    int a[8] = {6,5,55,23,3,9,87,10};
    sort(a,a+8,Rule1());
    for(int i = 0; i < 8; i++){
        cout << a[i] << ",";
    }
    cout << endl;
    Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0}};
    sort(ps,ps+8,Rule2());
    for(int i = 0; i < 8; i++){
        cout << "(" << ps[i].x << "," << ps[i].y << ")";
    }
    return 0;
}
