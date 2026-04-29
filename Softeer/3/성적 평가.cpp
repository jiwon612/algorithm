#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
int score[3][100001]; // 입력
int cnt[3001]; // 해당 점수가 몇명인지
int total[100001]; // 최종 점수 계산을 위한 총합
int ranking[3001]; // 순위 저장 테이블

int main(int argc, char** argv)
{
    cin>>N;
    for(int i=0; i<3; i++){
        
        for(int j=0; j<N; j++){
            int a;
            cin>>a;
            score[i][j]=a;
            cnt[a]++;
            total[j]+=a;
        }
        int n=0;
        for(int j=3000; j>=0; j--){
            if(cnt[j]!=0){
                ranking[j]=n+1;
                n+=cnt[j];
            }
        }
        for(int j=0; j<N; j++){
            cout<<ranking[score[i][j]]<<' ';
        }
        cout<<'\n';
        memset(cnt, 0, sizeof(cnt));
        memset(ranking, 0, sizeof(ranking));
    }
    int n=0;
    for(int j=0; j<N; j++){
        cnt[total[j]]++;
    }
    for(int j=3000; j>=0; j--){
        if(cnt[j]!=0){
            ranking[j]=n+1;
            n+=cnt[j];
        }
    }
    for(int j=0; j<N; j++){
        cout<<ranking[total[j]]<<' ';
    }
    return 0;
}