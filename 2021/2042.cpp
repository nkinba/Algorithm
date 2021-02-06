#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, K, a, b;
ll c;
vector<ll> inp;
vector<ll> tree;

ll setTree(int cur, int start, int end){
	if(start == end)
		return tree[cur] = inp[start];
	return tree[cur] = setTree(cur*2, start, (start+end)/2) 	
						  + setTree(cur*2+1, (start+end)/2 + 1, end);
}

void modTree(ll diff, int cur, int start, int end){
	if(b < start || b > end) return;
	tree[cur] = tree[cur] + diff;
	if(start != end){
		modTree(diff, cur*2, start, (start+end)/2);
		modTree(diff, cur*2 + 1, (start+end)/2 + 1, end);
	}
	return;
}

ll getSum(int cur, int start, int end){
		if(c < start || b > end) return 0;
		if(b <= start && end <= c) return tree[cur];
		return 
			getSum(cur*2, start, (start+end)/2) +
			getSum(cur*2 + 1, (start+end)/2 + 1, end);
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
			ll diff = c - inp[b];
			inp[b] = c;
			modTree(diff, 1, 1, N);
		} else 
		 	cout << getSum(1, 1, N) << '\n';
	}
	
	return 0;
}
