#include<bits/stdc++.h> 
using namespace std;  

int N;
vector<int> v;
int a;
double avg;

 
int main(){  
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>a;
		v.push_back(a);
	}
	int max=*max_element(v.begin(),v.end());
//	cout<<max;
	for (auto i : v){
		avg += (double)i/max*100;
//		cout<<avg<<' ';
	}

	avg /= N;
	cout<<avg;
}