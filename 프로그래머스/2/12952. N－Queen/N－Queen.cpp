#include <string>
#include <vector>

using namespace std;

int answer;
bool visit[11];
bool visit1[25];
bool visit2[25];
 
void dfs(int n, int N){
    if(n==N){
        answer++;
        return;
    }
    for(int i=1; i<=N; i++){
        if(visit[i] || visit1[n+i] || visit2[n-i+N]) continue;
        visit[i]=true;
        visit1[n+i]=true; // / 대각선 합은 다 같음
        visit2[n-i+N]=true; // \ 대각선
        dfs(n+1,N);
        visit[i]=false;
        visit1[n+i]=false;
        visit2[n-i+N]=false;
    }
}

int solution(int n) {
    dfs(0,n);
    return answer;
}