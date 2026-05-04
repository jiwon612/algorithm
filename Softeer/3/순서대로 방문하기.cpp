#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

int n,m;
bool visit[5][5];
int mp[5][5];
int cnt;
vector<pair<int,int>> v;

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

void dfs(int x, int y, int idx){
    if(x==v[idx].first && y==v[idx].second){
        if(idx==m-1){
            cnt++;
            return;
        }
        idx++;
    }
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1 || nx>n || ny<1 || ny>n) continue;
        if(!visit[nx][ny] && mp[nx][ny]==0){
            visit[nx][ny]=true;
            dfs(nx,ny,idx);
            visit[nx][ny]=false;
        }
    }
}

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>mp[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    visit[v[0].first][v[0].second]=true;
    dfs(v[0].first, v[0].second, 1);
    cout<<cnt;
    return 0;
}