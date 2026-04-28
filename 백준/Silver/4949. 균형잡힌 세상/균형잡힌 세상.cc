#include<bits/stdc++.h>
using namespace std;

vector<int> v;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	while(true){
		string s;
		getline(cin,s);
		if(s=="."){
			break;
		}
		stack<int> st;
		for(int j=0; j<s.size(); j++){
			if (s[j]=='('){
				st.push(s[j]);
			}
			if(s[j]==')'){
				if (!st.empty() && st.top()=='('){
					st.pop();
				}
				else{
					st.push(s[j]);
				}
			}
			if (s[j]=='['){
				st.push(s[j]);
			}
			if(s[j]==']'){
				if (!st.empty() && st.top()=='['){
					st.pop();
				}
				else{
					st.push(s[j]);
				}
			}
		}
		if(st.empty()){
			cout<<"yes"<<'\n';
		}
		else{
			cout<<"no"<<'\n';
		}
	}
}
