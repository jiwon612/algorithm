#include<bits/stdc++.h> 
using namespace std;   

int N,M,T,D;
const int INF=1e9;
//vector<int> graph[300004];
vector<int> dist_go(630, INF);
vector<int> dist_back(630, INF);
int graph[630];
int mx=-1e9;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

void go(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //오름차순 
	dist_go[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		int now=pq.top().first;
		int idx=pq.top().second;
		pq.pop();
		if(dist_go[idx]<now) continue;	
		for(int k=0; k<4; k++){
			int nx, ny;
			nx=idx/M+dx[k];
			ny=idx%M+dy[k];
			if(nx<0 || N<=nx || ny<0 || M<=ny) continue;
			int diff=graph[nx*M+ny]-graph[idx];
			if(diff>0){ // 높은 곳으로 가는 경우 
				int mul=pow(diff,2);
				if(now+mul<dist_go[nx*M+ny] && diff<=T && now+mul<=D){ // 최단 시간 업데이트 
					dist_go[nx*M+ny]=now+mul;
					pq.push({now+mul,nx*M+ny});
//					mx=max(mx,graph[nx*M+ny]);
//					cout<<graph[nx*M+ny]<<endl;
				}
			}
			else if(now+1<dist_go[nx*M+ny] && abs(diff)<=T && now+1<=D){ // 낮은 곳으로 가는 경우 +  최단 시간 업데이트 
				dist_go[nx*M+ny]=now+1;
				pq.push({now+1,nx*M+ny});
//				mx=max(mx,graph[nx*M+ny]);
//				cout<<graph[nx*M+ny]<<endl;
			}
		}
	}
}

void back(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //오름차순 
	dist_back[start]=0;
	pq.push({0,start});
	while(!pq.empty()){
		int now=pq.top().first;
		int idx=pq.top().second;
		pq.pop();
		if(dist_back[idx]<now) continue;	
		for(int k=0; k<4; k++){
			int nx, ny;
			nx=idx/M+dx[k];
			ny=idx%M+dy[k];
			if(nx<0 || N<=nx || ny<0 || M<=ny) continue;
			int diff=graph[nx*M+ny]-graph[idx];
			if(diff<0){ // 낮은 곳으로 가는 경우 
				int mul=pow(diff,2);
				if(now+mul<dist_back[nx*M+ny] && diff<=T && now+mul<=D){ // 최단 시간 업데이트 
					dist_back[nx*M+ny]=now+mul;
					pq.push({now+mul,nx*M+ny});
//					mx=max(mx,graph[nx*M+ny]);
//					cout<<graph[nx*M+ny]<<endl;
				}
			}
			else if(now+1<dist_back[nx*M+ny] && abs(diff)<=T && now+1<=D){ // 높은 곳으로 가는 경우 +  최단 시간 업데이트 
				dist_back[nx*M+ny]=now+1;
				pq.push({now+1,nx*M+ny});
//				mx=max(mx,graph[nx*M+ny]);
//				cout<<graph[nx*M+ny]<<endl;
			}
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M>>T>>D;
	for(int i=0; i<N; i++){
		string s;
		cin>>s;
		for(int j=0; j<M; j++){
			if(0<=s[j]-'A' && s[j]-'A'<=26){
				graph[i*M+j]=s[j]-'A';
			}
			else{
				graph[i*M+j]=s[j]-'a'+26;
			}
		}
	}
	go(0);
	back(0);
//	for(int i=0; i<N; i++){
//		for(int j=0; j<M; j++){
//			cout<<dist_go[i*M+j]<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=0; i<N; i++){
//		for(int j=0; j<M; j++){
//			cout<<dist_back[i*M+j]<<' ';
//		}
//		cout<<endl;
//	}
	int ans = 0;
	for (int i = 0; i < N * M; i++) {
	    if (dist_go[i] + dist_back[i] <= D) {
	        ans = max(ans, graph[i]);
	    }
	}
	cout << ans;
}