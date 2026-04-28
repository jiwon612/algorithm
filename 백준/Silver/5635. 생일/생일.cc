#include <bits/stdc++.h>
using namespace std;

int n;
struct student{
	string name;
	int d,m,y;
};

void print(student i){
	cout<< i.name<<" "<<i.d<<" "<<i.m<<" "<<i.y<<"\n";
}

int main(){
	cin>>n;
	vector<student> v;
	for (int i=0; i<n; i++){
		string name;
		int d,m,y;
		cin>>name>>d>>m>>y;
		v.push_back({name,d,m,y});
	}
//	for (student i : v){
//		print(i);
//	}
	
	// 1. for
	student max_student=v[0];
	student min_student=v[0];
	for(int i=1; i<v.size(); i++){
		if(v[i].y<max_student.y){
			max_student=v[i];
		}
		else if (v[i].y == max_student.y){
			if(v[i].m<max_student.m){
				max_student=v[i];
			}
			else if (v[i].m == max_student.m){
				if(v[i].d<max_student.d){
					max_student=v[i];
				}
			}
		}
	}
	for(int i=1; i<v.size(); i++){
		if(v[i].y>min_student.y){
			min_student=v[i];
		}
		else if (v[i].y == min_student.y){
			if(v[i].m>min_student.m){
				min_student=v[i];
			}
			else if (v[i].m == min_student.m){
				if(v[i].d>min_student.d){
					min_student=v[i];
				}
			}
		}
	}
	cout<<min_student.name<<'\n'<<max_student.name;
}