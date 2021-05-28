#include <bits/stdc++.h>

using namespace std;

int T, N, M, f, t, vCnt, SCCcnt;

vector<int> SCCEntryCnt;
vector<vector<int>> edges;
stack<int> dfsVStk;

int* SCCnum;
int* discoveredCnt;

void popSCC(int endV){
	
	SCCcnt++;
	SCCEntryCnt.emplace_back(0);
	
	while(true){
		int v = dfsVStk.top();
		SCCnum[v] = SCCcnt;
		dfsVStk.pop();
		
		if(v == endV) break;
	}

	return;

}

int dfsSCCNodes(int v){
	
	int parent = discoveredCnt[v] = ++vCnt;
	dfsVStk.push(v);
	
	for(int nextV : edges[v]){
		if(discoveredCnt[nextV] == 0)
			parent = min(parent, dfsSCCNodes(nextV));
		else if(discoveredCnt[nextV] < discoveredCnt[v] 
								&& SCCnum[nextV] == 0){
			parent = min(parent, discoveredCnt[nextV]);			
		}
	}
	
	if(parent == discoveredCnt[v])
		popSCC(v);
	
	return parent;
}

void composeSCC(){
	
	for(int i=1; i<=N; i++){
		if(SCCnum[i] == 0) 
			dfsSCCNodes(i);
	}

	return;
}

int countZeroEntrySCCs(){
	int cnt = 0;
	for(int v=1; v<=N; v++){
		int curSCC = SCCnum[v];
		for(int nextV : edges[v]){
			if(curSCC != SCCnum[nextV])
				SCCEntryCnt[SCCnum[nextV]-1]++;
		}
	}
	for(int num : SCCEntryCnt){
		if(num == 0) cnt++;
	}

	return cnt;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for(int test=0; test<T; test++){
		SCCEntryCnt.clear();
		edges.clear();
		
		cin >> N >> M;
		
		edges.resize(N+1);
		SCCnum = new int[N+1];
		discoveredCnt = new int[N+1];
		fill(SCCnum+1, SCCnum+N+1, 0);
		fill(discoveredCnt+1, discoveredCnt+N+1, 0); 
		
		vCnt = 0;
		SCCcnt = 0;
		
		for(int i=0; i<M; i++){
			cin >> f >> t;
			edges[f].emplace_back(t);	
		}	
			
		composeSCC();	
		cout << countZeroEntrySCCs() << '\n';
		
		delete SCCnum;
		delete discoveredCnt;
	}

	return 0;
}
