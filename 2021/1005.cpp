#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int T, N, K, D, X, Y;
int W[1001];
int P[1001];
int Wpresum[1001];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	FOR(t, 1, T){
		cin >> N >> K;
		fill(P+1, P+N+1, 0);
		fill(Wpresum+1, Wpresum+N+1, 0);
		
		queue<int> nq;
		vector<int> br[N+1];
		
		FOR(i, 1, N) cin >> W[i];
	
		FOR(i, 1, K){
			cin >> X >> Y;
			br[X].emplace_back(Y);
			P[Y]++;
		}
		FOR(i, 1, N){
			if(P[i] == 0) {
				Wpresum[i] = W[i];
				nq.push(i);
			} 
		} 
		cin >> D;
		
		bool f = false;
		while(!f){
			int qSize = nq.size();
			FOR(i, 1, qSize){
				int cur = nq.front();
				if(cur == D) {
					f = true;
					break;
				}
				nq.pop(); 
				vector<int>& nextNodes = br[cur];
				for(int next : nextNodes){
					Wpresum[next] = max(Wpresum[cur], Wpresum[next]);
					if(--P[next] == 0 ) {
						Wpresum[next] += W[next];
						nq.push(next);
					} 
				}
			}
		}
		cout << Wpresum[D] << '\n';
	}
	
	return 0;
}
