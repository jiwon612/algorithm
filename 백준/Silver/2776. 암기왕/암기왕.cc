#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		map<int, int> m;
		int N;
		cin>>N;
		for (int j=0; j<N; j++){
			int a;
			cin>>a;
			m[a]=1;
		}
		int M;
		cin>>M;
		for (int j=0; j<M; j++){
			int b;
			cin>>b;
			if(m[b]==1){
				cout<<'1'<<'\n';
			}
			else{
				cout<<'0'<<'\n';
			}
		}
	}
}
