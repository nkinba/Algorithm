#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

using namespace std;

int N, M, a, b;
vector<vector<int>> branch;
int* depth;
int** sparseTable;

void setTree(int cur, int from, int lv){
	depth[cur] = lv;
	vector<int>& nearNodes = branch[cur];
	for(int near : nearNodes){
		if(near != from){
			sparseTable[near][0] = cur;
			setTree(near, cur, lv+1);
		}
	}
	return;
}

void setSparseTable(){
	FOR(i, 1, 17){
		FOR(j, 1, N) 
			sparseTable[j][i] = sparseTable[ sparseTable[j][i-1] ][i-1];
	}
	return;
}

int findLCA(int deep, int shallow){
	int jump;
	int diff = depth[deep] - depth[shallow];
	
	for(jump = 0; diff; jump++){
		if(diff & 1) deep = sparseTable[deep][jump];
		diff >>= 1;
	}
	
	if(deep == shallow) return deep;
	
	REVFOR(i, 17, 0){
		if(sparseTable[deep][i] != sparseTable[shallow][i]){
			deep = sparseTable[deep][i];
			shallow = sparseTable[shallow][i];
		}
	}
	
	return sparseTable[deep][0];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	branch.resize(N+1);
	depth = new int[N+1];
	sparseTable = new int*[N+1];
	FOR(i, 0, N){
		sparseTable[i] = new int[18];
		fill(sparseTable[i], sparseTable[i]+18, 0);
	} 
	
	FOR(i, 1, N-1){
		cin >> a >> b;
		branch[a].emplace_back(b);
		branch[b].emplace_back(a);
	}
	
	setTree(1, 0, 1);
	setSparseTable();
	
	cin >> M;
	
	FOR(i, 1, M){
		cin >> a >> b;
		if(depth[a] < depth[b]) 
			swap(a, b);
		cout << findLCA(a, b) << '\n';
	}
	
	delete[] sparseTable;
	delete depth;

	return 0;
}
