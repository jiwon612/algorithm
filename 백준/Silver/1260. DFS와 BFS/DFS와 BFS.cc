#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[1000];
bool visit1[1000];
bool visit2[1000];
int N,M,V,a,b;

void DFS(int idx){
	visit1[idx]=true;
    cout<<idx<<' ';
    for(int i=0; i<v[idx].size(); i++){
        int y=v[idx][i];
   		if(!visit1[y]){
            DFS(y);
        }
        
    }
}

void BFS(int idx){
    visit2[idx]=true;
    queue<int> q;
    q.push(idx);
	while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        for(int i=0; i<v[x].size(); i++){
            int yy= v[x][i];
            if(!visit2[yy]){
                q.push(yy);
                visit2[yy]=true;
            }
        }
    }
}

int main() {

	cin>>N>>M>>V;
    for (int i=0; i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        sort(v[i].begin(), v[i].end());
	DFS(V);
    cout<<endl;
    BFS(V);
}