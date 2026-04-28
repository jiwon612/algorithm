#include <bits/stdc++.h>
using namespace std;


long long sum, m;
int N,K;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>N>>K;
	for (int i=0; i<N; i++){
		int a;
		cin>>a;
		v.push_back(a);	
	}
	for (int i=0; i<K; i++){
		sum+=v[i];
		m=sum;
	}
	for (int i=K; i<N; i++){
		sum+=v[i];
		sum-=v[i-K];
		if (sum>m){
			m=sum;
		}
	}
	cout<<m;
}