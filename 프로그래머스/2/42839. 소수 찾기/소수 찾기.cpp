#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

set<int> Set;
int answer;
int visit[10];

bool check(int n){
    if(n<2) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

void dfs(const string& n, string current){
    if(current!=""){
        int num=stoi(current);
        if(check(num)){
            Set.insert(num);
        }
    }
    for(int i=0; i<n.size(); i++){
        if(visit[i]) continue;
        visit[i]=true;
        dfs(n, current+n[i]);
        visit[i]=false;
    }
}

int solution(string numbers) {
    dfs(numbers, "");   
    answer=Set.size();
    return answer;
}
