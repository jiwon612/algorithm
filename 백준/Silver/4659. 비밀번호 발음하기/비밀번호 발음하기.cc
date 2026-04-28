#include <bits/stdc++.h>
using namespace std;

bool aeiou(char c){
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	string list="aeiou";
	while(cin>>s && s != "end"){
		int mo_cnt=0;
		int ja_cnt=0;
		bool accept=false;
		for (int i=0; i<s.size(); i++){
			if(aeiou(s[i])){
				accept=true;
				mo_cnt++;
				ja_cnt=0;
			}
			else{
				ja_cnt++;
				mo_cnt=0;
			}
			if(mo_cnt>=3 || ja_cnt>=3){
				accept=false;
				break;
			}		
		}

		for (int i=0; i<s.size(); i++){
			if(i>=1 && s[i-1]==s[i]){
				accept=false;
				if (s[i]=='e'||s[i]=='o'){
					accept=true;
				}
			}
		}
		if(accept){
			cout<<"<"<<s<<"> is acceptable."<<'\n';
		}
		else
			cout<<"<"<<s<<"> is not acceptable."<<'\n';
	}
	
}
