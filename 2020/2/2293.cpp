// 굳이 2차원 배열을 쓸 필요가 없다. 
// 행 길이가 1이상 차이나면 이전 행은 필요가 없을 뿐더러
// 현재 동전 가치 합에 대한 경우는  현재 동전을 쓰지 않았을 때의 경우와
// 썼을 때 현재 동전 가치 합이 되는 경우만 사용하므로
// 1차원 배열만 사용해도 현재 인덱스 이전의 값들만 사용하기 때문. 

#include <iostream>
#include <algorithm>

using namespace std;

int coins[100] = {0,};
int cases[10001] = {0,};
int n,N,K,inp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> K;
	N = 0;
	for(int i=0; i<n; i++)	{
		cin >> inp;
		if(inp <= 10000)
			coins[N++] = inp;
	}
	
	sort(coins, coins+N);
	
	for(auto coinIdx=0; coinIdx < N; coinIdx++){
		for(auto coinSum = coins[coinIdx]; coinSum <= K; coinSum++ )
			cases[coinSum] = (
								 ( (coinIdx > 0) ? cases[coinSum] : 0) 
							   + ( (coinSum - coins[coinIdx] >= 0) 
							 		 ? (cases[coinSum - coins[coinIdx]] )
							 		 :  0 )
							   + ( (coinSum == coins[coinIdx])
							         ? 1
									 : 0 )
							);
	}

	cout << cases[K];
	
	return 0;
}
