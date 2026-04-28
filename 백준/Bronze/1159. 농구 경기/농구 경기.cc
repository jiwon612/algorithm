#include <bits/stdc++.h>
using namespace std;

int N;
string s, ans;
int arr[26];

int main(){
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>s;
		arr[s[0]-'a']++;
	}
	for (int i=0; i<26; i++){
		if (arr[i]>=5){
			ans+=i+97;
		}
	}
	if (ans!="") cout<<ans;
	else cout<<"PREDAJA";
}