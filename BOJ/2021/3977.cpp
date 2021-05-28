#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int T, N, M, f, t;
int vCnt, SCCCnt;

int* SCCnum;
int* discoveredCnt;

vector<int> SCCEntryCnt;
vector<vector<int>> edges;
vector<vector<int>> SCCs;

stack<int> dfsVStk;

void popSCC(int endV){
	++SCCCnt;
	SCCEntryCnt.emplace_back(0);

	vector<int> SCC;
	while(true){
		int v = dfsVStk.top();
		SCCnum[v] = SCCCnt;
		SCC.emplace_back(v);
		dfsVStk.pop();
		if(v == endV) 
			break;		
	}
	
	sort(SCC.begin(), SCC.end());
	SCCs.emplace_back(SCC);
	
	return;
}

int dfsSCCNodes(int v){
	dfsVStk.push(v);
	int parent = discoveredCnt[v] = vCnt++;
	
	for(int nextV : edges[v]){
		if(discoveredCnt[nextV] == -1) 	
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
	FOR(v, 0, N-1){
		if(discoveredCnt[v] == -1) 
			dfsSCCNodes(v);
	}
	return;
}

void printZeroEntrySCC(){
	int zeroEntrySCCIndex = -1;

	FOR(v, 0, N-1){
		int curSCC = SCCnum[v];
		for(int nextV : edges[v]){
			if(SCCnum[nextV] != curSCC)
				SCCEntryCnt[SCCnum[nextV]-1]++;
		}
	}
	FOR(i, 0, SCCEntryCnt.size()-1){
		if(SCCEntryCnt[i] == 0)	{
			if(zeroEntrySCCIndex != -1){
				cout << "Confused\n";
				return;
			}
			zeroEntrySCCIndex = i;
		}
	}

	for(int v : SCCs[zeroEntrySCCIndex])
		cout << v << '\n';

	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	FOR(test, 1, T){
	
		vCnt = 0;
		SCCCnt = 0;
		
		cin >> N >> M;
		
		SCCnum = new int[N];
		discoveredCnt = new int[N];
		fill(SCCnum, SCCnum+N, 0);
		fill(discoveredCnt, discoveredCnt+N, -1); 
		
		SCCs.clear();
		SCCEntryCnt.clear();
		edges.clear();
		edges.resize(N);
		
		FOR(m, 1, M){
			cin >> f >> t;
			edges[f].emplace_back(t);
		}	
		
		composeSCC();
		printZeroEntrySCC();

		delete SCCnum;
		delete discoveredCnt;
		
		cout << '\n';

	}
	
	return 0;
}
