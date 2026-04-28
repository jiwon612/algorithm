#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    answer.push_back(arr[0]);
        for (int i=1; i<arr.size(); i++){
            bool flag;
            for (int j=0; j<answer.size(); j++){
                if(arr[i]==answer[j]){
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
            }
            if(!flag && answer.size()<k){
                answer.push_back(arr[i]);
            }
        }
    
    while(answer.size()<k){
        answer.push_back(-1);
    }

    return answer;
}