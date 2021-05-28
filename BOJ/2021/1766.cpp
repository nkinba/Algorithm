// priority_queue 를 이요해 노드 번호가 낮은 것부터 먼저 처리하는 식 

#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, p, l;
vector<int> children[32001];
int Pcnt[32001] = {0,};
priority_queue<int> Q;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	FOR(i, 1, M){
		cin >> p >> l;
		children[p].push_back(l);
		Pcnt[l]++;
	}

	FOR(i, 1, N){
		if(Pcnt[i] == 0) Q.push(-i);
	}
	
	while(!Q.empty()){
		int cur = -Q.top();
		cout << cur << " ";
		Q.pop(); 
		vector<int>& nextNodes = children[cur];
		for(int next : nextNodes){
			if(--Pcnt[next] == 0 ) 
				Q.push(-next);
		}
	}
	
	return 0;

}
