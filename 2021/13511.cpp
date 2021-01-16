#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

#define nodenum first
#define weight second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int N, M, q, k, u, v, w;

vector<vector<pii>> branch;

int* depth;
int** jumpTbl;
ll** weightTbl;

void memAlloc();
void setTree(int cur, int from, int lv);
void setSparseTbls();
void printPathWeight();
void printKthPathNode();

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	
	cin >> N;
	
	memAlloc();
	
	FOR(i, 1, N-1){
		cin >> u >> v >> w;
		branch[u].emplace_back(pii(v,w));
		branch[v].emplace_back(pii(u,w));
	}
	
	setTree(1, 0, 1);
	setSparseTbls();

	cin >> M;
	
	FOR(i, 1, M){
		cin >> q;
		(q == 1) ? (printPathWeight()) : (printKthPathNode());
	}
	
	delete[] jumpTbl;
	delete[] weightTbl;
	delete depth;	
	
	return 0;
}


void memAlloc(){

	branch.resize(N+1);
	depth = new int[N+1];
	
	jumpTbl = new int*[N+1];
	weightTbl = new ll*[N+1];

	FOR(i, 0, N){
		jumpTbl[i] = new int[18];
		weightTbl[i] = new ll[18];
		fill(jumpTbl[i], jumpTbl[i]+18, 0);
		fill(weightTbl[i], weightTbl[i]+18, 0);
	} 
	
	return;
}

void setTree(int cur, int from, int lv){

	depth[cur] = lv;
	vector<pii>& nearNodes = branch[cur];
	for(pii node : nearNodes){
		if(node.nodenum != from){
			jumpTbl[node.nodenum][0] = cur;
			weightTbl[node.nodenum][0] = node.weight;
			setTree(node.nodenum, cur, lv+1);
		}
	}
	
	return;
}

void setSparseTbls(){

	FOR(i, 1, 17){
		FOR(j, 1, N) {
			jumpTbl[j][i] = jumpTbl[ jumpTbl[j][i-1] ][i-1];
			weightTbl[j][i] 
				= (weightTbl[ jumpTbl[j][i-1] ][i-1] + weightTbl[j][i-1] );
		}
	}
	
	return;
}

\
void printPathWeight(){
	
	ll weightSum = 0;
	int deep, shallow, diff;
	
	cin >> u >> v;
	if(depth[u] < depth[v]) 
		swap(u, v);
	
	deep = u, shallow = v;	
	diff = (depth[deep] - depth[shallow]);
	
	for(int jump = 0; diff; jump++){
		if(diff & 1) {
			weightSum += weightTbl[deep][jump];
			deep = jumpTbl[deep][jump];
		}
		diff >>= 1;
	}
	
	if(deep == shallow) {
	 	cout <<  weightSum << '\n';
	 	return;
	}
		
	REVFOR(i, 17, 0){
		if(jumpTbl[deep][i] != jumpTbl[shallow][i]){
			weightSum += (weightTbl[deep][i] + weightTbl[shallow][i]);
			deep = jumpTbl[deep][i];
			shallow = jumpTbl[shallow][i];
		}
	}
	weightSum += (weightTbl[deep][0] + weightTbl[shallow][0]);

	cout <<  weightSum << '\n';
	return;
}

void climbUpTree(int& startNode, int diff){
	
	for(int jump = 0; diff; jump++){
		if(diff & 1) 
			startNode = jumpTbl[startNode][jump];
		diff >>= 1;
	}
	
	return;
}

void printKthPathNode(){
	
	bool noCurveInPath, isSwapped = false;
	int deep, shallow, diff, distToKth, startNode;

	int nodeCntFromDeep = 1;
	int nodeCntFromShallow = 1;
	int nodeCntInPath;
	
	cin >> u >> v >> k;
	if(depth[u] < depth[v]) {
		swap(u, v);
		isSwapped = true;
	}
	
	deep = u, shallow = v;	
	diff = (depth[deep] - depth[shallow]);

	nodeCntFromDeep += diff;	
	climbUpTree(deep, diff);
	
	if(deep == shallow) {
		if(isSwapped) k = (nodeCntFromDeep - k + 1);
		distToKth = k - 1;
		startNode = u;
	}
	else {
		REVFOR(i, 17, 0){
			if(jumpTbl[deep][i] != jumpTbl[shallow][i]){
				nodeCntFromDeep += (1 << i);
				nodeCntFromShallow += (1 << i);
				
				deep = jumpTbl[deep][i];
				shallow = jumpTbl[shallow][i];
			}
		}
		
		nodeCntInPath = (nodeCntFromDeep + nodeCntFromShallow + 1);
		if(isSwapped) k = (nodeCntInPath - k + 1);
		
		noCurveInPath = (k <= nodeCntFromDeep + 1);
			 
		if(noCurveInPath){
			distToKth = k - 1;
			startNode = u;
		}
		else {	
			distToKth = (nodeCntFromShallow - (k - 1 - nodeCntFromDeep));
			startNode = v;
		}
	}
	
	climbUpTree(startNode, distToKth);

	cout <<  startNode << '\n';
	return;
}
