#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

vector<int> v;
int n,x,cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	cin>>x;
	sort(v.begin(), v.end());
	int a=0;
	int b=n-1;
	while(a<b){
		if(v[a]+v[b]==x) {
			cnt++;
			b--;
		}
		else if(v[a]+v[b]>x) {
			b--;
		}
		else{
			a++;
		}
	}
	cout<<cnt;
}
