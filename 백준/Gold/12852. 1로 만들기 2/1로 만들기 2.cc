#include <bits/stdc++.h> 
using namespace std; 

int N;
int dp[1000001];
vector<int> v;
int MIN=1e9;

int go(int n){
	if(n==1) return dp[n]=0;
	if(dp[n]!=-1) return dp[n];
	int &res = dp[n];
	int a=1e9,b=1e9,c=1e9;
	if(n%3==0) {
		a=go(n/3)+1;
	}
	if(n%2==0) {
		b=go(n/2)+1;
	}
	c=go(n-1)+1;
	return res=min({a,b,c});
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	memset(dp, -1, sizeof(dp));
	int ans=go(N);
	int temp=N;
	cout<<ans<<'\n';
//	for(int i=0; i<=N; i++){
//		cout<<dp[i]<<' ';
//	}
	cout<<temp<<' ';
	while(temp>1){
		if(temp%3==0 && dp[temp/3]==ans-1){
			temp/=3;
			v.push_back(temp);
		}
		else if(temp%2==0 && dp[temp/2]==ans-1){
			temp/=2;
			v.push_back(temp);
		}
		else if(dp[temp-1]==ans-1){
			temp-=1;
			v.push_back(temp);
		}
		ans--;
	}
	for(int i:v){
		cout<<i<<' ';
	}
//	for(int i=v.size()-1; i>=0; i--){
//		cout<<v[i]<<' ';
//	}
}