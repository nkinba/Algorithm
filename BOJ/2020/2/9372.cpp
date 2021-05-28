#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int T, N, M, f, t, cnt;
int parents[1001];

int getRoot(int cur){
	if(parents[cur] == cur) return cur;
	return parents[cur] = getRoot(parents[cur]);
}

int find( int a, int b){
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
	
	cin >> T;
	FOR(testCase, 1, T){
		cnt = 0;
		cin >> N >> M;
		FOR(l, 1, N) 
			parents[l] = l;
		
		FOR(i, 1, M){
			cin >> f >> t;
			int rst =find(f,t);
			if(rst) cnt++;
		
		}	
		cout << cnt << '\n';
	}	

	return 0;
}
