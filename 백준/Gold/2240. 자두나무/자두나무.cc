#include <bits/stdc++.h> 
using namespace std; 

int T,W;
int dp[1001][2][31];
int a[1001];
// idx 1부터 T까지 
int go(int idx, int tree, int cnt){ //1번 트리 0 , 2번 트리 1 
	if(cnt<0) return -1e9;
    if(idx>T) return 0;
    if(dp[idx][tree][cnt]!=-1) return dp[idx][tree][cnt];
	int move=go(idx+1, tree^1, cnt-1);
	int skip=go(idx+1, tree, cnt);
	int ja=(a[idx]-1==tree);
	return dp[idx][tree][cnt]=max(move,skip)+ja;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>T>>W;
	for(int i=1; i<=T; i++){
		cin>>a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<go(0,0,W);
}