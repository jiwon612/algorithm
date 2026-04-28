#include<bits/stdc++.h>
using namespace std;

int MAX=0;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	int cnt[N];
	fill(cnt,cnt+N, 1);
	int a[N];
	for(int i=0; i<N; i++){
		cin>>a[i];
	}
	for(int i=1; i<N; i++){
		for (int j=0; j<=i-1; j++){
			if (a[j]<a[i]){
				if(cnt[i]<cnt[j]+1){
					cnt[i]=cnt[j]+1;
				}
				
			}
		}
	}
	for(int i=0; i<N; i++){
		MAX=max(MAX,cnt[i]);
	}
	cout<<MAX;
}
