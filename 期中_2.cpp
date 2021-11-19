#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Clock {
private:
    int h;
    int m;
    int s;
    int zone;
public:
    Clock(int _h, int _m, int _s, int _zone){
        h = _h;
        m = _m;
        s = _s;
        zone = _zone; // 范围[-12, 12] 例如 中国为+8
    }  
    bool operator>(Clock c){
        //先比较小时加上偏移值
        if((h + zone) > (c.h + c.zone))    return true;
        else if((h + zone) < (c.h + c.zone))    return false;
        if(m > c.m)    return true;
        else if(m < c.m)    return false;
        if(s > c.s)    return true;
        else if(s < c.s)    return false;
        else return false;
    }
    void showParams(){
        cout << h << ':' << m << ':' << s << ' ' << zone << endl;
    }      
};

void showClock(Clock* c[], int len){
    for(int i = 0; i < len; i++){
        c[i]->showParams();
    }
}

int main() {
    // 初始化随机种子
    srand((unsigned)time(NULL));
    int count = 20;
    Clock* c[count];

    // 定义 count 个Clock对象，其h, m, s, zone均由随机生成
    // rand()函数 随机生成 0 到无穷  之间的一个整数
    for(int i = 0; i < count; i++){
        int h = rand() % 24;
        int m = rand() % 60;
        int s = rand() % 60;
        int zone = rand() % 25 - 12;
        Clock * cs = new Clock(h, m, s, zone);
        c[i] = cs; 
    }

    showClock(c, count);

    // 对 count个Clock按格林威治标准时间按升序排序
    for(int i = 0; i < count-1; i++){
        for(int j = 0; j < count-1-i; j++){
            if(*c[j] > (*c[j+1])){
                Clock* temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
    // 显示排序后的结果
    showClock(c, count);
    // 释放动态数组空间
    delete[] c;
    return 0;
}
