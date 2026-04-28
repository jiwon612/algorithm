#include <bits/stdc++.h> 
using namespace std; 

int N,ans;
vector<int> v;
priority_queue<int> p;  //내림차순 
priority_queue<int,vector<int>,greater<int>> m; //오름차순 

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		int a;
		cin>>a;
		if(a>0) p.push(a);
		else m.push(a);
	}
	while(!p.empty()){
		if(p.size()==1){
			ans+=p.top();
			break;
		}
		int a=p.top();
		p.pop();
		int b=p.top();
		if(a*b>a+b){
			ans+=a*b;
			p.pop();
		}
		else{
			ans+=a;
		}
	}
	while(!m.empty()){
		if(m.size()==1){
			ans+=m.top();
			break;
		}
		int a=m.top();
		m.pop();
		int b=m.top();
		if(a*b>a+b){
			ans+=a*b;
			m.pop();
		}
		else{
			ans+=a;
		}
	}
	cout<<ans;
}