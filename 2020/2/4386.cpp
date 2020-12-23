#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define RFOR(i,e,b) for(int i=e; i>=b; i--)

#define w first
#define nodes second

using namespace std;

typedef pair<int,int> pii;
typedef pair<float, float> point;
typedef pair<float, pii> edge;

int n;
float x, y, stellaWeight = 0.0;
int parents[101];
point points[101];
edge edges[9901];
int edgeCnt = 0, stellaEdges = 0;

int getRoot(int cur){
	if(parents[cur] == cur) return cur;
	return parents[cur] = getRoot(parents[cur]);
}

float dist(point p1, point p2){
	return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
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
	
	cin >> n;
	FOR(i, 1, n){
		cin >> x >> y;
		parents[i] = i;
		points[i] = point(x,y);
		RFOR(j, i-1, 1)
			edges[++edgeCnt] = edge(dist(points[i], points[j]), pii(i,j));
	}
	
	sort(edges+1, edges+edgeCnt+1);
	FOR(i, 1, edgeCnt){
		edge& e = edges[i];
		if( find(e.nodes.first, e.nodes.second) == 1){
			stellaWeight += e.w;
			stellaEdges++;
		}
		if(stellaEdges ==  n-1) break;
	}	
	
	cout << fixed;
	cout.precision(2);
	cout << stellaWeight;
	
	return 0;
}
