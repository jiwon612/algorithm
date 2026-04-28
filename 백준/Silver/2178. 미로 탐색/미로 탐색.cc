#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int a[101][101];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
bool visit[10001];
int N,M;
int cnt[10001];

void BFS(){
	queue<int> q;
	visit[0]=true;
	q.push(0);
	cnt[0]=1;
	while(!q.empty()){
		int idx=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int nx= idx/M +dx[i];
			int ny= idx%M +dy[i];
			int nidx = M*nx+ny;
			if (nx<0||nx>=N||ny<0||ny>=M) continue;
			if (a[nx][ny]=='0') continue;
			if(!visit[nidx]){
				visit[nidx]=true;
				cnt[nidx]=cnt[idx]+1;
				q.push(nidx);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	for (int i=0; i<N; i++){
		string s;
		cin>>s;
		for (int j=0; j<M; j++){
			a[i][j]=s[j];
		}
	} 
	BFS();
	cout<<cnt[N*M-1];
}