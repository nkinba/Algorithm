#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define MAX 1000000
#define RED 0 
#define BLUE 1 
#define GREEN 2
 
using namespace std;

int N;
int cost[1000][3];
int dp[1000][7] = {{0,},};  // dp[i][c] -> i번째 집에서 c라는 색을 칠했을 때 비용 최소값  
// 1<<color(0~2)  001 010 100 
int painted[1000]={0,};
int findMin(int house, int curColor){

	if(house == N-1) {
		int lastRst = MAX;
		FOR(color, RED, GREEN)
			if(painted[0] != (1<<color) && painted[house-1] != (1<<color)) 
				lastRst = min(lastRst, cost[house][color]); 
		return lastRst;
	}
	
	int& rst = dp[house][painted[house]];
	if(rst) 
		return rst;
	
	rst = MAX;
	FOR(color, RED, GREEN){
		if(painted[house] != (1<<color)){
			painted[house+1] = (1<<color);
			rst = min(rst, cost[house][curColor] + findMin(house+1, color));
			painted[house+1] = 0;
		}
	}
	return rst;
}

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	FOR(i,0,N)  
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	int answer = MAX;
	FOR(c,0,3){
		painted[0] = (1<<c); 
		answer = min(answer, findMin(0,c));
		FOR(n, 0, N)
			fill(dp[n], dp[n]+7, 0);
	}
	cout <<answer <<endl;
	return 0;
}
