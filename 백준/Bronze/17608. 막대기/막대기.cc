#include <bits/stdc++.h> 
using namespace std; 

int N;
stack<int> s;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		int a;
		cin>>a;
		s.push(a);
	}
	int cnt=1;
	int now=s.top();
	s.pop();
	while(!s.empty()){
		if(s.top()>now){
			now=s.top();
			cnt++;
		}
		s.pop();
	}
	cout<<cnt;
}
