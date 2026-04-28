#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<string> v;

bool cmp(string a, string b){
	if(a.size()==b.size()) return a<b;
	return a.size()<b.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	for (int i=0; i<N; i++){
		string new_s="";
		string s;
		cin>>s;
		for (int j=0; j<s.size()+1; j++){
			if(0<=s[j]-'0' && s[j]-'0'<=9){
				new_s+=s[j];
//				cout<<new_s<<' ';
			}
			else if(new_s!=""){
//				cout<<stoi(new_s)<<' ';
				while(new_s.size()>1 && new_s[0]=='0'){
					new_s.erase(0,1);
				}
				v.push_back(new_s);
				new_s="";
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		cout<<i<<'\n';
	}
}
