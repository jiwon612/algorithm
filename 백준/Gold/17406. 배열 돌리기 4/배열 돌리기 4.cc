#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N,M,K;
int arr[51][51];
int orig[51][51];
int temp[51][51];
int r,c,s;
int MIN=1e9;

struct query {
	int r,c,s;
	bool operator<(const query& other) const {
        if (r != other.r) return r < other.r;
        if (c != other.c) return c < other.c;
        return s < other.s;
    }
};
vector<query> v;

void rot(int r, int c, int s){
	memcpy(temp, arr, sizeof(arr));
	for(int i=1; i<=s; i++){
		/*
		행 r+i, 열 c-i ~ c+i 
		행 r-i, 열 c-i ~ c+i 
		행 r-i ~ r+i, 열 c+i
		행 r-i ~ r+i, 열 c-i
		*/
		for(int a=c-i; a<c+i; a++){
			arr[r-i][a+1]=temp[r-i][a];
			arr[r+i][a]=temp[r+i][a+1];
		}
		for(int b=r-i; b<r+i; b++){
			arr[b][c-i]=temp[b+1][c-i];
			arr[b+1][c+i]=temp[b][c+i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M>>K;
	for(int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			cin>>orig[i][j];
		}
	}
	for (int i=1; i<=K; i++){
		cin>>r>>c>>s;
		v.push_back({r,c,s});
	}
	sort(v.begin(), v.end());
	do{
		memcpy(arr, orig, sizeof(arr));
		for(int j=0; j<v.size(); j++){
			rot(v[j].r, v[j].c, v[j].s);
		}
		for(int j=1; j<=N; j++){
			int ans=0;
			for(int k=1; k<=M; k++){
	//			cout<<arr[j][k]<<' ';
				ans+=arr[j][k];
			}
			MIN=min(MIN, ans);
	//		cout<<'\n';
		}
	}while (next_permutation(v.begin(),v.end()));

	cout<<MIN;
}
