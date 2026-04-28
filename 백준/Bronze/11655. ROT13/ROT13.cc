#include <bits/stdc++.h>
using namespace std;

int N;
string s, ans;
int arr[26];

int main(){
	getline(cin, s); // 공백을 포함하여 엔터를 치기 전까지의 모든 문자를 읽음
	for (int i=0; i<s.size(); i++){
//		cout<<s[i]-'a'<<' ';
//		cout<<s[i]-'A'<<endl;
		if ((0<=s[i]-'a'&&s[i]-'a'<13) || (0<=s[i]-'A'&&s[i]-'A'<13)){
			ans+=s[i]+13;
		}
		else if ((13<=s[i]-'a'&&s[i]-'a'<26) || (13<=s[i]-'A'&&s[i]-'A'<26)){
			ans+=s[i]-13;
//			cout<<s[i]-13<<' ';
		}
		else ans+=s[i];
	}
	cout<<ans;
}