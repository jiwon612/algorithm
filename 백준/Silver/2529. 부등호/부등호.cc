#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<char> v;
vector<string> ans;
int k;
int visit[10];

bool check(char x, char y, char op){
	if(x<y && op=='<') return true;
	if(x>y && op=='>') return true;
	return false;
}

void go(int idx, string num){
	if(idx==k+1){
		ans.push_back(num);
		return;
	}
	for (int i=0; i<=9; i++){
		if (visit[i]) continue;
		if(idx==0 || check(num[idx-1], i+'0', v[idx-1])){
			visit[i]=1;
			go(idx+1, num+to_string(i));
			visit[i]=0;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>k;
	string num(k+1, '0');
	for (int i=0; i<k; i++){
		char s;
		cin>>s;
		v.push_back(s);
	}
	go(0,"");
	sort(ans.begin(),ans.end());
	cout<<*(ans.end()-1)<<'\n'<<*ans.begin();
}
