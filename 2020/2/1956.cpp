// dfs로 시도, TO
// 플로이드 와샬 시도,  2644kB, 100ms

#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define MAX 4000001

using namespace std;

int V,E,a,b,c;
int cost[401][401];

int result = MAX; 

void fw(){
	FOR(i, 1, V){
		FOR(j, 1, V){
			FOR(k, 1, V)
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
		}
	}
} 

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E;
	FOR(i, 1, V){
		FOR(j, 1, V)
			cost[i][j] = MAX;
	}
	
	FOR(i, 1, E){
		cin >> a >> b >> c;
		cost[a][b] = c;
	}
	
	fw(); 
	
	FOR(start, 1, V) result = min(result, cost[start][start]);
	cout << ((result == MAX) ? -1 : result);
	
	return 0;
}
