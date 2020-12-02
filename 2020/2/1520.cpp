#include <iostream>

using namespace std;

int dp[500][500];
int map[500][500];
int M,N;
int mdir[4] = {-1,0,1,0};
int ndir[4] = {0,-1,0,1};

bool inRange(int m, int n){
	return (0<=m && m<M && 0<=n && n<N);
}

//void print(){
//	for(int i=0; i<M; i++){
//		for(int j=0; j<N; j++)
//			cout << dp[i][j] << " ";
//		cout <<endl;
//	}
//	cout <<endl;
//}

int dfs(int m, int n){
	if(m==M-1 && n==N-1) return 1;
	
	dp[m][n] = 0;
	
	for(int i=0; i<4; i++){
		int nm = m + mdir[i];
		int nn = n + ndir[i];
		if(inRange(nm,nn) && (map[nm][nn] < map[m][n]) && dp[nm][nn])
			dp[m][n] += ((dp[nm][nn]==-1) ? dfs(nm,nn) : dp[nm][nn]);
	}
		
//	print();	
		
	return dp[m][n];
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> M >> N;
	for(int i=0; i<M; i++){
		fill_n(dp[i], N, -1);
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	}
	dp[M-1][N-1] = 1;
	cout << dfs(0,0);
	return 0;
}
