#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll c){
	if(b==0) return 1;
	if(b==1) return a%c;
	ll half=power(a,b/2,c);
	half = (half*half)%c;
	if (b%2) half=(half*a)%c;
	return half;
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll A,B,C;
	cin>>A>>B>>C;
	cout<<power(A,B,C);
}