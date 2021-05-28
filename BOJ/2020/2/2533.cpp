#include <bits/stdc++.h> 
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, a, b;
vector<int> links[1000001];
int dp[2][1000001];

int process(int cur, bool sel, int root){
	int& rst = dp[sel][cur];
	if(rst != -1) return rst;
	
	rst = 0;
	for(int link : links[cur]){
		if(link == root) continue;
		
		if(sel){
			int selNext = process(link, sel, cur);
			int skipNext = process(link, !sel, cur);
			rst += min(selNext, skipNext);
		}
		else 
			rst += process(link, true, cur);
	}
	
	if(sel) rst += 1;
	
	return rst;
}


int main(void){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	scanf("%d", &N);
	FOR(i, 1, N-1){
		scanf("%d%d", &a, &b);
		links[a].emplace_back(b);
		links[b].emplace_back(a);
	}
	
	fill(dp[0]+1, dp[0]+N+1, -1);
	fill(dp[1]+1, dp[1]+N+1, -1);
	
	printf("%d", min(process(1, false, 1), process(1, true, 1)));

	return 0;
}
