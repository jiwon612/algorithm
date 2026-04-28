#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int app[25];
int N,M,J;
int cnt;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M>>J;
	for(int i=0; i<J; i++){
		cin>>app[i];
	}
	int front=M;
	int end=front-M+1;
	for(int i=0; i<J; i++){
		int current=app[i];
		while(end>current || current>front){
			if(front<current){
				front++;
				end++;
			}
			else if(current<end){
				front--;
				end--;
			}
			cnt++;
		}
	}
	cout<<cnt;
}
