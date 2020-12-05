// 이분 탐색(log N) 을각 위치에서 수행

#include <cstdio>
#include <algorithm>
#include <stack>

#define FOR(i,b,e) for(int i=b; i<e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

using namespace std;
typedef pair<int,int> pii;

int N;
pii A[1000000];
stack<int> stk;

int main(void){
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d", &(A[i].first));
		A[i].second = N - i;
	}
	
	
		
	return 0;

}
