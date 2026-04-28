#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin>>s;
	vector<int> a(s.size());
	for (int i=0; i<s.size(); i++){
		a[i]=s[i]-'0';
	}
	sort(a.begin(),a.end(),greater<int>());
	for (int i=0; i<s.size(); i++){
		cout<<a[i];
	}
}