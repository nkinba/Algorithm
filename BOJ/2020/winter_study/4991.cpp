/* 4991 로봇 청소기
	1984KB	44ms	C++14 
	
 	 중복방문을 허용하는 1x1 칸으로 이루어진 지도에서 청소기가 주어진 초기 위치에서 출발해서 더러운 칸을 모두 방문하는데에
	필요한 최소 이동횟수를 구하는 문제.
	
	 청소기 초기 위치와 더러운 점들을 Graph의 vertex로 규정하고 모든 vertex간에 bfs를 통해 구한 최소 이동 횟수를 가중치(weight)로 삼는
	유일한 edge를 두었다. 이 vertex들은 초기에 testcase로부터 입력값을 받을 때 pair<int,int> vertex[10] 배열에 저장되고 
	이 배열의 index값을 순열을 돌려 나온 수열을 방문순서로 삼아 각 vertex를 모두 방문하는데 필요한 최소 이동횟수를 구하였다.
	이 때 최솟값 int m(getShortestPath 함수) 을 두어 각 수열마다 방문하다가 이동횟수가 최솟값을 넘어갈 때에는 곧바로 다음 수열의 경우로
	넘어가도록 하여 시간을 단축시켰다.  
	  
	 makeGraph( int Graph[10][10]의 값을 결정하는 함수 )의 결과가 false 일 때, 즉 방문하지 못하는 더러운  칸이 있는 testcase마다  
	vn(청소기 초기 위치와 더러운 칸의 개수 - 형성할 Graph의 vertex 수)을 초기화 하지 않아서 Runtime Error가 발생했었다.
	
	 ※문제를 해결한 다른 사람들이 알고리즘 유형에 비트마스킹을 추가해놓은 걸 보니 비트마스킹을 이용해 메모리와 시간을 단축시킬수 있을 것 같다!  
*/

#include <iostream>
#include <algorithm>
#include <queue>

#define r first
#define c second

using namespace std;

typedef pair<int,int> pii;

int Graph[10][10];
char Map[20][20];
pii vertex[10];

int rdir[4] = {-1,0,1,0};
int cdir[4] = {0,-1,0,1};

int w=0, h=0; //c, r
int vn = 1;

int* visitOrder;

bool inRange(int r, int c){
	return  ( (0 <= r) && (r < h) && (0 <= c) && (c < w) );
}

int getWeight(pii from, pii to){ // bfs를 통해 Graph를 형성
	int dist = 0;
	bool visited[20][20];
	
	for(size_t i=0; i<h; i++){
		for(size_t j=0; j<w; j++)
		 	visited[i][j]=false;
	}
	
	visited[from.r][from.c] = true;
	queue<pii> vQueue;
	
	for(size_t i=0; i<4; i++){
		int nextr = from.r+rdir[i];
		int nextc = from.c+cdir[i];
		if(inRange(nextr, nextc)){
		  	if( Map[nextr][nextc] != 'x'){
				vQueue.push(pii(nextr,nextc));
				visited[nextr][nextc] = true;
			}
		}
	}
	
	while(!vQueue.empty()){
	 	dist++;
	 	int qSize = vQueue.size();
	 	for(size_t i=0; i<qSize; i++){
	 		pii cv = vQueue.front();
	 	
		 	if(cv == to) 		//탈출조건  
			 	return dist;
		
			for(size_t i=0; i<4; i++){
				int nextr = cv.r+rdir[i];
				int nextc = cv.c+cdir[i];
				if(inRange(nextr, nextc) ){
					 if( Map[nextr][nextc] != 'x' && !visited[nextr][nextc]){
						vQueue.push(pii(nextr, nextc));
						visited[nextr][nextc] = true;
					}
				}
			}
			vQueue.pop();	
		 }
	} 
	return -1;
}

bool makeGraph(){
	for(size_t i=0; i<vn; i++){
		for(size_t j=i; j<vn; j++){
			if(i==j) 
				Graph[i][j] = 0; 
			else{
				Graph[i][j] = Graph[j][i] = getWeight(vertex[i], vertex[j]);
				if(Graph[i][j]==-1) {
					return false;
				}
			}
		}
	}
	return true;
}

int getShortestPath(){
	int m = 1<<10;
	do{
		int preV = 0;
		int sumW = 0;
		size_t i;
		for(i=0; i<vn-1; i++){
				int curV = visitOrder[i];
				sumW += Graph[preV][curV];
				preV= curV;
				if(sumW > m) break;
		}
		if(i!=vn-1) continue;
		m = min(m, sumW);
	}while(next_permutation(visitOrder, visitOrder+vn-1));
	
	return m;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	while(true){   
		cin >> w >> h;
		if(w==0 && h==0) break; // 종료조건  
		
		for(size_t i=0; i<h; i++){
			for(size_t j=0; j<w; j++){
				cin >> Map[i][j];
				if(Map[i][j] == '*'){
					vertex[vn] = pii(i,j);
					vn++;
				}
				else if(Map[i][j]=='o')
					vertex[0] = pii(i,j);
			}
		}

	 	if(!makeGraph())	// 도달할 수 없는 칸이 있는 경우  
		  cout << -1 <<endl;	
		  
		else{
		 	visitOrder = new int[vn-1]; // 칸 방문 순서 배열  
		 	for(size_t i=0; i<vn-1; i++)
		 		visitOrder[i] = i+1;
		
			cout << getShortestPath() <<endl;
			delete visitOrder;
		}
	
		vn = 1;
	}
	
	return 0;
} 
