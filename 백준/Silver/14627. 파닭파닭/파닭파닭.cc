#include<bits/stdc++.h>
using namespace std;

long long MAX=-1e9;
long long MIN=1e9;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	long long p, c;
	cin>>p>>c;
	long long len[p];
	long long l=1;
	long long r=0;
	long long sum=0;
	for (int i=0; i<p; i++){
		cin>>len[i];
		sum+=len[i];
		if(r<len[i]){
			r=len[i];
		}
//		cout<<sum<<' ';
	}
	long long res;
	while(l<=r){
		long long n=0;
		long long mid=(l+r)/2;
		long long ans=0;
//		cout<<mid<<' ';
		for (int i=0; i<p; i++){
			n+=len[i]/mid;
		}
//		cout<<n<<' ';
		if(c<=n){ //가능 
			l=mid+1;
			if(MAX<mid){
				MAX=mid;
			}
		}
		else{
			r=mid-1;
		}
	}
//	cout<<MAX;
//	cout<<MIN;
	res=sum-c*MAX;
	cout<<res;
}
