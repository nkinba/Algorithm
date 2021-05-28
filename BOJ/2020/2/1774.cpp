#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define RFOR(i,e,b) for(int i=e; i>=b; i--)

#define w first
#define nodes second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, pll> edge;

int N, M, x, y, f, t;
int parents[1001];
pll points[1001];
vector<edge> edges;
int edgeCnt = 0;
double weight = 0;

double dist(pll p1, pll p2){
	return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

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
	
	cin >> N >> M;
	FOR(i, 1, N){
		parents[i] = i;
		cin >> x >> y;
		points[i] = pll(x,y);
	}
	FOR(m, 1, M){
		cin >> f >> t;
		find(f,t);
	}
	
	FOR(i, 1, N){
		RFOR(j, i-1, 1){
			if(getRoot(i) != getRoot(j))
				edges.emplace_back(edge(dist(points[i], points[j]), pll(i,j)));
		} // 이미 설정된 통로를 제외해주지 않으면 왜 안될까? 
	}
	
	sort(edges.begin(), edges.end());
	for(edge e : edges){
		if( find(e.nodes.first, e.nodes.second) == 1){
			weight += e.w;
			edgeCnt++;
		}
		if(edgeCnt ==  N-M) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << weight;
	return 0;
}
