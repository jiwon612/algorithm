#include<bits/stdc++.h>
using namespace std;

map<int, int> m, t;
vector<pair<int, int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int win[101];
	cin>>N;
	for (int i=0; i<N; i++){
		int a;
		cin>>a;
		m[a]++;
		string s;
		cin>>s;
		int time=60*stoi(s.substr(0,2))+stoi(s.substr(3,5));
//		cout<<time;
		if (m[1]>m[2]){
			v.push_back({1,time});
		}
		else if (m[1]<m[2]){
			v.push_back({2,time});
		}
		else{
			v.push_back({0,time});
		}
	}
	for (int i=0; i<v.size(); i++){
		if (i==v.size()-1){
//			cout<<48*60-v[i].second; 
			t[v[i].first]+=(48*60-v[i].second);
			break;
		}
		t[v[i].first]+=(v[i+1].second-v[i].second);
	}
	cout<<setfill('0') << setw(2)<<t[1]/60<<':'<<setfill('0') << setw(2)<<t[1]%60<<'\n';
	cout<<setfill('0') << setw(2)<<t[2]/60<<':'<<setfill('0') << setw(2)<<t[2]%60;
//	for (auto i : t){
//		cout<<i.second<<' ';
//	}
}
