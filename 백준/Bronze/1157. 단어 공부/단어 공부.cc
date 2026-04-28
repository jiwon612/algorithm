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
int index;
vector<int> v(10000);

int main(){
    getline(cin, t);
    for (int i=0; i<t.size(); i++){
        index = int(toupper(t[i]));
    	v[index]++;
    }
	int max=*max_element(v.begin(), v.end());
	int cnt=count(v.begin(), v.end(), max);
    
    if(cnt>1){
        cout<<'?';
    }
    else {
        index=max_element(v.begin(), v.end())-v.begin();
        cout<<char(index);
    }
}