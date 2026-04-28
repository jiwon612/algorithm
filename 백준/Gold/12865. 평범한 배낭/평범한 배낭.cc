#include <bits/stdc++.h> 
using namespace std; 

int N,K; 
pair <int, int> v[101];
int dp[100001][101];

int go(int weight, int idx){
	if(weight>K) return -1e9; 
	if(idx==N) return 0;
	if(dp[weight][idx]!=-1) return dp[weight][idx];
	int pick=go(weight+v[idx].first, idx+1)+v[idx].second;
	int skip=go(weight, idx+1);
	return dp[weight][idx]=max(pick, skip);
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	cin>>N>>K;
	for(int i=0; i<N; i++){
		int W,K;
		cin>>W>>K;
		v[i].first=W;
		v[i].second=K;
	}
	memset(dp, -1, sizeof(dp));
	cout<<go(0,0);
}