#include <bits/stdc++.h>
using namespace std;

int N,C;
vector<pair<int, int>> v;
map<int, int> mp, mp_order;

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first==b.first){
		return mp_order[a.second]<mp_order[b.second]; //숫자 넣어서 order가 더 작은게 더 우선 
	}
	return a.first>b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>C;
	for (int i=0; i<N; i++){
		int a;
		cin>>a;
		mp[a]++;
		if(mp_order[a]==0) mp_order[a]=i+1;
	}
	for (auto i : mp){
		v.push_back({i.second, i.first}); //횟수, 숫자 순 
	}
	sort(v.begin(),v.end(),cmp);
	for (auto i : v){
		for (int j=0; j<i.first; j++){
			cout<<i.second<<' ';
		}
	}
}
