#include<bits/stdc++.h> 
using namespace std;  

int N;
int f, rest, rest3,ans;
 
int main(){  
	cin>>N;
	f = N/5;
	rest=N%5;
	while (ans==0){
		if (f<0){
			ans=-1;
			break;
		}
		else if (rest%3 != 0){
				rest+=5;
				f--;
		}
		else{
			rest3=rest/3;
			ans = f+rest3;
		}
		
	}
	cout<<ans;
}