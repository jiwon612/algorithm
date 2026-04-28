#include<bits/stdc++.h>
using namespace std;

vector<int> v;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for (int i=0; i<T; i++){
		stack<int> st;
		string s;
		cin>>s;
		for(int j=0; j<s.size(); j++){
			if (s[j]=='('){
				st.push(s[j]);
			}
			else{
				if (!st.empty() && st.top()=='('){
					st.pop();
				}
				else{
					st.push(s[j]);
				}
			}
		}
		if(st.empty()){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
}
