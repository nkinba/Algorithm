// 왜 2차원 배열로 하면 틀릴까? 반례가 뭘까..? 
// 메모이제이션, dp 배열을 채우는 부분에서 오류가 있었다. 
// (반례) 정답 484 출력 488 
// 19 20169
// 240 2560 434 6 31 577 500 2715 2916 952 2490 258 1983 1576 3460 933 1660 2804 2584
// 82 77 81 0 36 6 53 78 49 82 82 33 66 8 60 0 98 91 93 

// 1차원으로 해도 시간은 0ms로 같았지만 메모리가 절반 이상 감소 

#include <bits/stdc++.h>

using namespace std;

int N, M, maxCost=0, ans;
int mem[101];
int cost[101];
int dp[101][10001]={{0,},};

void print(){
	for(int i=1; i<=N; i++){
		for(int j=0; j<=maxCost; j++)
			cout << dp[i][j] << " ";
		cout <<endl;
	}
	cout << endl;	
}

void f(){
	
	for(int i=2; i<=N; i++){
		// 이전 mem의 합들과 비교하기 위한 초기화 부분 추가
		dp[i][cost[i]] = mem[i]; 
		
		for(int j = 0; j <= maxCost; j++){
//			잘못된 부분 
//       : '새로 메모리를 더하는 경우 (+mem[i]) 는 dp[i-1][j-cost[i]]가
//			0이 아닐 경우에만 적용해야 해당 조건을 빠뜨리고
// 		    모든 경우에 대해 적용하면 존재하지 않는 경우까지
// 			dp 배열을 채우게 된다. 
//			dp[i][j] = max(dp[i-1][j], dp[i-1][j - cost[i]] + mem[i]);		
				
//		   수정한 부분, 삼항 연산자의 전자는 이전 mem합을 사용, 후자는 현재 mem 사용 
			dp[i][j] = max (
						((dp[i-1][j-cost[i]] != 0) ? (dp[i-1][j-cost[i]] + mem[i]) : dp[i][j])
						,dp[i-1][j]
						 );

			print();
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		cin >> mem[i];
	for(int i=1; i<=N; i++){
		cin >> cost[i];
		maxCost += cost[i];
	}
	
	dp[1][cost[1]] = mem[1];
	f();
		
	for(ans=0; ans<=maxCost && dp[N][ans] < M; ans++);
	cout << ans;
	
	return 0;
}
