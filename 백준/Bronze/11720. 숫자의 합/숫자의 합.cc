#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <array>

using namespace std;

int N;
string t;
int ans;

int main(){
    string s;
    getline(cin, s);
    N = stoi(s);
    getline(cin, t);
    for (int i=0; i<N; i++){
    
        ans += (t[i] - '0');
    }
    cout<<ans;
}