#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;


int N,M;
int a,b;
int cnt;

bool visit[10001];
vector<int> graph[10001];
queue<int> q;

void BFS(int index){
    queue<int> q;
    q.push(index);
    visit[index] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i=0; i<graph[x].size(); i++){
            int y=graph[x][i];
            if(!visit[y]){
                q.push(y);
                cnt++;
                visit[y] = true;
            }
        }
    }
}

int main()
{
	cin >> N >> M;
    for (int i=0; i<M; i++)
    {
        cin >> a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
	BFS(1);
    cout << cnt <<endl;
    return 0;
}