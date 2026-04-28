#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	int start=v[0].first;
	int end=start+v[0].second;
	for(int i=1; i<v.size(); i++){
		if(end<v[i].first){
			end=v[i].first+v[i].second;
		}
		else{
			end+=v[i].second;
		}
	}
	cout<<end;
}
