#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int a[101][101];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
bool visit[10004];
int cnt;
int w;
vector<int> v;
int M,N,K;
int z;

void DFS(int x, int y){
	visit[x*N+y]=true;
	z++;
	for (int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||nx>=M||ny<0||ny>=N) continue;
		if (a[nx][ny]==0 && !visit[nx*N+ny]){
			DFS(nx,ny);
//			cout<<z;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>M>>N>>K;
	for (int i=0; i<K; i++){
		int x1,y1,x2,y2;
		cin>>y1>>x1>>y2>>x2;
		for (int i=M-x2; i<M-x1; i++){
			for (int j=y1; j<y2; j++){
				a[i][j]=1;
			}
		}
	}
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
//			cout<<a[i][j]<<' ';
			if(a[i][j]==0 && !visit[i*N+j]){
				DFS(i,j);
				v.push_back(z);
				cnt++;
				z=0;
			}
		}
//		cout<<endl;
	}
	cout<<cnt<<'\n';
	sort(v.begin(),v.end());
	for (int i : v){
		cout<<i<<' ';
	}
}