#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int arr[100][100];
int N;

void act(int n, int x, int y){ //4
	int current = arr[x][y];
	bool same=true;
	for(int i=x; i<x+n; i++){
		for(int j=y; j<y+n; j++){
			if(arr[i][j]!=current){
				same=false;
				break;
			}
		}
		if(!same) break;
	}
	if(same){
		cout<<current;
	}
	else{
		cout<<"(";
		int nextN=n/2;
		act(nextN,x,y);
		act(nextN,x,y+nextN);
		act(nextN,x+nextN,y);
		act(nextN,x+nextN,y+nextN);
		cout<<")";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		string s;
		cin>>s;
		for (int j=0; j<N; j++){
			arr[i][j]=s[j]-'0';
		}
	}
	act(N,0,0);
}