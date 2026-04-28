#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parent[10001];

struct edge{
    int u,v,weight;
};

bool cmp(const edge& a, const edge& b){
    return a.weight < b.weight;
}

int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}

void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    cin>>V>>E;
    vector<edge> v;
    for(int i=0; i<E; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=1; i<=V; i++){
        parent[i]=i;
    }
    long long mst_weight=0;
    int edge_count=0;
    for(int i=0; i<E; i++){
        if(edge_count==V-1) break;
        int u_root=findParent(v[i].u);
        int v_root=findParent(v[i].v);
        if(u_root != v_root){
            unionParent(v[i].u, v[i].v);
            mst_weight+=v[i].weight;
            edge_count++;
        }
    }
    cout<<mst_weight;
    return 0;
}