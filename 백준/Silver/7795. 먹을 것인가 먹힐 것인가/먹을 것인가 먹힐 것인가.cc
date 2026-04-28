#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int a[20001];
int b[20001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N, M;
		cin>>N>>M;
		for(int j=0; j<N; j++){
			cin>>a[j];
		}
		for(int j=0; j<M; j++){
			cin>>b[j];
		}
		sort(a,a+N);
		sort(b,b+M);
//		for(int k:b){
//			cout<<k<<' ';
//		}
		int cnt=0;
		for(int j=0; j<N; j++){
			int pointer=0;
			while(a[j]>b[pointer] && pointer<M){
				pointer++;
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
}
