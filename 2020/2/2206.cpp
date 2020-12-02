// 이전에 벽을 부쉈는지와 안 부쉈는지 두 가지 경우에 대해 동시에 bfs진행 
// 벽이 있으면 visited[ ][1]을 true로 하고 queue에 삽입,
// 아니면 		``    `` [0]을 true로 하고 queue에 삽입. 
 
//그리고  현재 위치마다 벽을 부숴서 온 경우와  ( visited[cur][1] == true )
//			 						 아닌 경우 (visited[cur][0] == true ) 
// 들에 대해 다시 주변을 돌면서 경로를 진행해야한다.

#include <bits/stdc++.h>

using namespace std;

int N, M;
char mat[1000][1000];
bool visited[1000*1000][2] = {{false,false},};
queue<int> qi;

int xdir[4] ={-1,0,1,0};
int ydir[4] = {0,-1,0,1};
int cx, cy, nx, ny, dist = 0;
int Min;

bool inRange(int x, int y){
	return (0 <= x && x < M && 0 <= y && y < N);
}

int bfs(){
	qi.push(0);
	visited[0][0] = true;
	
	while(!qi.empty()){
		dist++;
		int qSize = qi.size();
		for(int s = 0; s < qSize; s++){
			int cur = qi.front();
			if(cur == (N*M - 1)) return dist;
			
			cx = cur%M;   5,5, 0 / 5,5, 1
			cy = cur/M;
			qi.pop();
			
			
			for(int d = 0; d < 4; d++){
				nx = cx + xdir[d];
				ny = cy + ydir[d];
				if(inRange(nx, ny)){
					if(visited[cur][1]==true){  	
						if(mat[ny][nx] == '0' && visited[ny*M + nx][1] == false){
							visited[ny*M + nx][1] = true;
							qi.push(ny*M + nx);
						}
					}
					
					if(visited[cur][0]==true) {
						if(mat[ny][nx] == '1' && visited[ny*M +nx][1] == false){
							visited[ny*M + nx][1] = true;
							qi.push(ny*M + nx);
						}
						else if(mat[ny][nx] == '0' && visited[ny*M + nx][0] == false){

							visited[ny*M + nx][0] = true;
							qi.push(ny*M + nx);
						}	
					}
				}
			}
			
		}
	}
	return -1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin  >> N >> M;
	for(int n = 0; n < N; n++){
		for(int m = 0; m < M; m++)
			cin >> mat[n][m];
	}
	
	cout << bfs();
	
	return 0;
}
