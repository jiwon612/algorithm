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

void DFS(int x, int y, int M, int N){
	visit[M*x+y]=true;
	a[x][y]=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (0>nx||N<=nx||0>ny||M<=ny) continue;
		if (a[nx][ny]==0) continue;
		if (!visit[M*nx+ny]){
			DFS(nx,ny,M,N);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for (int i=0; i<T; i++){ // 2
		memset(visit, false, sizeof(visit));
		int cnt=0;
		int M,N,K; // 열 M 행 N 
		cin>>M>>N>>K;
		for (int j=0; j<K; j++){
			int X,Y;
			cin>>Y>>X;
			a[X][Y]=1;
		}
		for (int m=0; m<N; m++){
			for (int n=0; n<M; n++){
				if(a[m][n]==1 && !visit[m*M+n]){
					DFS(m,n,M,N);
					cnt++;
//					cout<<m<<' '<<n<<endl;
				}
			}
		}
		cout<<cnt<<'\n';
	}
}