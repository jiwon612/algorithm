#include <bits/stdc++.h> 
using namespace std; 

int cnt[10001]; 

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a, a+n);
	fill(cnt, cnt+10001, 1e9);
	for(int i=0; i<n; i++){
		for(int j=1; j<=k; j++){
			if(j%a[i]==0 && j/a[i]<cnt[j]){
				cnt[j]=j/a[i];
			}
			else{
				if(j-a[i]>=0 && cnt[j-a[i]]+1<cnt[j]){
					cnt[j]=cnt[j-a[i]]+1;
				}
			}
		}
	}
	if(cnt[k]==1e9){
		cout<<"-1";
	}
	else{
		cout<<cnt[k];
	}
//	for(int i=0; i<20; i++){
//		cout<<cnt[i]<<' ';
//	}
}