#include <bits/stdc++.h> 
using namespace std; 

int N;
int a[104];
long long dp[100][25];

long long go(int idx, int val){ // 0 + , 1 -
	if(idx==N-2){
		if(val==a[N-1]) return 1;
		else return 0;
	}
	if(val<0 || 20<val) return 0;
	long long &res=dp[idx][val];
	if(res!=-1) return res;
	res=0;
	res += go(idx+1,val+a[idx+1]);
	res += go(idx+1,val-a[idx+1]);
	return res;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<go(0,a[0]);
}