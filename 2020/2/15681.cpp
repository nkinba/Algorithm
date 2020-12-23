#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, R, Q, a, b, q;
vector<int> lists[100001];
int leaves[100001];

int cntLeaves(int r){
	leaves[r] = 1;
	vector<int>& nears = lists[r];
	for(int nearNode : nears){
		if(leaves[nearNode] == -1)
			leaves[r] += cntLeaves(nearNode);	
	}
 	return leaves[r];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> R >> Q;
	FOR(i, 1, N-1){
		cin >> a >> b;
		lists[a].emplace_back(b);
		lists[b].emplace_back(a);
	}	
	fill(leaves+1, leaves+N+1, -1);
	cntLeaves(R);
	
	FOR(i, 1, Q){
		cin >> q;
		cout << leaves[q]<< '\n';		
	}	

	return 0;
}
