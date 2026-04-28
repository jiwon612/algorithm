#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

long long X,Y,mid;
long long MIN=1e9;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//	cout<<47*100/53;

	cin>>X>>Y;
	long long Z=Y*100/X;
	long long newZ=Z;
	if((Y+1000000000)*100/(X+1000000000)==Z){
		cout<<"-1";
		exit(0);
	}
	long long start=1;
	long long end=1000000000;
	while(start<=end){
		mid =(start+end)/2;
		newZ=(Y+mid)*100/(X+mid);
		if(newZ!=Z){
			end=mid-1;
			MIN=min(MIN,mid);
		}
		else{
			start=mid+1;
		}
	}
	cout<<MIN;
}
