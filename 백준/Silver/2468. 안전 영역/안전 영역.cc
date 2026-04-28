#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int a[100][100];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
bool visit[10004];
int mm;
int N;

void DFS(int x, int y, int z){
	visit[x*N+y]=true;
	for (int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
		if(a[nx][ny]>z && !visit[nx*N+ny]){
			DFS(nx,ny,z);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int b;
			cin>>b;
			a[i][j]=b;
		}
	}
	for(int k=0; k<=100; k++){
		int cnt=0;
		fill(&visit[0], &visit[0]+10004,0);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(a[i][j]>k && !visit[i*N+j]){
					DFS(i,j,k);
					cnt++;
				}
			}
		}
		if(cnt>mm){
			mm=cnt;
		}
//		cout<<cnt<<endl;
	}
	cout<<mm;
}