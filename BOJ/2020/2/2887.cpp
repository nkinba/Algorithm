#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define RFOR(i,e,b) for(int i=e; i>=b; i--)

#define w first
#define nodes second

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

struct p {
	int x, y, z, n;
	p(int _x, int _y, int _z, int _n) : x(_x), y(_y), z(_z), n(_n) {}
	p(){}
};

int N, x, y, z, dim = 0;
p points[100001];
int parents[100001];
vector<edge> edges;
int weight = 0, edgeCnt = 0;

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

bool cmp(const p& a, const p& b){
	if(dim == 0) return b.x > a.x;
	else if(dim == 1) return b.y > a.y;
	return b.z > a.z;
}

void putEdges(){
	if(dim == 0){
		FOR(p, 1, N-1) 
			edges.emplace_back(edge(points[p+1].x - points[p].x, pii(points[p+1].n, points[p].n)));
	}
	else if(dim == 1){
		FOR(p, 1, N-1) 
			edges.emplace_back(edge(points[p+1].y - points[p].y, pii(points[p+1].n, points[p].n)));
	}
	else {
		FOR(p, 1, N-1) 
			edges.emplace_back(edge(points[p+1].z - points[p].z, pii(points[p+1].n, points[p].n)));
	}
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	FOR(i,1,N) {
		parents[i] = i;
		cin >> x >> y >> z;
		points[i]= p(x,y,z,i);
	}
	
	FOR(d, 0, 2){
		dim = d;
		sort(points+1, points+N+1, cmp);
		putEdges();
//		cout << "d : " << d <<endl;
//		FOR(i, 1, N) 
//			cout <<points[i].x << "," << points[i].y << "," << points[i].z << " : " << points[i].n << endl;
		
	}
	
	sort(edges.begin(), edges.end());
	
	for(edge e : edges){
		if( find(e.nodes.first, e.nodes.second) == 1){
			weight += e.w;
			edgeCnt++;
		}
		if(edgeCnt ==  N-1) break;
	} 
	cout << weight;
	
	return 0;
}
