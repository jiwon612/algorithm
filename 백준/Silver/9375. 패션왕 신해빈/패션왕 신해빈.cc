#include <bits/stdc++.h>
using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		map<string, int> m;
		int a;
		cin>>a;
		for(int j=0; j<a; j++){
			string s1, s2;
			cin>>s1>>s2;
			m[s2]++;
		}
		int ans=1;
		for (auto k : m){
//			cout<<k.second;
			ans *= (k.second+1);
		}
		cout<<ans-1<<'\n';
	}
}