#include <bits/stdc++.h>

using namespace std;

int N, M, f, t;
int vCnt = 0, SCCCnt = 0;
vector<vector<int>> edge;
vector<vector<int>> SCCs;
vector<int> discoveredCnt;
vector<int> SCCNum;
stack<int> dfsVstk;

void popSCC(int endV){
	SCCCnt++;
	vector<int> SCC;
	
	while(true){
		int v = dfsVstk.top();
		dfsVstk.pop();
		SCCNum[v] = SCCCnt;
		
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

inline notVal(int x){
	return ((x <= N) ? x + N : x - N);
}

inline falseVal(int x){
	return -x + N;
}

inline getRealVal(int x){
	if(x > 0) return x;
	else return falseVal(x);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	edge.resize(2*N+1);
	discoveredCnt.resize(2*N+1);
	SCCNum.resize(2*N+1);
	
	for(int i=0; i<M; i++){
		cin >> f >> t;
//		cout << "pre : "<< f << " " << t <<endl;
		f = getRealVal(f);
		t = getRealVal(t);
//		cout << "real : " << f << " " << t <<endl;
		edge[notVal(f)].push_back(t);
		edge[notVal(t)].push_back(f);
	}

//	for(int i=1; i<=2*N; i++){
//		cout << i << ":\n";
//		for(int v : edge[i])
//			cout<< v << " ";
//		cout<<endl;
//	}

	composeSCC();
	cout << hasAnswer();

	return 0;
}
