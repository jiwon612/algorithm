#include <bits/stdc++.h> 
using namespace std; 

int N;
priority_queue<int, vector <int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		int p,d;
		cin>>p>>d; 
		v.push_back({d,p});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; i++){
		pq.push(v[i].second);
		if(pq.size()>v[i].first){ // 현재꺼 강의했을때 기한보다 크면 
			pq.pop();
		}
	}
	int sum=0;
	while(!pq.empty()){
//		cout<<pq.top()<<' ';
		sum+=pq.top();
		pq.pop();
	}
	cout<<sum;
}