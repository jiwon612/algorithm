#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	for (int i=0; i<T; i++){
		int num;
		cin>>num;
		int cnt=0;
		int five=5;
		int n=1;
		while (num/five){
			cnt+=num/five;
			five*=5;
		}
		
		cout<<cnt<<'\n';
	}
}
