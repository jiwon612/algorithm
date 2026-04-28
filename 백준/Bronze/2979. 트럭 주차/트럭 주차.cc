#include <bits/stdc++.h>
using namespace std;

int A,B,C;
int arr[101];
int ans;

int main(){
	cin>>A>>B>>C;
	for (int i=0; i<3; i++){
		int a,b;
		cin>>a>>b;
		for(int i=a; i<b; i++){
			arr[i]++;
		}
	}
	for (int i : arr){
		if (i==1) ans+=A*i;
		else if (i==2) ans+=B*i;
		else if (i==3) ans+=C*i;
	}
	cout<<ans;
}