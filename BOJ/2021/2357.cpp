#include <bits/stdc++.h>

using namespace std;

int a, b, N, M;
vector<int> inp;
vector<int> minTree;
vector<int> maxTree;

int setMaxTree(int cur, int start, int end);
int setMinTree(int cur, int start, int end);
int getMax(int cur, int start, int end);
int getMin(int cur, int start, int end);

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	inp.resize(N+1);
	minTree.resize(1 << (int)ceil(log2(N)) +1);
	maxTree.resize(1 << (int)ceil(log2(N)) +1);
	
	for(int i=1; i<=N; i++)
		cin >> inp[i];
	
	setMaxTree(1, 1, N);
	setMinTree(1, 1, N);
	
	for(int i=1; i<=M; i++){
		cin >> a >> b;	
		cout << getMin(1, 1, N) << " " << getMax(1, 1, N)<<'\n';
	}
	
	return 0;
}

int setMaxTree(int cur, int start, int end){
	if(start == end) return maxTree[cur] = inp[start];
	return maxTree[cur] = max(
		setMaxTree(cur*2, start, (start+end)/2),
			setMaxTree(cur*2 + 1, (start+end)/2 + 1, end)
			);
			
}

int setMinTree(int cur, int start, int end){
	if(start == end) return minTree[cur] = inp[start];
	return minTree[cur] = min(
		setMinTree(cur*2, start, (start+end)/2),
			setMinTree(cur*2 + 1, (start+end)/2 + 1, end)
			);
			
}

int getMax(int cur, int start, int end){
	if(start >= a && end <= b) return maxTree[cur];
	if(a > end || b < start) return -1;
	return  max(
			getMax(cur*2, start, (start+end)/2),
			getMax(cur*2 + 1, (start+end)/2 + 1, end)
		);
}

int getMin(int cur, int start, int end){
	if(start >= a && end <= b) return minTree[cur];
	if(a > end || b < start) return 1000000001;
	return  min(
			getMin(cur*2, start, (start+end)/2),
			getMin(cur*2 + 1, (start+end)/2 + 1, end)
		);

}
