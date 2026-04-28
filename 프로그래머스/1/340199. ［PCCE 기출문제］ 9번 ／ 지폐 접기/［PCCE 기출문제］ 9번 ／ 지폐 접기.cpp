#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int a=bill[0];
    int b=bill[1];
    int wallet_min = *min_element(wallet.begin(), wallet.end());
    int wallet_max = *max_element(wallet.begin(), wallet.end());
    while(min(a, b) > wallet_min || max(a, b) > wallet_max){
        if(a>b){
            a=a/2;
        }
        else {
            b= b/2;
        }
        // cout<<'g';
        answer++;
    }
    
    return answer;
}