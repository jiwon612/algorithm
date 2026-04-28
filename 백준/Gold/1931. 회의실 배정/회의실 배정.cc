#include <bits/stdc++.h> 
using namespace std; 

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second) return a.first<b.first;
	return a.second < b.second;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		int s, e;
		cin>>s>>e;
		v.push_back({s,e});
	}
	sort(v.begin(), v.end(), cmp);
	int end=v[0].second;
	int cnt=1;
	for(int i=1; i<N; i++){
		if(v[i].first>=end){
			end=v[i].second;
			cnt++;
		}
	}
	cout<<cnt;
}