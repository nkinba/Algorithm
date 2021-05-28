#include <bits/stdc++.h>

using namespace std;

int N,M,n,m,ans = 1;
bool visited[101] = {false, };
vector<int> net[101]; 
priority_queue<int> pq;

int bfs(){
	pq.push(1);
	visited[1] = true;
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		vector<int>& linked = net[cur];	
		for(size_t i=0; i< linked.size(); i++){
			int next = linked[i];
			if(visited[next] == false){
				visited[next] = true;
				pq.push(next);
				ans++;
			}
		}
	}
	
	return ans-1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(size_t i=0; i<M; i++){
		cin >> 	n >> m;
		net[n].emplace_back(m);
		net[m].emplace_back(n);
	}
		
	cout << bfs();
	
	return 0;
}
