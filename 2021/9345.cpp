#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int T, N, K;
int Q, a, b;
vector<int> inp;
vector<int> minTree;
vector<int> maxTree;

pii modTree(int from, int to, int cur, int start, int end){
 	int& MIN = minTree[cur];
 	int& MAX = maxTree[cur];
 	
	if(start > from || end < from ) 
		return pii(MIN, MAX);
	
	MIN = min(MIN, to);
	MAX = max(MAX, to);

	if(start == end){
		MIN = MAX = to;
		return pii(MIN, MAX);

	}
	
	pii l = modTree(from, to, cur*2, start, (start+end)/2);
	pii r = modTree(from, to, cur*2 + 1, (start+end)/2 + 1, end);
	MIN = min(l.first, r.first);
	MAX = max(l.second, r.second);

	return pii(MIN, MAX);
}

int setMaxTree(int cur, int start, int end){
	int& rst  = maxTree[cur];
	if(start == end)
		rst = inp[start];
	
	else {
		setMaxTree(cur*2, start, (start+end)/2);
		setMaxTree(cur*2 + 1, (start+end)/2 + 1, end);
		rst = max(
			maxTree[cur*2], maxTree[cur*2 + 1]
		);
	}
			
	return rst;	
}

int setMinTree(int cur, int start, int end){
	int& rst  = minTree[cur];
	if(start == end)
		rst = inp[start];
	
	else {
		setMinTree(cur*2, start, (start+end)/2);
		setMinTree(cur*2 + 1, (start+end)/2 + 1, end);
		rst = min(
			minTree[cur*2], minTree[cur*2 + 1]
		);
	
	}		
	return rst;
}

int getMax(int cur, int start, int end){
	if(start >= a && end <= b) return maxTree[cur];
	if(a > end || b < start) return -1000000;
	return  max(
			getMax(cur*2, start, (start+end)/2),
			getMax(cur*2 + 1, (start+end)/2 + 1, end)
		);
}

int getMin( int cur, int start, int end){
	if(start >= a && end <= b) return minTree[cur];
	if(a > end || b < start) return 1000000;
	return  min(
			getMin(cur*2, start, (start+end)/2),
			getMin(cur*2 + 1, (start+end)/2 + 1, end)
		);

}

void p(){
	for(int e : inp) cout << e <<" ";
	cout <<endl;
}

void pt(){
	cout << " MIN \n";
	for(int i=1; i<minTree.size(); i++){
		cout << "cur :" << i << " -> " << minTree[i] <<endl;
	}

	cout <<"\n MAX \n";
	for(int i=1; i<maxTree.size(); i++){
		cout << "cur :" << i << " -> " << maxTree[i] <<endl;
	}
}

void check(){
 	int MIN = getMin(1,1,N);
 	int MAX = getMax(1,1,N);
	if(a == MIN && b == MAX)
		cout << "YES\n";
	else cout << "NO\n";
	return;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for(int t = 1;  t <= T; t++){
		cin >> N >> K;
		
		inp.clear();
		minTree.clear();
		maxTree.clear();
		
		inp.resize(N+1);
		minTree.resize(1 << (int)ceil(log2(N)) +1);
		maxTree.resize(1 << (int)ceil(log2(N)) +1);
		
		for(int i=1; i<=N; i++)
			inp[i] = i;
		
		setMaxTree(1, 1, N);
		setMinTree(1, 1, N);
		for(int i=1; i<=K; i++){
			cin >> Q >> a >> b;
			a++; b++;
			if(Q == 0) {
				modTree(a, inp[b], 1, 1, N);
				modTree(b, inp[a], 1, 1, N);
				swap(inp[a], inp[b]);
			} 
			else check();
		}
	}
		
	return 0;
}

