#include<iostream>


using namespace std;

long long K,P,N;

int main(int argc, char** argv)
{
    cin>>K>>P>>N;
    long long ans=K;
    for(int i=0; i<N; i++){
        ans=(ans*P)%1000000007;
    }
    cout<<ans;
    return 0;
}