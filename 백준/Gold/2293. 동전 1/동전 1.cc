#include <bits/stdc++.h> 
using namespace std; 

int dp[10001]; 

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			if(j-a[i]>=0) dp[j]+=dp[j-a[i]];
		}
	}
	cout<<dp[k];
}