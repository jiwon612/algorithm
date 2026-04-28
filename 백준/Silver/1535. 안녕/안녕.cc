#include <bits/stdc++.h> 
using namespace std; 

pair<int, int> v[25];
int N;
int MAX=-1e9;
int dp[25][101];

int go(int idx, int sad){
	if(sad<=0) return -1e9;
	if(idx>N) return 0;
	if(dp[idx][sad]!=-1) return dp[idx][sad];
	int pick=v[idx].second+go(idx+1, sad-v[idx].first);
	int skip=go(idx+1, sad);
	return dp[idx][sad]=max(pick, skip);                                      
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=1; i<=N; i++){
		int s;
		cin>>s;
		v[i].first=s;
	}
	for(int i=1; i<=N; i++){
		int j;
		cin>>j;
		v[i].second=j;
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(1,100);
}