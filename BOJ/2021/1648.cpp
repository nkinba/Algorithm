#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef pair<int,int> pii;

int mod = 9901;
int N, M;
int dp[15][15];

void cntDp(int n, int m){
//	dp[n][m] = dp[n-2][m] * dp[2][m-1]
//			 + dp[n-1][m] * dp[1][m-2];

	dp[n][m] = dp[n-2][m] + dp[n][m-1] - dp[n-2][m-1]
			 + dp[n-1][m] + dp[n][m-2] - dp[n-1][m-2];
//			 + dp[n-2][m-2];
	return;
}
		
int main(void){
	cin >> N >> M;
	
	int l = max(M, N);

	dp[0][0] = 1;
	FOR(i, 1, l){
		dp[0][i] = dp[i][0] = 1;
		dp[1][i] = dp[i][1] = ((i%2) ? 0 : 1);
	}
	FOR(i, 2, N){
		FOR(j, 2, M){
			cntDp(i,j);
			cout << i << "," << j << " : " << dp[i][j]%mod<<'\n';
		}
	}	
	
	FOR(i,0 ,N){
		FOR(j,0, M)
			cout << dp[i][j] << " ";
		cout <<endl; 
	}
	

	return 0;
}
