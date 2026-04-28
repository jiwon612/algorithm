#include <bits/stdc++.h> 
using namespace std; 

stack<char> st;
int idx;
vector<char> v;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	string s, a, ss;
	cin>>s>>a;
	for(int i=0; i<s.size(); i++){
		st.push(s[i]);
		if(st.size()>=a.size() && st.top()==a[a.size()-1]){
			for(auto i:a){
				ss+=st.top();
				st.pop();
			}
			reverse(ss.begin(), ss.end());
			if(ss!=a){
				for(auto i:ss){
					st.push(i);
				}
			}
			ss="";
		}
	}
	if(st.empty()){
		cout<<"FRULA";
	}
	else{
		while(st.size()){
			v.push_back(st.top());
			st.pop();
		}
		for(int i=v.size()-1; i>=0; i--){
			cout<<v[i];
		}
	}
}