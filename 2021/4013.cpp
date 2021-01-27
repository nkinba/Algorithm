// 106572KB	348ms.. 좀 더 좋은 방식을 찾자 

#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, S, P, s, t, p;
int vCnt = 0, SCCCnt = 0;

vector<vector<int>> edges;
vector<int> cash;
vector<bool> isRstrnt; 

vector<vector<int>> SCCs;
vector<int> discoveredCnt;
vector<int> SCCNum;
vector<int> SCCCashSum;
vector<int> dpSCC;
vector<bool> isRstrntInSCC;
stack<int> dfsVstk;

void popSCC(int endV){
	SCCCnt++;
	int cashSum = 0;
	bool hasRstrnt = false;
	
	vector<int> SCC;
	
	while(true){
		int v = dfsVstk.top();
		dfsVstk.pop();
		
		if(isRstrnt[v]) 
			hasRstrnt = true;
		
		SCCNum[v] = SCCCnt;
		SCC.emplace_back(v);
		cashSum += cash[v];
		
		if(endV == v) break;
	}
	
	SCCCashSum.emplace_back(cashSum);
	SCCs.emplace_back(SCC);
	isRstrntInSCC.emplace_back(hasRstrnt);
	dpSCC.emplace_back(-1);
	
	return;
}

int dfsSCC(int v){
	int parent = discoveredCnt[v] = ++vCnt;
	dfsVstk.push(v);
	
	for(int nextV : edges[v]){
		if(discoveredCnt[nextV] == 0)
			parent = min(parent, dfsSCC(nextV));
		else if(discoveredCnt[nextV] < discoveredCnt[v] 
					&& SCCNum[nextV] == 0){
			parent = min(parent, discoveredCnt[nextV]);
		}
	}
	
	if(parent == discoveredCnt[v]){
		popSCC(v);
	}
	
	return parent;
}

void composeSCC(){
	FOR(i, 1, N){
		if(SCCNum[i] == 0)
			dfsSCC(i);
	}
	return;
}

int countMaxCash(int curSCC){
	int& rst = dpSCC[curSCC - 1];
	if(rst != -1) return rst;
	
	rst = 0;
	for( int elem : SCCs[curSCC - 1]){
		for(int nextV : edges[elem]){
			if( SCCNum[nextV] != curSCC)
				rst = max(rst, countMaxCash(SCCNum[nextV]));
		}
	}
	if(rst == 0 && !isRstrntInSCC[curSCC - 1]) rst = 0;
	else rst += SCCCashSum[curSCC - 1];
   	
	return rst;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	edges.resize(N+1);
	cash.resize(N+1);
	isRstrnt.resize(N+1);
	SCCNum.resize(N+1);
	discoveredCnt.resize(N+1);
	
	FOR(i, 1, M){
		cin >> s >> t;
		edges[s].emplace_back(t);		
	}
	FOR(i, 1, N) cin >> cash[i];
	
	cin >> S >> P;
	FOR(i, 1, P){
		cin >> p;
		isRstrnt[p] = true;
	}

	composeSCC();
	cout <<  countMaxCash(SCCNum[S]);

	return 0;
}
