#include<iostream>
#include<set>
using namespace std;

void add(multiset<int> &st) {
    int x;
    int count = 0;
    cin >> x;
    st.insert(x);
    multiset<int>::iterator j;
    for(j = st.begin(); j != st.end(); ++j){
        if(*j == x){
            count++;
        }
    }
    cout << count;
}

void del(multiset<int> &st){
    int x;
    int count = 0;
    cin >> x;
    multiset<int>::iterator i;
    for(i = st.begin(); i != st.end(); ++i){
        if(*i == x){
            count++;
            st.erase(i);
        }
    }
    cout << count;
}

void ask(multiset<int> &st){
    int x;
    int count = 0;
    cin >> x;
    multiset<int>::iterator i,j;
    i = st.find(x);
    if(i != st.end()){
        cout << "1" << " ";
        for(j = st.begin(); j != st.end(); ++j){
            if(*j == x){
                count++;
            }
        }
        cout << count;
    }
    else{
        cout << "0" << " " << "0";
    }
}

int main(){
    multiset<int> st;
    char arg[10];
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> arg;
        switch(arg[1]){
            case 'd': add(st); cout << endl;break;
            case 'e': del(st); cout << endl;break;
            case 's': ask(st); cout << endl;break;
        }
    }
}