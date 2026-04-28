#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int cnt;
bool set[21];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int M;
	cin>>M;
	for(int i=0; i<M; i++){
		string s;
		cin>>s;
		int a;
		if(s=="add"){
			cin>>a;
			set[a]=true;
			continue;
		}
		if(s=="remove"){
			cin>>a;
			set[a]=false;
			continue;
		}
		if(s=="check"){
			cin>>a;
			if(set[a]){
				cout<<1<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
			continue;
		}
		if(s=="toggle"){
			cin>>a;
			set[a]=set[a]^1;
			continue;
		}
		if(s=="all"){
			for(int j=0; j<21; j++){
				set[j]=true;
			}
			continue;
		}
		if(s=="empty"){
			for(int j=0; j<21; j++){
				set[j]=false;
			}
			continue;
		}
	}
}
