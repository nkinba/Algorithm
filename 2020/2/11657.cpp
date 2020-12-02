// N (1 ≤ N ≤ 500) , M (1 ≤ M ≤ 6,000)
// 둘째 줄부터 M개의 줄에는
// A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)
// 왜 거리 값(dist[]) 타입을 long long 으로 하지 않으면 출력 초과가 나는지
// 이유를 잘 모르겠다... 아래 코드는 HardCase(500, 6000, 1,2에 대해 -10000값 weight를 갖는 edge들로 구성) 
// 를 입력받는다.
  
#include <bits/stdc++.h>

#define MAX 1e9
#define dest first
#define cost second

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int N,M,a,b,t;
bool result;
vector<pii> destAndCost[501];
ll dist[501] = {0,};

bool BellmanFord(){
	for(int i = 1; i <= N; i++){
		for(int n = 1; n <= N; n++){
			if(dist[n] == MAX) continue;
			vector<pii>& edges = destAndCost[n];
			for(int e = 0; e < edges.size(); e++){
				if(dist[edges[e].dest] > dist[n] + edges[e].cost ){
					if( i == N ) return false;
					dist[edges[e].dest] = dist[n] + edges[e].cost;
				}
			}
		}
	}

	return true;
}

int main(void){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ifstream ifs("11657HardCase.txt");
	ifs >> N >> M;
//	cin >> N >> M;

	fill(dist+2, dist+N+1, MAX);
	for(int m = 0; m < M; m++){
//		cin >> a >> b >> t;
		ifs >> a >> b >> t;
		destAndCost[a].emplace_back(pii(b,t));
	}

	result = BellmanFord();

//	if(!result) cout << -1;
//	else {
//		for(int i = 2; i <= N; i++)	
//			cout << ( (dist[i]==MAX) ? -1 : dist[i]) << "\n";
//	}

	for(int i = 1; i <= 10; i++)	
			cout << dist[i] <<endl;
	ifs.close();
	
	return 0;
}
