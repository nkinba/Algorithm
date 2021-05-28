#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef priority_queue<int> pq;

int N,ci,cj,ni,nj;
char m[25][25]= {{0,},};
int k[313]={0,};
int c = 0;

pq Q;
bool visited[625] = {false,};
int idir[4] = {-1,0,1,0};
int jdir[4] = {0,-1,0,1};

bool inRange(int i, int j){
	return (0<=i && i<N && 0<=j && j<N);
}

void bfs(int i, int j){
//	m[i][j] = 2 + 48;
	int cnt = 1;
	Q.push(i*N + j);
	visited[i*N + j] = true;
	while(!Q.empty()){
		int cur = Q.top();
		Q.pop();
		ci = cur / N;
		cj = cur % N;		
		for(size_t d = 0; d < 4; d++){
			ni = ci + idir[d];
			nj = cj + jdir[d];
			if(inRange(ni, nj) && visited[ni*N + nj] == false && m[ni][nj] == (1+48)){
	//			m[ni][nj] = 2 + 48;
				visited[ni*N + nj] = true;
				Q.push(ni*N + nj);
				cnt++;
			}
		}
	}
	
	k[c++] = cnt;
	
}

void color(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(m[i][j] == 1 + 48) 
				bfs(i,j);
		}
	}
}

int main(void){

	cin >> N;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cin >> m[i][j];
	}
	
	color();
	
	cout << c << "\n";
	sort(k, k+c);
	for(int i=0; i<c; i++)
		cout << k[i] << "\n";
	return 0;
}

