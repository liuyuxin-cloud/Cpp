#include <iostream>
using namespace std;

class Employee{
    private:
        char* m_name;
        char* m_no;
    public:
        Employee(char *name, char *no){
            cout << "Employee类的构造函数调用！" << endl; 
            m_name = name;
            m_no = no;
        }
        void display(){
            cout << "姓名:" << " " << m_name << endl;
            cout << "员工编号:"<< " " << m_no << endl;
        }
        virtual ~Employee(){
            cout << "Employee类的析构函数调用！" << endl;
        }
};

class Leader : public Employee{
    private:
        char* m_posdes;
    public:
        Leader(char *name, char *no, char *posdes) : Employee(name, no){
            cout << "Leader类的构造函数调用！" << endl;
            m_posdes = posdes;
        }    
        void display(){
            Employee :: display();
            cout << "职位描述:" << " " << endl;
        }
        virtual ~Leader(){
            cout << "Leader类的析构函数调用！" << endl;
        }
};

int main(){
    Employee *pe = new Leader("张三", "0001", "部门经理");
    pe->display();
    delete pe;
    return 0;
} 