#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char maze[100][100];
vector<int> nodes[10000];
queue<int> Q;
int N, M, n, m, cnt = 1;
bool visited[10000] = {false, };

void bfs(){
	Q.push(0);
	visited[0] = true;
	
	while(!Q.empty()){
		for(int s = 0; s < Q.size(); s++){
			vector<int>& nextNodes = nodes[Q.front()];
			Q.pop();
			for(int i=0; i < nextNodes.size(); i++){
				if(nextNodes[i] == (N*M - 1)){
					cnt++;
					return;
				}
				if(!visited[nextNodes[i]]){
					visited[nextNodes[i]] = true;
					Q.push(nextNodes[i]);
				}
			}
		}
		cnt++;
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			cin >> maze[i][j];
	}
		
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(maze[i][j] == '1'){
				if(i < N-1 && maze[i+1][j] == '1'){
					nodes[i*M + j].emplace_back( (i+1)*M + j );
					nodes[(i+1)*M + j].emplace_back( i*M + j );
				}
				if(j < M-1 && maze[i][j+1] == '1'){
					nodes[i*M + j].emplace_back( i*M + j+1 );
					nodes[i*M + j+1].emplace_back( i*M + j );	
				}
			}
		}
	}	

	bfs();
	cout << cnt;
	
	return 0;
}
