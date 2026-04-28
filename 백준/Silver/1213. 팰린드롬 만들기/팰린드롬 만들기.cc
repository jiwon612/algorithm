#include <bits/stdc++.h>
using namespace std;

int cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	string s, ans;
	cin>>s;
	map<char, int> m;
	int leng=s.size();
	for (int i=0; i<leng; i++){
		m[s[i]]++;
	}
	char mid=0;
	for (auto i : m){
		if (i.second%2){
			mid=i.first;
			cnt++;
		}
		for (int j=0; j<i.second/2; j++){
			ans+=i.first;
		}
	}
	if (cnt>1)
		cout<<"I'm Sorry Hansoo";
	else{
		string s2 = ans;
        reverse(s2.begin(), s2.end());
        if (mid != 0) ans += mid; 
        ans += s2;
        cout << ans;
	}
}