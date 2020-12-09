// 이분 탐색(log N) 을각 위치에서 수행

#include <cstdio>
#include <algorithm>
#include <stack>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

using namespace std;

int N, inp;
int A[1000001];
int dp[1000001];
stack<int> stk;
vector<int> vt;

int main(void){
	scanf("%d", &N);
	fill(dp+1, dp+N+1, 0);
	vt.push_back(-1000000001);

	FOR(i, 1, N){
		scanf("%d", &inp);
		A[i] = inp;
	    if (vt.back() < inp) {
	        dp[i] = vt.size();
	        vt.push_back(inp);
	    }
	    else {
	        auto it = lower_bound(vt.begin(), vt.end(), inp);
			dp[i] = (it - vt.begin());
	        *it = inp;
	    }
	}
	
	int len = vt.size()-1;
	printf("%d\n", len );
	
	REVFOR(i, N, 1){
		if(dp[i] == len){
			stk.push(A[i]);
			if(--len == 0) break;
		}
	}
	while(!stk.empty()){
		printf("%d ", stk.top());
		stk.pop();
	}

	return 0;

}
