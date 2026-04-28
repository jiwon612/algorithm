#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int F,S,G,U,D;
int nextup, nextdown;

bool visit[1000001];
int cnt[1000001];
queue<int> q;

void BFS(int f,int s,int g,int u,int d)
{
    
	visit[s] = true;
    cnt[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        int result = (x==g);
        if (result)
        	break;
       
		q.pop();
        nextup = x + u;
        nextdown = x - d;
        if (nextup <=f && !visit[nextup])
        {
            visit[nextup] = true;
            q.push(nextup);
            cnt[nextup] = cnt[x] + 1;
        }
		if (nextdown >=1 && !visit[nextdown])
        {
            visit[nextdown] = true;
            q.push(nextdown);
            cnt[nextdown] = cnt[x] + 1;
        }
    }
}

int main()
{
    cin >>F>>S>>G>>U>>D;
    BFS(F,S,G,U,D);
    if (!visit[G])
        cout << "use the stairs" << endl;
    else
        cout << cnt[G] << endl;
    return 0;
}