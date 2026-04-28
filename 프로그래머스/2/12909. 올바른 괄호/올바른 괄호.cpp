#include <string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)  
{ 
    queue<int> q;
    bool emp = false;
    bool answer = false;
    for (int i=0; i<s.length(); i++)
    { 
        if (s[i]=='(')
        {
            q.push(1);
        }
        else if (s[i]==')')
        {
            if(!q.empty())
                q.pop();
            else
                emp = true;
        }
    }
    cout<<emp<<endl;
    if (!emp && q.empty())
        answer = true;

    return answer;
}