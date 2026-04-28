#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N,M,sum;
int MIN=1e9;

int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   cin>>N>>M;
   int a[N];
   int l=0;
   for (int i=0; i<N; i++){
      cin>>a[i];
      l=max(l,a[i]);
      sum+=a[i];
   }
   int r=sum;
   while(l<=r){
   	  int day=1;
      int mid=(l+r)/2;
      int current=mid;
      for (int i=0; i<N; i++){
         if(a[i]<=current){
            current-=a[i];
         }
         else{
            current=mid-a[i];
            day++;
         }
      }
      if(day<=M){
         r=mid-1;
         MIN=min(MIN,mid);
      }
      else{
         l=mid+1;
      }
   }
   cout<<MIN;
}
