#include<iostream>
#include<iomanip>

using namespace std;

int N,K;
double sum[1000001];

int main(int argc, char** argv)
{
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        double d;
        cin>>d;
        sum[i]=sum[i-1]+d;
    }
    for(int i=0; i<K; i++){
        int a,b;
        cin>>a>>b;
        double s=0;
        s=sum[b]-sum[a-1];
        double n=b-a+1;
        cout<<fixed<<setprecision(2)<<s/n<<endl;
    }
    return 0;
}