#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define RFOR(i,e,b) for(int i=e; i>=b; i--)

using namespace std;

int T, N, p, c, u, v, root;
vector<int> leaves[10005];
int dp[10005][14];
int depth[10005];

void setDepth(int n, int d, int p){
	depth[n] = d;
	for(auto i : leaves[n]){
		if(i != p){
			dp[i][0] = n;
			setDepth(i, d+1, n);
		}
	}
	return;
}

void setParents(){
	FOR(j, 1, 13){
		FOR(i, 1, N)
			dp[i][j] = dp[ dp[i][j-1] ][j-1];
	}
	return;
}

int findLCA(int a, int b){
	if(depth[a] < depth[b]) swap(a, b);
	int d = depth[a] - depth[b];
	int i;
	for(i=0; d; i++){
		if(d & 1) a = dp[a][i];
		d >>= 1;
	}
	if(a == b) return a;
	
	int restD = 13-i;
	RFOR(i, restD, 0){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	FOR(t, 1 ,T){
		cin >> N;
		
		FOR(i, 1, N){
			fill(dp[i]+1, dp[i]+N+1, 0);
			fill(leaves[i].begin(), leaves[i].end(), 0);
		}
		fill(depth+1, depth+N+1, 0);
		
		int pCnt[10005] = {0,};
		
		FOR(i, 1, N-1){
			cin >> p >> c;
			leaves[p].push_back(c);
			pCnt[c]++;
		}
		FOR(i, 1, N-1){
			if(pCnt[i]==0) root = i; 
		}
		
		setDepth(root, 1, 0);
		setParents();
		
		cin >> u >> v;
		cout << findLCA(u, v) << '\n';
	}

	return 0;
} 
