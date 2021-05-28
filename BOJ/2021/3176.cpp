#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

#define nodenum first
#define weight second

#define MIN first
#define MAX second

using namespace std;

typedef pair<int,int> pii;

int N, K, a, b, w;
vector<vector<pii>> branch;
int* depth;
int** jumpTbl;
int** minWTbl;
int** maxWTbl;

void memAlloc();
void setTree(int cur, int from, int lv);
void setSparseTables();
pii renewMinMax(const pii preVal, const int deep, const int shallow, const int jump);
pii findMinMaxByLCA(int deep, int shallow);
void printSparseTables();

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	memAlloc();
	
	FOR(i, 1, N-1){
		cin >> a >> b >> w;
		branch[a].emplace_back(pii(b,w));
		branch[b].emplace_back(pii(a,w));
	}
	
	setTree(1, 0, 1);
	setSparseTables();
	
	cin >> K;
	
	FOR(i, 1, K){
		cin >> a >> b;
		if(depth[a] < depth[b]) 
			swap(a, b);
		pii result = findMinMaxByLCA(a, b);
		cout << result.first << " " << result.second << '\n';
	}
	
//	printSparseTables();

	delete[] jumpTbl;
	delete[] minWTbl;
	delete[] maxWTbl;
	delete depth;

	return 0;
}

void memAlloc(){

	branch.resize(N+1);
	depth = new int[N+1];
	
	jumpTbl = new int*[N+1];
	minWTbl = new int*[N+1];
	maxWTbl = new int*[N+1];
	FOR(i, 0, N){
		jumpTbl[i] = new int[18];
		minWTbl[i] = new int[18];
		maxWTbl[i] = new int[18];

		fill(jumpTbl[i], jumpTbl[i]+18, 0);
		fill(minWTbl[i], minWTbl[i]+18, 0);
		fill(maxWTbl[i], maxWTbl[i]+18, 0);
	} 
	
	return;
}

void setTree(int cur, int from, int lv){

	depth[cur] = lv;
	vector<pii>& nearNodes = branch[cur];
	for(pii near : nearNodes){
		if(near.nodenum != from){
			jumpTbl[near.nodenum][0] = cur;
			minWTbl[near.nodenum][0] = near.weight;
			maxWTbl[near.nodenum][0] = near.weight;
			setTree(near.nodenum, cur, lv+1);
		}
	}
	return;
}

void setSparseTables(){

	FOR(i, 1, 17){
		FOR(j, 1, N) {
			jumpTbl[j][i] 
			= jumpTbl[ jumpTbl[j][i-1] ][i-1];

			minWTbl[j][i] 
			= min(minWTbl[ jumpTbl[j][i-1] ][i-1],
				  minWTbl[j][i-1]);
			
			maxWTbl[j][i] 
			= max(maxWTbl[ jumpTbl[j][i-1] ][i-1],
				  maxWTbl[j][i-1]);
		}
	}
	return;
}

pii renewMinMax(const pii preVal, const int deep, const int shallow, const int jump){
	return pii(
			min(min(preVal.MIN, minWTbl[deep][jump]), minWTbl[shallow][jump]),
		    max(max(preVal.MAX, maxWTbl[deep][jump]), maxWTbl[shallow][jump])
			);
}
		
pii findMinMaxByLCA(int deep, int shallow){

	pii result = pii(1000000, 1);
	int diff = depth[deep] - depth[shallow];

	for(int jump = 0; diff; jump++){
		if(diff & 1) {
			result.MIN = min(result.MIN, minWTbl[deep][jump]);
			result.MAX = max(result.MAX, maxWTbl[deep][jump]);
			deep = jumpTbl[deep][jump];
		}
		diff >>= 1;
	}
	
	if(deep == shallow)
		return result;
	
	REVFOR(i, 17, 0){
		if(jumpTbl[deep][i] != jumpTbl[shallow][i]){
			result = renewMinMax(result, deep, shallow, i);	
			
			deep = jumpTbl[deep][i];
			shallow = jumpTbl[shallow][i];
		}
	}
	
	result = renewMinMax(result, deep, shallow, 0);	
			
	return result;
}

void printSparseTables(){

	cout << "jumpTbl\n";
	FOR(i, 1, N){
		FOR(j, 0, 17)
			cout << jumpTbl[i][j] << " ";
		cout <<'\n';
	}
	cout << "minWTbl\n";
	FOR(i, 1, N){
		FOR(j, 0, 17)
			cout << minWTbl[i][j] << " ";
		cout <<'\n';
	}
	cout << "maxWTbl\n";
	FOR(i, 1, N){
		FOR(j, 0, 17)
			cout << maxWTbl[i][j] << " ";
		cout <<'\n';
	}
	return;
}
