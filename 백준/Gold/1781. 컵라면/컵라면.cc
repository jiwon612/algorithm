#include <bits/stdc++.h> 
using namespace std; 

int N,ans;
vector<pair<int,int>> v;
priority_queue<int, vector<int>,greater<int>> cup;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		int d,c;
		cin>>d>>c;
		v.push_back({d,c});
	}
	sort(v.begin(), v.end());
//	for(auto i:v){
//		cout<<i.first<<' '<<i.second<<endl;
//	}
	for(int i=0; i<v.size(); i++){
		cup.push(v[i].second);
		if(cup.size()>v[i].first){
//			cout<<cup.top()<<' ';
			cup.pop();
		}
	}
	while(!cup.empty()){
//		cout<<cup.top()<<' ';
		ans+=cup.top();
		cup.pop();
	}
	cout<<ans;
}
