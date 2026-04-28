#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int K,n;
vector<int> v;
vector<int> ans[11];

void go(int start, int end, int depth){
	if(depth==K) return;
	int mid = (start+end)/2;
	ans[depth].push_back(v[mid]);
	go(start, mid-1, depth+1);
	go(mid+1, end, depth+1);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>K;
	n=(int)pow(2,K)-1;
//	cout<<n;
	for (int i=0; i<n; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	go(0, n, 0);
	for (int i=0; i<K; i++){
		for(int j:ans[i]){
			cout<<j<<' ';
		}
		cout<<'\n';
	}
}
