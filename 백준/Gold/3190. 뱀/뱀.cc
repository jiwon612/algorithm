#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N,K,L;
vector<pair<int, char>> dir;
int a[101][101];
int time;
int hx=1,hy=1;
queue<pair<int, int>> snake;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int i;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>N>>K;
	for(int i=0; i<K; i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=2;
	}
	cin>>L;
	for(int i=0; i<L; i++){
		int t;
		char d;
		cin>>t>>d;
		dir.push_back({t,d});
	}
	snake.push({1,1});
	a[1][1]=1;
	while(true){
		time++;
		hx=hx+dx[i];
		hy=hy+dy[i];
		if(hx<1 || N<hx || hy<1 || N<hy) break;
		if(a[hx][hy]==1) break;
		if(a[hx][hy]==0){
			pair<int,int> tail=snake.front();
			a[tail.first][tail.second]=0;
			snake.pop();
		}
		a[hx][hy]=1;
		snake.push({hx,hy});
		if(!dir.empty() && time==dir[0].first){
			if(dir[0].second=='L'){
				i=(i+3)%4;
				dir.erase(dir.begin());
			}
			else if(dir[0].second=='D'){
				i=(i+1)%4;
				dir.erase(dir.begin());
			}
		}
	}
	cout<<time;
}
