#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char AA[50];
vector <int>num;
vector<char> op;
int MAX = -1e9;

int cal(int a, int b, char op)
{
    if (op == '+')
        return a+b;
    if (op == '-')
        return a-b;
    if (op == '*')
        return a*b;
}   
    
void DFS(int idx, int current)
{
    // 결과 출력
    if (idx>= op.size())
    {
        MAX =max(MAX, current);
        return;
    }
    
    // 괄호 없음
    int result = cal(current, num[idx+1], op[idx]);
    DFS(idx+1, result);
    
    // 괄호 있음
    int x = cal(num[idx+1], num[idx+2], op[idx+1]);
    int y = cal(current, x, op[idx]);
    if (idx + 1<op.size())
    {
        // 괄호 다음은 무조건 없는걸로
        DFS(idx+2,y);
    }
}

int main()
{
    cin>>N>>AA;
    
    for (int i=0; i<N; i++)
    {
        if (i%2==0) 
            num.push_back(AA[i]-'0');
        else
            op.push_back(AA[i]);
    }
    DFS(0, num[0]);
    cout<<MAX<<endl;
    return 0;
}