#include<iostream>
#include<vector>

using namespace std;

bool visit1[100001];
bool visit2[100001];
bool visit3[100001];
bool visit4[100001];
vector<int> v[100001];
vector<int> rev[100001];
int n,m,S,T;

void dfs(int x, int y, bool visit[], vector<int> adj[]){
    if(visit[x]) return;
    visit[x]=true;
    if(x==y) return;
    for(int i=0; i<adj[x].size(); i++){
        int a=adj[x][i];
        dfs(a,y,visit,adj);
    }
}

int main(int argc, char** argv)
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        rev[y].push_back(x);
    }
    cin>>S>>T;
    dfs(S,T,visit1,v);
    dfs(T,-1,visit2,rev); // 중복 탐색, S를 거쳐도 상관없으므로 모든 경로 탐색
    dfs(T,S,visit3,v);
    dfs(S,-1,visit4,rev);
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(i==S || i==T) continue;
        if(visit1[i] && visit2[i] && visit3[i] && visit4[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

// S->X->T 가 되려면 S->X, T->X(역방향) 확인
// T->S일 때도, 총 4번