#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,r,c,d;
int Arr[100][100];
int clean;
bool visit[100][100];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void BFS(int a, int b, int dir)
{
    int nx = a;
    int ny = b;
    while(true)
    {
        bool front = false;
        // 현재 칸이 빈칸인 경우
        if (Arr[nx][ny] == 0)
        {
            Arr[nx][ny]=2; // 청소하면 2
            clean++;
        }
        for(int i=0; i<4; i++)
        {
            // 반시계 회전
            dir = (dir+3)%4;
            int fx = nx + dx[dir]; 
            int fy = ny + dy[dir];
            // 앞이 빈칸인경우
            if(fx>=0 && fx<N && fy>=0 && fy<M && Arr[fx][fy] == 0)
            {
                // 한칸 전진
                nx = fx;
                ny = fy;
                front = true;
                break;
            }
        }
        if (front) continue;
        // 빈칸 없는 경우
        int bx = nx + dx[(dir+2)%4];
        int by = ny + dy[(dir+2)%4];
        // 벽없으면 후진
        if(bx>=0 && bx<N && by>=0 && by<M && Arr[bx][by] != 1)
        {
            nx =bx;
            ny =by;      // 맞을 때만 업데이트
            continue;
        }
        else
            break;
    }
}

int main()
{
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>Arr[i][j];
        }
    }
    BFS(r,c,d);
    cout<<clean<<endl;
    return 0;
}