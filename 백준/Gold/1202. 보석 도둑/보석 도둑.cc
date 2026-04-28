#include <bits/stdc++.h> 
using namespace std; 

int N,K;
long long ans;
vector<pair<int,int>> v;
priority_queue<int, vector<int>,greater<int>> bag; //오름차순 -> 작은값 나옴 
priority_queue<int> value;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>K;
	for(int i=0; i<N; i++){
		int m, va;
		cin>>m>>va;
		v.push_back({m,va});
	}
	for(int i=0; i<K; i++){
		int c;
		cin>>c;
		bag.push(c);
	}
	// 무게순으로 정렬
	sort(v.begin(), v.end()); 
	// v.first 중에 bag[i]보다 작거나같으면 pq에 추가
	int idx=0;
	while(!bag.empty()){
		int b=bag.top();
		bag.pop();
		for(int i=idx; i<v.size(); i++){
			if(v[i].first<=b){
				value.push(v[i].second);
				idx=i+1;
			}
			else break;
		}
		if(!value.empty()){
			ans+=value.top();
			value.pop();
		}
	}
	cout<<ans; 
}
