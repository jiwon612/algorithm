#include <bits/stdc++.h> 
using namespace std; 

int N,ans;
vector<int> v;
priority_queue<int,vector<int>,greater<int>> pq;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		int a;
		cin>>a;
		pq.push(a);
	}
	while(pq.size()>1){
		int sum=0;
		sum+=pq.top();
		pq.pop();
		sum+=pq.top();
		ans+=sum;
		pq.pop();
		pq.push(sum);
	}
	cout<<ans;
}