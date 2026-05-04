#include<iostream>


using namespace std;

int a[10];
int as, ds;

int main(int argc, char** argv)
{
    for(int i=0; i<8; i++){
        cin>>a[i];
    }
    for(int i=1; i<8; i++){
        if(a[i]-a[i-1]==1){
            as++;
        }
        else if(a[i-1]-a[i]==1){
            ds++;
        }
    }
    if(a[0]==1 && as==7){
        cout<<"ascending";
    }
    else if(a[0]==8 && ds==7){
        cout<<"descending";
    }
    else{
        cout<<"mixed";
    }
    return 0;
}