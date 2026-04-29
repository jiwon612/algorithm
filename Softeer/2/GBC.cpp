#include<iostream>
#include<vector>

using namespace std;

int N,M;
int len[600];
vector<pair<int,int>> v;
int start=1;
int ans;

int main(int argc, char** argv)
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        for(int j=start; j<start+a; j++){
            len[j]=b;
        }
        start+=a;
    }
    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    start=1;
    for(int i=0; i<M; i++){
        int l=v[i].first;
        int s=v[i].second;
        for(int j=start; j<start+l; j++){
            if(s>len[j]){
                ans=max(ans,s-len[j]);
            }
        }
        start+=l;
    }
    cout<<ans;
    return 0;
}