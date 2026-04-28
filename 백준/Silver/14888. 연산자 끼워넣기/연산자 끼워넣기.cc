#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int MAX=-1e9;
int MIN=1e9;
int op[4];
int arr[11];
vector<int> num;
int N;
int ans;

void cal(){
	ans=num[0];
	for(int i=0; i<N-1; i++){
		if(arr[i]==0){
			ans=ans+num[i+1];
		}
		else if(arr[i]==1){
			ans=ans-num[i+1];
		}
		else if(arr[i]==2){
			ans=ans*num[i+1];
		}
		else if(arr[i]==3){
			ans=ans/num[i+1];
		}
	}
	MAX=max(ans,MAX);
	MIN=min(ans,MIN);
}

void search(int depth){
	if(depth==N-1){
		cal();
		return;
	}
	for(int i=0; i<4; i++){
		if(op[i]!=0){
			arr[depth]=i;
			op[i]--;
			search(depth+1);
			op[i]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		int n;
		cin>>n;
		num.push_back(n);
	}
	for (int i=0; i<4; i++){
		cin>>op[i];
	}
	search(0);
	cout<<MAX<<'\n'<<MIN;
}
