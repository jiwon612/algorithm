#include <bits/stdc++.h>
using namespace std;

int a,b;
map<int, int> m;
int cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>a>>b;
	for (int i=0; i<a; i++){
		int x;
		cin>>x;
		m[x]++;
	}
	for (int i=0; i<b; i++){
		int y;
		cin>>y;
		m[y]++;
	}
	for (auto it:m){
		if(it.second==1)cnt++;
	}
	cout<<cnt;
}
