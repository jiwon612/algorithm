#include <bits/stdc++.h>
using namespace std;

string s,s1;

int main(){
	cin>>s;
	s1=s;
	reverse(s1.begin(), s1.end());
	if (s==s1) cout<<'1';
	else cout<<'0';
}