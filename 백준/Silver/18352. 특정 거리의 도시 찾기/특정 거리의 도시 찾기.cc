#include<bits/stdc++.h> 
using namespace std;   

int N,M,K,X;
const int INF=1e9;
vector<int> graph[300004];
vector<int> dist(300004, INF);
vector<int> ans;

void di(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //오름차순 
	dist[X]=0;
	pq.push({0,X});
	while(!pq.empty()){
		int here=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		
		if(dist[u]<here) continue;
		
		for(auto v : graph[u]){
			int new_=here+1;
			if(new_ < dist[v]){
				dist[v]=new_;
				pq.push({new_,v});
			}
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M>>K>>X;
	for(int i=0; i<M; i++){
		int A,B;
		cin>>A>>B;
		graph[A].push_back(B);
	}
	di(X);
	for(int i=1; i<=N; i++){
		if(dist[i]==K){
			ans.push_back(i);
		}
	}
	if(ans.size()){
		sort(ans.begin(), ans.end());
		for(auto i : ans){
			cout<<i<<'\n';
		}
	}
	else cout<<-1;
}