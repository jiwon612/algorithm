#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int a[21][21];
int N;
bool arr[21];

int MIN=1e9;

void cal(){
	int start=0, link=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i] && arr[j]){
				start+=a[i][j];
			}
			else if(!arr[i] && !arr[j]){
				link+=a[i][j];
			}
		}
	}
	int diff=abs(start-link);
	MIN=min(MIN,diff);
}

void comb(int idx, int depth){
	if(depth==N/2){
		cal();
		return;
	}
	for(int i=idx; i<N; i++){
		arr[i]=true;
		comb(i+1, depth+1);
		arr[i]=false;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>a[i][j];
		}
	}
	comb(0,0);
	cout<<MIN;
}
