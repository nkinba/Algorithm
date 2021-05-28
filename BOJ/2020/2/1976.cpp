#include <iostream>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, link, start, coRoot;
int parents[201];

int findRoot(int node){
	if(parents[node] == node) return node;
	return parents[node] = findRoot(parents[node]);
}

void uni(int a, int b){
	int aR = findRoot(a);
	int bR = findRoot(b);
	if(aR == bR) return;
	(aR > bR) ? (parents[aR] = bR) : (parents[bR] = aR);
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	FOR(i,1,N) parents[i] = i;
	FOR(i,1,N){
		FOR(j,1,N){
			cin >> link;
			if(link)		
		// i,j가 서로 바뀌었을 때 생략하면 안된다. 
		// 둘 중 낮은 노드 외에 또다른 낮은 위치의 노드에서의
		//  findRoot 호출로 인해 
		// 더 높은 쪽의 root만 갱신될 가능성이 있다. 
				uni(i,j);
			
		}
	}
	
//	FOR(i,1,N) cout << parents[i] << endl;
	
	cin >> start;
	coRoot = parents[start];
	
	int m, path;
	for(path = 2; path <= M; path++){
		cin >> m;
		if(parents[m] != coRoot){
			cout << "NO";
			break;
		}
	} 
	if(path > M) cout << "YES";
	
	return 0;
}
