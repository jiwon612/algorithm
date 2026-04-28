#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<string> v;
int a[101][101];
int H,W;


void DFS(int x, int y, int cnt){
	for (int j=y; j<W; j++){
		if(a[x][j+1]==0) break;
		if(a[x][j+1]==-1){
			a[x][j+1]+=cnt;
			cnt++;
			DFS(x, j+1, cnt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>H>>W;
	for (int i=0; i<H; i++){
		string s;
		cin>>s;
		for(int j=0; j<W; j++){
			if(s[j]=='c'){
				a[i][j]=0;
			}
			else{
				a[i][j]=-1;
			}
		}
	}	
	for (int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(a[i][j]==0 && a[i][j+1]==-1){
				DFS(i,j,2);
			}
		}
	}
	for (int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
