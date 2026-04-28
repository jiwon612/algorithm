#include <bits/stdc++.h>
using namespace std;

int cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int N;
	cin>>N;
	for(int i=0; i<N; i++){ // 3
		string s;
		cin>>s;
		stack<char> q;
		for(char c : s){
			if (!q.empty() && q.top()==c){ // 알파벳이 top에 있으면 꺼내기 
				q.pop(); 
			}
			else {
				q.push(c);
			}
		}
//		for (int j=0; j<q.size(); j++){
//			cout<<q.top();
//			q.pop();
//		}
		// 마지막에 stack에 남은게 없으면 좋은 단어 
		if(q.empty()){
			cnt++;
		}
//		else { 
//			while(!q.empty()){
//				q.pop();
//			}
//		}
	}
	cout<<cnt;
}