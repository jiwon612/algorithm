#include<bits/stdc++.h> 
using namespace std;   

int a[15];
int arr[100];

void pri(){
	for (int i=0; i<7; i++){
		cout<<a[arr[i]]<<"\n";
	}
}

void comb(int d, int n){
	if (d==7){
		int ans=0;
		for (int i=0; i<7; i++){			
			ans +=a[arr[i]];
		}
		if(ans==100){
			pri();
			exit(0);
		}
		return;
	}
	
	for (int i=n; i<=8; i++){
		arr[d]=i;
		comb(d+1, i+1);
	}
}

int main(){
	for (int i=0; i<9; i++){
		cin>>a[i];
	}
	sort(a,a+9);
	comb(0,0);
}