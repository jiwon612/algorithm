#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int N,M;
int a,b;
int cnt;
int home[1000];
char AA[30][30];

bool visit[1000];
vector<int> graph[1000];
queue<int> q;

void BFS()
{
	for(int i=0; i<1000; i++)
    {
        if (!visit[i] && AA[i/N][i%N] == '1')
        {
            cnt++;
            visit[i] = true;
            q.push(i);
            
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                home[cnt]++;
                for (int j=0; j<graph[x].size(); j++)
                {
                    int y = graph[x][j];
                    if(!visit[y])
                    {
                        visit[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    }
    
}

int main()
{
	cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> AA[i];
    }
    for (int j=0; j<N; j++)
    {
        for (int k=0; k<N; k++)
        {
            if (j<N-1 && AA[j][k] == '1' && AA[j+1][k] == '1')
            {
                graph[N*j+k].push_back(N*(j+1)+k);
                graph[N*(j+1)+k].push_back(N*j+k);
            }
            if (k<N-1 && AA[j][k] == '1' && AA[j][k+1] == '1')
            {
                graph[N*j+k].push_back(N*j+(k+1));
                graph[N*j+(k+1)].push_back(N*j+k);
            }
        }
    }
	BFS();
    cout << cnt << endl;
    sort(home+1, home+cnt+1);
    for (int a=0; a<cnt; a++)
    {
        cout << home[a+1] << endl;
    }
    return 0;
}