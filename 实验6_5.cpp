#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stdio.h>

using namespace std;

vector<int> v[100]; 
map<int, int> list;
int num  = 0;


void New() {
	int id;
	cin >> id;
	list[id] = num;
	num++;
}

void Add() {
	int id, n;
	cin >> id >> n;
	v[list[id]].push_back(n);
}

void Out() {
	int id;
	cin >> id;
	vector<int>::iterator iter;
    for(iter = v[list[id]].begin(); iter != v[list[id]].end(); iter++)
        cout << *iter << " " ;
	cout << endl;	
}

void Merge() {
	int target, source;
	cin >> target >> source;

	vector<int>::const_iterator i,j;
	vector<int>::const_iterator temp;
	for(i = v[list[source]].begin(); i != v[list[source]].end(); i++){
		for(j = v[list[target]].begin() + 1; j != v[list[target]].end(); j++){
			if(*i >= *(j-1) && *i < *(j) && j < v[list[target]].end()){
				v[list[target]].insert(j, *i);
				cout<<*j<<endl;
				break;
			}
			if(j == v[list[target]].end() - 1){
				temp = i;
				for(temp = i; temp != v[list[source]].end(); temp++){
					v[list[target]].push_back(*temp);
				}
				break;
			}
		}
		if(temp == v[list[source]].end()) break;
	}
	//v[list[target]].insert(v[list[target]].end(), v[list[source]].begin(), v[list[source]].end());
	v[list[source]].clear();
}

void Unique() {
	int id;
	cin >> id;
	set<int> s(v[list[id]].begin(), v[list[id]].end());
	v[list[id]].assign(s.begin(), s.end());
}

int main() {
	int total, i;
	char op[10];
	cin >> total;
	
	num = 0; 
	for (i = 0; i < total; i++) {
		scanf("%s", op); 
		if (!strcmp(op, "new")) {
			New();
		} else if (!strcmp(op, "add")) {
			Add();
		} else if (!strcmp(op, "merge")) {
			Merge();
		} else if (!strcmp(op, "unique")) {
			Unique();
		} else if (!strcmp(op, "out")) {
			Out();
		}
	}
}
 
