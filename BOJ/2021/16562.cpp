#include <bits/stdc++.h>

using namespace std;

int A[10001];
int parents[10001];
int minCost[10001] = {0,};
int N, M, k;
int v, w;

int findParent(int i){
	if(parents[i] == i) return i;
	return parents[i] = findParent(parents[i]);
}

void uni(int v, int w){
	int pv = findParent(v);
	int pw = findParent(w);
	
	if(pv > pw) parents[pv] = pw; 
	else if(pw > pv) parents[pw] = pv;
	return;
}

int main(void){
	long long cost = 0;
	
	cin >> N >> M >> k;
	for(int i=1; i<=N; i++){
		cin >> A[i];
		parents[i] = i;
	}
	
	for(int i=1; i<=M; i++){
		cin >> v >> w;
		uni(v,w);
	}
	
	for(int i=1; i<=N; i++){
		int p = findParent(i);
		if(minCost[p] == 0) minCost[p] = A[i];
		else minCost[p] = min(minCost[p], A[i]);
	}
	
	sort(minCost+1, minCost+10001, greater<int>());

	for(int i=1; i<=10001; i++){
		if(minCost[i] == 0 || k < 0) break;
		cost += minCost[i];
		k -= minCost[i];
	}

	if(k < 0) cout << "Oh no";
	else cout << cost;

	return 0;
}

