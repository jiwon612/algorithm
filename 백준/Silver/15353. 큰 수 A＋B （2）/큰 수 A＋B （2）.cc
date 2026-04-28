#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int sum; 
string ret;

void add(string a, string b){
	while(a.size() || b.size() || sum){
		if(a.size()){
			sum+=a.back()-'0';
			a.pop_back();
		}
		if(b.size()){
			sum+=b.back()-'0';
			b.pop_back();
		}
		ret+=(sum%10)+'0';
		sum /= 10;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	string a,b;
	cin>>a>>b;
	add(a,b);
	reverse(ret.begin(), ret.end());
	cout<<ret;
}
