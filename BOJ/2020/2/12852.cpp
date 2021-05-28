#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

int N;
int dp[1000001] = {0,};
int pre[1000001] = {0,};

void btmUp(){
	for(int i=2; i<=N; i++){
		int& rst = dp[i];
		rst = MAX;
		if(i%3 == 0 && rst > dp[i/3] + 1){
			rst = dp[i/3] + 1;
			pre[i] = i/3;
		}
		if(i%2 == 0 && rst > dp[i/2] + 1){
			rst = dp[i/2] + 1;
			pre[i] = i/2;
		}
		if(rst > dp[i-1] + 1){
			rst = dp[i-1] + 1;
			pre[i] = i-1;
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	btmUp();
	cout << dp[N] <<'\n';
	int start = N;
	while(start != 0){
		cout << start << " ";
		start = pre[start];
	}
		
}
