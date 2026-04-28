#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int sum;
int MAX=-1e9;
deque<int> q;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		sum+=a;
		MAX=max(MAX, sum);
		if(sum<0) sum=0;
	}
	cout<<MAX;
}
