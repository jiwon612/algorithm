#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	string s;
	cin>>s;
	while(s!=""){
		if((s[0]=='p'&&s[1]=='i') || (s[0]=='k'&&s[1]=='a')){
			s.erase(0,2);
		}
		else if(s[0]=='c'&&s[1]=='h'&&s[2]=='u'){
			s.erase(0,3);
		}
		else{
			cout<<"NO";
			break;
		}
	}
	if(s==""){
		cout<<"YES";
	}
}
