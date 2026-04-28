#include <bits/stdc++.h>
using namespace std;

int a[8];
vector<pair<int,int>> v{};
int ans;

int main(){
	for (int i=0; i<8; i++){
		cin>>a[i];
		v.push_back({a[i], i+1});
	}
	sort(v.begin(),v.end(), greater<pair<int,int>>());
	for (int i=0; i<5; i++){
		ans+=v[i].first;
	}
	cout<<ans<<'\n';
	vector<int> idx;
	for (int i=0; i<5; i++){
		idx.push_back(v[i].second);
	}
	sort(idx.begin(),idx.end());
	for (int i=0; i<5; i++){
		cout<<idx[i]<<' ';
	}
}