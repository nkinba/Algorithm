// 첫번째 색을 선택하거나 / 선택하지 않거나로 고정해서 두 경우에서 
// N개중에 인접한 경우가 없도록 K개를 선택하는 가짓수를 구해서 더한다. 
// 매우 오래걸린다. 
// 17672KB	512ms TO(1초) 근접한 방식. 
 
#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define MOD 1000000003

using namespace std;

typedef long long ll;

int N, K;
ll dpFirstON[1001][1001];
ll dpFirstOFF[1001][1001];

ll withFirst(int cur, int checkSum){
	
	if(checkSum == K)
		return 1;
	
	ll& rst = dpFirstON[cur][checkSum];
	if(rst != -1) return rst;

	rst = 0;
	FOR(i, cur+2, N-1)
		rst += withFirst(i, checkSum+1);
	
	rst %= MOD;
	return rst;
}

ll withoutFirst(int cur, int checkSum){
	if(checkSum == K)
			return 1;
	
	ll& rst = dpFirstOFF[cur][checkSum];
	if(rst != -1) return rst;

	rst = 0;
	FOR(i, cur+2, N)
		rst += withoutFirst(i, checkSum+1);
		
	rst %= MOD;
	return rst;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	FOR(i,1,N){
		fill(dpFirstON[i] + 1, dpFirstON[i] + (N+1), -1);
		fill(dpFirstOFF[i] + 1, dpFirstOFF[i] + (N+1), -1);
	}
	
	ll answer = 0;
	ll wt = withFirst(1,1);
	answer += (wt % MOD);
	
	FOR(i, 2, N) {
		ll wo = withoutFirst(i,1);
		answer += wo;
		answer %= MOD;
	}
				
	cout << answer;
	return 0;
} 
