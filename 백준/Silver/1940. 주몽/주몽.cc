#include <bits/stdc++.h>
using namespace std;

int N,M;
int a[15004];
int arr[10];
int res;

void comb(int depth, int next){
	if(depth==2){
		if( a[arr[0]]+a[arr[1]]==M) res++;
		return;
	}
	for(int i=next; i<N; i++){
		arr[depth]=i;
		comb(depth+1, i+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cin>>N>>M;
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	comb(0,0);
	cout<<res;
}