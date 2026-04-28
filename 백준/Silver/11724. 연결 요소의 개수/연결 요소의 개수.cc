#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[1000];
bool visit1[1000];
bool visit2[1000];
int N,M,V,a,b,cnt;

void BFS(int idx){
    visit2[idx]=true;
    queue<int> q;
    q.push(idx);
	while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int yy= v[x][i];
            if(!visit2[yy]){
                q.push(yy);
                visit2[yy]=true;
            }
        }
    }
    cnt++;
    for (int j=1; j<=N; j++){
        if(!visit2[j]){
            BFS(j);
        }
    }
}



int main() {
	cin>>N>>M;
    for (int i=0; i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
	BFS(1);
    cout<<cnt;
}