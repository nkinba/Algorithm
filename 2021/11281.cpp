#include <bits/stdc++.h>

using namespace std;

int N, M, f, t;
int vCnt = 0, SCCCnt = 0;
vector<vector<int>> edge;
vector<vector<int>> SCCs;
vector<int> discoveredCnt;
vector<int> SCCNum;
vector<int> trueOrFalse;
stack<int> dfsVstk;

inline int notVal(int x){
	return ((x <= N) ? (x + N) : (x - N));
}

inline int falseVal(int x){
	return -x + N;
}

inline int getRealVal(int x){
	if(x > 0) return x;
	else return falseVal(x);
}

void popSCC(int endV){
	SCCCnt++;
	vector<int> SCC;
	
	while(true){
		int v = dfsVstk.top();
		dfsVstk.pop();
		SCCNum[v] = SCCCnt;
		SCC.emplace_back(v);
		if(endV == v) break;
	}
	SCCs.push_back(SCC);
	return;
}


int dfsSCC(int v){
	int parent = discoveredCnt[v] = ++vCnt;
	dfsVstk.push(v);
	
	for(int nextV : edge[v]){
		if(discoveredCnt[nextV] == 0) 
			parent = min(parent, dfsSCC(nextV));
		else if(SCCNum[nextV] == 0)
			parent = min(parent, discoveredCnt[nextV]);
	}

	if(parent == discoveredCnt[v]) 
		popSCC(v);

	return parent;
}

void composeSCC(){
	for(int i = 1; i <= 2*N; i++){
		if(SCCNum[i] == 0)
			dfsSCC(i);
	}
	return;
}

int hasAnswer(){
	int ans = 1;
	for(int i=1; i<=N; i++){
		if(SCCNum[i] == SCCNum[i+N]) {
			ans = 0;
			break;
		}
	}
	return ans;
}

void printAnswer(){
	for(int i = SCCs.size()-1; i>=0; i--){
		for(int v : SCCs[i]){
			if(trueOrFalse[v] == -1){
				trueOrFalse[v] = 0;
				trueOrFalse[notVal(v)] = 1;
			}
		}
	}
	for(int i=1; i<=N; i++)
		cout << ((trueOrFalse[i] == 0) ? 0 : 1) << ' ';
		
	return;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	edge.resize(2*N+1);
	discoveredCnt.resize(2*N+1);
	SCCNum.resize(2*N+1);
	trueOrFalse.resize(2*N+1);
	fill(trueOrFalse.begin(), trueOrFalse.end(), -1);
	
	for(int i=0; i<M; i++){
		cin >> f >> t;
		f = getRealVal(f);
		t = getRealVal(t);
		edge[notVal(f)].push_back(t);
		edge[notVal(t)].push_back(f);
	}

	composeSCC();

	if(hasAnswer()){
		cout << "1\n";
		printAnswer();
	} 
	else 
		cout << '0';
	
	return 0;
}
