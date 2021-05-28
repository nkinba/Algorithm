#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define w first
#define nodes second

using namespace std;

typedef pair<int,int> pii;
typedef pair<int, pii> edge;

int V, E, A, B, C, edgeCnt = 0;
int parents[10001];
edge edges[100001];
int weight = 0;

int getRoot(int cur){
	if(parents[cur] == cur) return cur;
	return parents[cur] = getRoot(parents[cur]);
}

int find(int a, int b){
	int aR = getRoot(a);
	int bR = getRoot(b);
	if(aR == bR) return 0;
	(aR > bR) ? (parents[aR] = bR) : (parents[bR] = aR);
	return 1;	
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E;
	FOR(i, 1, V) parents[i] = i;
	FOR(i, 1, E){
		cin >> A >> B >> C;
		edges[i] = edge(C, pii(A,B));
	}	
	sort(edges+1, edges+E+1);
	
	FOR(i, 1, E){
		edge& e = edges[i];
		if( find(e.nodes.first, e.nodes.second) == 1){
			weight += e.w;
			edgeCnt++;
		}
		if(edgeCnt ==  V-1) break;
	}	
	
	cout << weight;
	
	return 0;
}
