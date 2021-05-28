#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int N, M, K, a, b;
ll c;
vector<ll> inp;
vector<ll> tree;

ll setTree(int cur, int start, int end){
	if(start == end)
		return tree[cur] = inp[start];
	return tree[cur] = (setTree(cur*2, start, (start+end)/2) 	
						  * setTree(cur*2+1, (start+end)/2 + 1, end))%MOD;
}

ll modTree( int cur, int start, int end){
	if(b < start || b > end) return tree[cur];
	if(start == end)
		return tree[cur] = inp[b] = c;
	
	return tree[cur]
	=  (modTree(cur*2, start, (start+end)/2) *
		modTree(cur*2 + 1, (start+end)/2 + 1, end))%MOD;
	
}

ll getMul(int cur, int start, int end){
		if(c < start || b > end) return 1;
		if(b <= start && end <= c) return tree[cur];
		return 
			(getMul(cur*2, start, (start+end)/2) *
			getMul(cur*2 + 1, (start+end)/2 + 1, end)
			)%MOD;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M >> K;
	inp.resize(N+1);
	tree.resize(1<< (int)ceil(log2(N))+1);
	
	for(int i=1; i <= N; i++) cin >> inp[i];
	
	setTree(1, 1, N);
	
	for(int i=0; i < M+K; i++){
		cin >> a >> b >> c;
		if(a == 1) {
			modTree(1, 1, N);
		} else 
		 	cout << getMul(1, 1, N) << '\n';
	}
	
	return 0;
}
