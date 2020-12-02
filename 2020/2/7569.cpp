#include <bits/stdc++.h>

using namespace std;

queue<int> Q;
int N, M, H, t, loc;
int days = 0, rests = 0;
int cur, nxt, cx, cy, cz, nx, ny, nz;
bool visited[1000000] = {false, };
int box[100][100][100];

int xdir[6] = {-1,0,1,0,0,0};
int ydir[6] = {0,-1,0,1,0,0};
int zdir[6] = {0,0,0,0,1,-1};

bool isInRange(int x, int y, int z){
	return (( 0 <= x && x < M) &&
		   	( 0 <= y && y < N) &&
		    ( 0 <= z && z < H));
}

void bfs(){
	while(!Q.empty()){
		days++;
		int qSize = Q.size();
		for(int s = 0; s <  qSize; s++){
			cur = Q.front();
			Q.pop();	
			cz = cur / (N*M);
			cy = (cur % (N*M)) / M;
			cx = (cur % (N*M)) % M;
		
			for(int d = 0; d < 6; d++){
				nx = cx + xdir[d]; 
				ny = cy + ydir[d];
				nz = cz + zdir[d];
				nxt = nz*(N*M) + ny*M + nx;
				
				if(isInRange(nx, ny, nz) && !visited[nxt] && box[nz][ny][nx]==0){
					rests--;
					visited[nxt] = true;
					Q.push(nxt);
				}
				
			}
			
		}
		
	}
	days = ((rests > 0) ? -1 : days-1 );	
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> M >> N >> H;
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n++){
			for(int m = 0; m < M; m++){
				cin >> t;
				box[h][n][m] = t;
				if(t == 1){
					 loc = h*(N*M) + (n*M) + m;
					 Q.push(loc);
					 visited[loc] = true;
				}
				else if(t == 0) rests++;
			}
		}
	} 

	if(rests > 0) bfs();
	
	cout << days;
	
	return 0;
}
