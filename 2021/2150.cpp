#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int V, E, f, t, vCnt = 0;

bool* isInSCC = nullptr;
int* discoveredCnt = nullptr;

vector<pii> edges;
vector<vector<int>> adj;
vector<vector<int>> SCCs;

stack<int> dfsVStk;

void stkClear(int endV){
	int v;
	vector<int> SCC;
	
	while(true){
		v = dfsVStk.top();
		isInSCC[v] = true;
		SCC.emplace_back(v);
		dfsVStk.pop();
		
		if(v == endV) break;
	}
	
	sort(SCC.begin(), SCC.end());
	SCCs.emplace_back(SCC);
	
	return;
}

int dfsSCCTarjan(int v){
	int parent = discoveredCnt[v] = vCnt++;
	dfsVStk.push(v);
	
	for(int nextV : adj[v]){
		if(discoveredCnt[nextV] == -1)
			parent = min(parent, dfsSCCTarjan(nextV));
		else if(discoveredCnt[nextV] < discoveredCnt[v]
					&& isInSCC[nextV] == false)
			parent = min(parent, discoveredCnt[nextV]);
	}
	
	if(parent == discoveredCnt[v]) 
		stkClear(v);
		
	return parent;
}

void tarjanSCC(){

	for(int i=0; i<E; i++){
		cin >> f >> t;
		adj[f].emplace_back(t);
	}
	
	for(int i=1; i<=V; i++){
		if(isInSCC[i] == false)
			dfsSCCTarjan(i);
	}
	return;
}

void dfsReverseKosaraju(int v, vector<int>& SCC){
	discoveredCnt[v] = 1;
	SCC.emplace_back(v);
	for(int i=1; i<=V; i++){
		if(adj[v][i] == 1 && discoveredCnt[i] == -1)
			dfsReverseKosaraju(i, SCC);
	}
	return;
}

void dfsKosaraju(int v){
	discoveredCnt[v] = 1;
	for(int i=1; i<=V; i++){
		if(adj[v][i] == 1 && discoveredCnt[i] == -1)
			dfsKosaraju(i);
	}
	dfsVStk.push(v);
	return;
}

void reverseEdge(){
	for(pii edge : edges){
		if(!adj[edge.first][edge.second] || !adj[edge.second][edge.first] ){
			adj[edge.first][edge.second] = 0;
			adj[edge.second][edge.first] = 1;
		}
	}
	return;
}

void kosarajuSCC(){
	
	for(vector<int>& v : adj)
		v.resize(V+1);

	for(int i=0; i<E; i++){
		cin >> f >> t;
		adj[f][t] = 1;
		edges.emplace_back(pii(f,t));
	}

	for(int i=1; i<=V; i++){
		if(discoveredCnt[i] == -1) 
			dfsKosaraju(i);
	}

	fill(discoveredCnt+1, discoveredCnt+V+1, -1);
	reverseEdge();
	
	while(!dfsVStk.empty()){
		int v = dfsVStk.top();
		dfsVStk.pop();
		if(discoveredCnt[v] == -1){
			vector<int> SCC;
			dfsReverseKosaraju(v, SCC);
			sort(SCC.begin(), SCC.end());
			SCCs.emplace_back(SCC);
		}
	}
	return;
}

bool comp(const vector<int>& v1, const vector<int>& v2){
	return v1[0] < v2[0];
}

void printAnswer(){
	cout << SCCs.size() << '\n';
	for(vector<int>& SCC : SCCs){
		for(int elem : SCC)
			cout << elem << " ";
		cout << "-1\n";
	}
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E;
	adj.resize(V+1);
	isInSCC = new bool[V+1];
	discoveredCnt = new int[V+1];
	
	fill(isInSCC+1, isInSCC+V+1, false);
	fill(discoveredCnt+1, discoveredCnt+V+1, -1);

	tarjanSCC();
//	kosarajuSCC();
	sort(SCCs.begin(), SCCs.end(), comp);
	
	printAnswer();

	delete isInSCC;
	delete discoveredCnt;

	return 0;
}
