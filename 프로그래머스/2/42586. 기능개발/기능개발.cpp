#include <string>
#include <vector>
#include <queue>

using namespace std;

int a;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i< progresses.size(); i++){
        if((100-progresses[i])%speeds[i]==0){
            a=(100-progresses[i])/speeds[i];
        }
        else a=(100-progresses[i])/speeds[i]+1;
        q.push(a);
    }
    int cnt=1;
    //q 맨앞 변수에 넣고 pop
    int f=q.front();
    q.pop();
    //q가 없을때까지
    while(!q.empty()){
        //뒤에꺼보다 작으면 배포
        if(f<q.front()){
            answer.push_back(cnt);
            cnt=1;
            f=q.front();
            q.pop();
        }
        //크거나 같으면 기다리기, cnt++
        else {
            cnt++;
            q.pop();
        }
    }
    answer.push_back(cnt);
    return answer;
}