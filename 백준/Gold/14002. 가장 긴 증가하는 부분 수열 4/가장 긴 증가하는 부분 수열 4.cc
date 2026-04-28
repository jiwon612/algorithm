#include<bits/stdc++.h>
using namespace std;

int MAX=1;
vector<int> res;

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
			if (a[j]<a[i] && cnt[i]<cnt[j]+1){
				cnt[i]=cnt[j]+1;
				if(cnt[i]>MAX){
					MAX=cnt[i];
				}
			}
		}
	}
	int temp=MAX;
	for (int i=N-1; i>=0; i--){
		if(cnt[i]==temp){
			res.push_back(a[i]);
			temp--;
		}	
	}
	cout<<MAX<<'\n';
	for(int i=res.size()-1; i>=0; i--){
		cout<<res[i]<<' ';
	}
}
