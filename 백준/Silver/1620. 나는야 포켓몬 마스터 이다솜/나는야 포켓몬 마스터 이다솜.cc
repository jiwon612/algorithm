#include <bits/stdc++.h>
using namespace std;

vector<string> v;
map<string,int> name;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int N,M;
	cin>>N>>M;
	for (int i=0; i<N; i++){
		string s;
		cin>>s;
		v.push_back(s);
		name[s]=i+1;
	}
	for (int i=0; i<M; i++){
		string in;
		cin>>in;
		if (isdigit(in[0])){
			cout<<v[stoi(in)-1]<<'\n';
		}
		else{
			cout<<name[in]<<'\n';
		}
	}
}