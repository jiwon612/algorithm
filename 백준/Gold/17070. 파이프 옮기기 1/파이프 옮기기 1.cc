#include <bits/stdc++.h> 
using namespace std; 

int N;
int a[18][18];
int dp[18][18][3];

int go(int x2, int y2, int state){ // 0 가로 1 세로 2 대각선 
	if(x2>=N || y2>=N) return 0;
	if(state==2){
		if(a[x2-1][y2]!=0 || a[x2][y2-1]!=0){
			return 0;
		}
	}
	if(a[x2][y2]==1) return 0;
	if(x2==N-1 && y2==N-1) return 1;
	int &res=dp[x2][y2][state];
	if(res!=-1) return res;
	res=0;
	if(state==0){
		res+=go(x2,y2+1,0);
		res+=go(x2+1,y2+1,2);
	} 
	else if(state==1){
		res+=go(x2+1,y2,1);
		res+=go(x2+1,y2+1,2);
	} 
	else if(state==2){
		res+=go(x2,y2+1,0);
		res+=go(x2+1,y2,1);
		res+=go(x2+1,y2+1,2);
	} 
	return res;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(0,1,0);
}