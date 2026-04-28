#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N,M;
int l,r;
int MIN=1e9;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	int a[M];
	for(int i=0; i<M; i++){
		cin>>a[i];
		r=max(r, a[i]);
	}
	l=1;
	while(l<=r){
		long long stu=0;
		int mid=(l+r)/2;
		for(int i=0; i<M; i++){
			stu+=a[i]/mid;
			if(a[i]%mid!=0){
				stu++;
			}
		}
		if(stu<=N){
			r=mid-1;
			MIN=min(MIN,mid);
		}
		else{
			l=mid+1;
		}
	}
	cout<<MIN;
}
