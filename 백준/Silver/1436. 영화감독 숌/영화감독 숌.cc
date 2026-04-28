#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin>>N;
	int num=666;
	int cnt=0;
	while(true){
		if(to_string(num).find("666")!=string::npos){
			cnt++;
		}
		if(cnt==N){
			cout<<num;
			break;
		}
		num++;
	}
}
