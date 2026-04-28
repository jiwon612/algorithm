#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	double ans=1;
	double max=0;
	for (int i=0; i<N; i++){
		double a;
		cin>>a;
		ans*=a;
//		cout<<ans<<' ';
		if(max<ans){
			max=ans;
		}
		if(ans<1){
			ans=1;
		}
	}
	cout<<fixed<<setprecision(3)<<max;
}
