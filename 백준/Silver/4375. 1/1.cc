#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	while (cin>>n){ // 3
		int cnt=1;
		int i=1;
		if (n==1){
			cout<<1<<'\n';
			continue;
		}
		while (i!=0){
			i = (i*10+1)%n;
			cnt++;
//			cout<<i%n;
		}
		cout<<cnt<<'\n';	
	}
}