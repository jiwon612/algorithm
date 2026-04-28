#include<iostream>

using namespace std;

int N;
int num[3001];
int cnt[3001];

int main(int argc, char** argv)
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        cnt[i] = 1; // 모든 위치의 기본 길이는 1로 초기화
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++)
        if(num[i]<num[j]){
            cnt[j]=max(cnt[j],cnt[i]+1);
        }
    }
    int ans=0;
    for(int i=0; i<N; i++){
        ans=max(ans, cnt[i]);
    }
    cout<<ans;
    return 0;
}