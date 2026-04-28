#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, K;
int next1, next2, next3;

bool visit[200000];
int cnt[200000];
queue<int> q;

void BFS(int n, int k)
{
	visit[n] = true;
    cnt[n]=0;
    q.push(n);
    while(!q.empty())
    {
        int x = q.front();
        int result = (x==k);
        q.pop();
        next1 = x + 1;
        next2 = x - 1;
        next3 = 2 * x;
        if (result)
            break;
        
        if (next1 <= 100001 && !visit[next1])
        {
            visit[next1] = true;
            q.push(next1);
            cnt[next1]=cnt[x]+1;
        }
        if (0 <=next2 && !visit[next2])
        {
            visit[next2] = true;
            q.push(next2);
            cnt[next2]=cnt[x]+1;
        }
        if (next3 <= 100000 && !visit[next3])
        {
            visit[next3] = true;
            q.push(next3);
            cnt[next3]=cnt[x]+1;
        }

        
    }
}

int main()
{

	cin >> N >> K;
    if (N==K)
    {
        cout << 0 << endl;
        return 0;
    }
    BFS(N, K);
    cout << cnt[K] << endl;
    return 0;
}