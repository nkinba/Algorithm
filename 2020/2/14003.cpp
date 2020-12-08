// 이분 탐색(log N) 을각 위치에서 수행

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

#define len first
#define pre second

using namespace std;
typedef pair<int,int> pii;

int N, MAXIDX;
int* ub;
int A[1000001];
pii dp[1000001];
stack<int> stk;

void findLIS(){
	FOR(i, 2, N){
		ub = upper_bound(A+1, A+i, A[i],
							 [](const int& a, const int& b){
			              return a < b;
          				});
		cout << ub << " ->" << *ub << " vs " << i <<endl;
		if(A[MAXIDX] < A[i]){ // 1 2 3 4 3 2 5
			dp[i].len = dp[MAXIDX].len + 1;
			dp[i].pre = MAXIDX;
			MAXIDX = i;
		}
		else {
			if(ub == A+i) dp[i].len = 1;
			else {
				dp[i].len = dp[(int)(ub - (A+1))].len + 1;
				dp[i].pre = *ub;
			}
		}
		if(dp[MAXIDX].len < dp[i].len) MAXIDX = i;
		
	}
	return;
}

int main(void){
	scanf("%d", &N);
	FOR(i, 1, N) 
		scanf("%d", &(A[i]));
	MAXIDX = 1;
	fill(dp+1, dp+N+1, pii(1,-1000000001));
	
	findLIS();
	FOR(i, 1, N)
		printf("%d | %d\n", dp[i].len, dp[i].pre);	
	printf("%d\n", dp[N].len);
	
	int pathChk = MAXIDX;
	while(pathChk != -1000000001){
		stk.push(A[pathChk]);
		pathChk = dp[pathChk].pre;
	}
	while(!stk.empty()){
		printf("%d ", stk.top());
		stk.pop();
	}
		
	return 0;

}
