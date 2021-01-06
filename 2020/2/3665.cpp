// 자력으로 풀지 못한 위상 정렬 문제...
// 위상 정렬 이용한 원리를 잘 생각해보자 

#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

//typedef pair<int,int> pii;

int N, M, T, a, b;
int* entryCnt;
int* totalRanks;
int* myRanks;

int adj[501][501];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >>T;
	FOR(t, 1 ,T){
		queue<int> targetQ;
		queue<int> resultQ;
		
		cin >> N;
		memset(adj, 0, sizeof adj);
		myRanks = new int[N+1];
		totalRanks = new int[N+1];
		entryCnt = new int[N+1];
		fill(entryCnt+1, entryCnt+N+1, 0);
		
		FOR(i, 1, N){
			cin >> totalRanks[i];
			myRanks[totalRanks[i]] = i;
		}
		
		FOR(i, 1, N-1){
			FOR(j, i+1, N){
				int from = totalRanks[i];
				int to = totalRanks[j];
				
				adj[from][to] = 1;
				entryCnt[to]++;
			}
		}
		
		cin >> M;
		FOR(i, 1, M){
			int better, worse;
			cin >> a >> b;
			worse = b; better = a;
			if(myRanks[a] > myRanks[b]){
				worse = a; better = b;
			}
			if(entryCnt[worse] > 0)
				entryCnt[worse]--;
			entryCnt[better]++;
			
			adj[worse][better] = 1;
			adj[better][worse] = 0;
		}
		
		FOR(i, 1, N){
			if(entryCnt[i]==0) 
				targetQ.push(i);
		}

		while(!targetQ.empty()){
			if(targetQ.size() > 1){
				cout << "?\n";
				break;
			}
			int cur = targetQ.front();
			targetQ.pop();
			resultQ.push(cur);
			FOR(i, 1, N){
				if(adj[cur][i] > 0){
					if(--entryCnt[i] == 0)
						targetQ.push(i);
				}
			}
		}
			
		if(targetQ.empty()){
		
			if(resultQ.size() != N)
				cout << "IMPOSSIBLE\n";
		
			else {
				FOR(i, 1, N){
					cout << resultQ.front() << " ";
					resultQ.pop();
				}
				cout << "\n";
			}
		}
	
		delete myRanks;
		delete totalRanks;
		delete entryCnt;

	}
	return 0;
}
