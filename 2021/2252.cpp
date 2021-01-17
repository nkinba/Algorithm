#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, s, b;
vector<vector<int>> tallers;
int* entryCnt;
queue<int> targetStudQ;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	tallers.resize(N+1);
	entryCnt = new int[N+1];
	fill(entryCnt+1, entryCnt+N+1, 0);
	
	FOR(i, 1, M){
		cin >> s >> b;
		tallers[s].push_back(b);
		entryCnt[b]++;
	}
	FOR(i, 1, N){
		if(entryCnt[i] == 0) targetStudQ.push(i);
	}
	
	while(!targetStudQ.empty()){
		int cur = targetStudQ.front();
		targetStudQ.pop();
		cout << cur << " ";
		for(int taller : tallers[cur]){
			if(--entryCnt[taller]==0)
				targetStudQ.push(taller);
		}
	}
	delete entryCnt;
	
	return 0;
}
