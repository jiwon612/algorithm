#include<bits/stdc++.h> 
using namespace std;   

string s;
int arr[26];

int main(){
	cin>>s;	
	for (int i=0; i<s.size(); i++){
		int alp=s[i]-'a';
		arr[alp]++;
	}
	for (int i=0; i<26; i++){
		cout<<arr[i]<<' ';
	}
}