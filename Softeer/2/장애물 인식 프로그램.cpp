#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int N;
int cnt;
int mp[26][26];
bool visit[26][26];
vector<int> ans;
int n;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int,int>> q;
    visit[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
            if(mp[nx][ny]==1 && !visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny]=true;
                n++;
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin>>N;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        for(int j=0; j<N; j++){
            mp[i][j]=s[j]-'0';
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(mp[i][j]==1 && !visit[i][j]){
                n=1;
                bfs(i,j);
                cnt++;
                ans.push_back(n);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<cnt<<'\n';
    for(int i : ans){
        cout<<i<<'\n';
    }
    return 0;
}