#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;
int main() {
    int b,c, ans;
	string s;
    stack<char> num;
    queue<int> realnum;
    queue<char> op;
    cin >> s;
    for (int i=0; i<=s.length(); i++){
        if ('0' <= s[i] && s[i] <= '9') {
            num.push(s[i]);
        }
        else{
            op.push(s[i]);
            int cnt=1;
            int rn=0;
            while(!num.empty()){
                char c=num.top();
                num.pop();
                rn+=(c-'0')*cnt;
                cnt*=10;
            }
            realnum.push(rn);
        }
    }
    ans=realnum.front();
    realnum.pop();
    bool flag=false;
    while(!op.empty()){
		char oper=op.front();
        op.pop();
        int nxt=realnum.front();
        realnum.pop();
        if (oper=='-'){
            flag=true;
        }
        
        if(flag){
            ans-=nxt;
        }
        else{
            ans+=nxt;
        }
    }
        cout<<ans;
}