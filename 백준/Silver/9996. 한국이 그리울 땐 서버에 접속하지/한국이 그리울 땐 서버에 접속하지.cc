#include <bits/stdc++.h>
using namespace std;



int main(){
	int N;
	cin>>N;
	string s;
	cin>>s;
	auto it = s.find('*');
	string s1=s.substr(0,it);
	string s2=s.substr(it+1);
	string st;
	for (int i=0; i<N; i++){
		cin>>st;
		if (s1.length()+s2.length()>st.length()){
			cout<<"NE"<<'\n';
			continue;
		}
		auto it1 = st.find(s1);
		string st2 = st.substr(st.length()-s2.length());
		if (it1==0 && s2 == st2){
			cout<<"DA"<<'\n';
		}
		else {
			cout<<"NE"<<'\n';
		}
	}
}