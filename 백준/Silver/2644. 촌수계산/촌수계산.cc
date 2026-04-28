#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,a,b,m,x,y;
bool visit[200];
int cnt[200];
vector<int> graph[200];
queue<int> q;

void BFS(int index)
{
    visit[index]=true;
    q.push(index);
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for (int i=0; i<graph[x].size(); i++)
        {
            int y= graph[x][i];
            if(!visit[y])
            {
                visit[y] = true;
                q.push(y);
                cnt[y]= cnt[x]+1;
            }
        }
    }
}

int main()
{
    cin >> n >>a>>b>>m;
    for (int i=0; i<m; i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS(a);
	if (cnt[b] == 0)
        cout<< -1 <<endl;
    else
    	cout << cnt[b] <<endl;	
    
    return 0;
}