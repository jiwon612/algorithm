#include<iostream>
#include<cmath>

using namespace std;

int N;

int main(int argc, char** argv)
{
    cin>>N;
    int ans=pow((pow(2,N)+1),2);
    cout<<ans;
    return 0;
}