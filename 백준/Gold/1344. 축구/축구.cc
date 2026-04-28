#include <bits/stdc++.h> 
using namespace std; 

double A,B;
vector<int> v ={2,3,5,7,11,13,17};
double dp[20][20][20]; //a 득점 횟수, b 득점 횟수, 현재 게임 

double go(int a, int b, int now){
	if(now==18){
	   auto it_a = find(v.begin(), v.end(), a);
	   auto it_b = find(v.begin(), v.end(), b);   
	   // 둘 중 하나가 소수면 반영 
	   if(it_a!=v.end() || it_b!=v.end()) return 1;
	   return 0; 
	}
   double &res=dp[a][b][now];
   if(res>=0) return res;
   
   res=0;
   double pA=A/100;
   double pB=B/100;
   
   // A득점, B득점
   res+=pA*pB*go(a+1,b+1,now+1);
   // A득점, B무득점
    res += pA * (1 - pB) * go(a + 1, b, now + 1);
    // A무득점, B득점
    res += (1 - pA) * pB * go(a, b + 1, now + 1);
    // 둘 다 무득점
    res += (1 - pA) * (1 - pB) * go(a, b, now + 1);
    
    return res;
}

int main() { 
   ios::sync_with_stdio(false); 
   cin.tie(NULL); cout.tie(NULL);
   cin>>A>>B; 
//   cout<<pow((A/100),2);
	for(int i=0; i<20; i++)
	        for(int j=0; j<20; j++)
	            for(int k=0; k<20; k++)
	            	dp[i][j][k]=-1;
   cout<<fixed<<setprecision(16)<<go(0,0,0);
}