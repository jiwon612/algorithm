#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int W,N;
vector<pair<int,int>> v;
int ans;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

int main(int argc, char** argv)
{
    cin>>W>>N;
    for(int i=0; i<N; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i : v){
        if(W<=0) break;
        if(i.first<W){
            W-=i.first;
            ans+=i.first*i.second;
        }
        else{
            ans+=W*i.second;
            W=0;
        }
        // cout<<W*i.second<<endl;
    }
    cout<<ans;
    return 0;
}