#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M,D;
int AA[300];
int result, MAX;
int Arr[3];
int gindex[3];
int TMP[300];
bool visit[300];
int cnt;
int x,y;
int nx, ny;

void step() // 위에서 아래로 덮어쓰기 -> 아래에서 위부터 확인
{
    for (int i=N-2; i>=0; i--)
    {
        for (int j=0; j<M; j++)
        {
            TMP[M * (i+1) + j] = TMP[M*i+j];
        }
    }
    for (int i=0; i<M; i++)
    	TMP[i]=0;
}

void BFS(int index)
{
    int sx = index / M;
    int sy = index % M;

    queue<int> qx, qy, qd; // x좌표, y좌표, 거리
    bool local_visit[300] = {false};

    qx.push(sx);
    qy.push(sy);
    qd.push(0);
    local_visit[sx * M + sy] = true;

    int dx[3] = {0, -1, 0};  // 왼, 위, 오
    int dy[3] = {-1, 0, 1};

    while (!qx.empty())
    {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        int dist = qd.front(); qd.pop();

        if (dist >= D) continue; // 거리 = 0 ~ D-1까지 실행

        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + 1;

            if (0 <= nx && nx < N && 0 <= ny && ny < M && !local_visit[nx * M + ny])
            {
		            // 궁수가 탐색했나
                local_visit[nx * M + ny] = true;
	
                if (TMP[nx * M + ny] == 1)
                {
		                // 이미 죽인애가 아니면 true
                    visit[nx * M + ny] = true;
                    return;
                }

                qx.push(nx);
                qy.push(ny);
                qd.push(ndist);
            }
        }
    }
}


void attack(int array[3], int AA[200]) // 여기에 [3] 범위
{
    cnt = 0; //  공격 시뮬레이션마다 초기화해야 함
		
		// 맵 복사
    for (int i = 0; i < N*M; i++)
        TMP[i] = AA[i];
		
		// 궁수 인덱스
    for(int i=0; i<3; i++)
        gindex[i] = N*M - 1 + array[i];

    for(int turn = 0; turn < N; turn++)  // 한 턴씩 시뮬레이션 진행
    {
        for (int i = 0; i < 3; i++)
            BFS(gindex[i]);

				// 한번에 죽이기
        for (int i = 0; i < N*M; i++)
        {
            if (visit[i])
            {
                cnt++;
                TMP[i] = 0;
                visit[i] = false;
            }
        }
        // 아래로 내려감
        step();
    }
}

   
void combination(int depth, int next)
{
    if(depth == 3)
    {
        attack(Arr, AA); // 여기는 그냥 배열 이름
        if (cnt > MAX)
            MAX = cnt;
        return;
    }
    for (int i=next; i<=M; i++)
    {
        Arr[depth] = i;
        combination(depth+1, i+1);
    }
}
    
int main()
{
    cin>>N>>M>>D;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin>>AA[i*M+j];
        }
    }
	combination(0, 1);
    cout<<MAX<<endl;
}