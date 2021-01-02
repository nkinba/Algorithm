#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, p;
long long Ecnt = 0;
vector<int> mulCnts;
vector<int> existNums;
vector<vector<int>> children;
vector<int> freq;

void modMulCnt(int n, bool addOrNot){
	for (int i = 1; i * i <= n; i++) {
			 if (n % i == 0) { 
			 	mulCnts[i] += ((addOrNot) ? 1 : -1);
				if (i * i < n) 
				   mulCnts[n/i] += ((addOrNot) ? 1 : -1);
			}
 	}
 	return;
}

int findDivs(int n){
	int rst = 0;
	for (int i = 1; i * i <= n; i++) {
			 if (n % i == 0) { 
			 	rst += existNums[i];
				if (i * i < n) 
				   rst += existNums[n/i];
			}
 	}
 	return rst;
}

void dfs(int n){
	int c = freq[n];
	Ecnt += mulCnts[c];
	Ecnt += findDivs(c);
	Ecnt -= existNums[c]; // 자기 자신을 findDiv에서 더했으므로 그만큼 제거 
	
	existNums[c]++;
	modMulCnt(c, true);
	
	for(int child : children[n])
	 	dfs(child);
	
	existNums[c]--;
	modMulCnt(c, false);

}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	
	freq.resize(N+1);
	children.resize(N+1);
	mulCnts.resize(100001);
	existNums.resize(100001);
	
	FOR(i, 1, N) cin >> freq[i];
	FOR(i, 2, N) {
		cin >> p;
		children[p].push_back(i);
	}

	dfs(1);
	cout << Ecnt;
	
	return 0;
}
