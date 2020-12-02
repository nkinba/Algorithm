// TIMEOUT
// bfs + brute
 
#include <bits/stdc++.h>

using namespace std;

typedef queue<int> qi;

int N, M, Min, dist;
char MAP[1000][1000];  //1M

vector<int> nearWalls[1000*1000]; //max 1M
vector<int> walls;

bool wallVisited[1000*1000] = {false, }; //1M
bool nodeVisited[1000*1000] = {false, }; //1M

qi nodeQ, wallQ;
int cur, nx, ny, nodeQSize;

int xdir[4] = {-1,0,1,0};
int ydir[4] = {0,-1,0,1};

void printMap(){
	cout << endl;
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++)
			cout<< MAP[y][x];
		cout << endl;
	}
}

bool inRange(int x, int y){
	return (0 <= x && x < M && 0 <= y && y < N);
}

void clear( qi &q ){
   qi empty;
   swap( q, empty );
}

int nBfs(){
	
//	printMap();
	
	int cnt = 1;
	nodeQ.push(0);
	nodeVisited[0] = true;
	
	while(!nodeQ.empty()){
		nodeQSize = nodeQ.size();
		for(int s = 0; s < nodeQSize; s++){
			cur = nodeQ.front();
			nodeQ.pop();
			for(int d = 0; d < 4; d++){
				nx = cur%M + xdir[d];
				ny = cur/M + ydir[d];
				
				if(nx == M-1 && ny == N-1)	{
					clear(nodeQ);
					return cnt+1;
				}	
				
				if(inRange(nx, ny) && !nodeVisited[ny*M + nx] && MAP[ny][nx]=='0'){
					nodeQ.push(ny*M + nx);
					nodeVisited[ny*M + nx] = true;
				}
			}
		}
		++cnt;
	}
	return -1;
}

void wBfs(){
	for(int b = 0; b < walls.size(); b++){
		if(wallVisited[walls[b]] == false){
			wallVisited[walls[b]] = true;
			wallQ.push(walls[b]);
			
			while(!wallQ.empty()){
				int wall = wallQ.front();
				
				// node bfs
				MAP[wall/M][wall%M] = '0';
				dist = nBfs();
				if(dist != -1) Min = min(dist, Min);
				
				fill_n(nodeVisited, N*M, false);
				MAP[wall/M][wall%M] = '1';
				
				wallQ.pop();
				vector<int>& nearWall = nearWalls[wall];
				for(int w = 0; w < nearWall.size(); w++){
					int nxtWall = nearWall[w];
					if( inRange(nxtWall%M, nxtWall/M) &&
					    !wallVisited[nxtWall] ){
						wallVisited[nxtWall] = true;
						wallQ.push(nxtWall);	    	
					}
				}		
			}
		}
	}

}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	Min = N * M + 1;
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++)
			cin >> MAP[y][x];
	}
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			if(MAP[y][x] == '1'){
				walls.emplace_back(y*M + x);
				if(y < N-1 && MAP[y+1][x]=='1'){
					 nearWalls[y*M + x].emplace_back((y+1)*M + x);
					 nearWalls[(y+1)*M + x].emplace_back(y*M + x);
				}
				if(x < M-1 && MAP[y][x+1]=='1'){
					 nearWalls[y*M + x].emplace_back(y*M + x+1);
					 nearWalls[y*M + x+1].emplace_back(y*M + x);
				}
			}
		}
	}
	
	wBfs();
	if (Min > N*M) Min = -1;
	cout << Min;
	
	return 0;
}
