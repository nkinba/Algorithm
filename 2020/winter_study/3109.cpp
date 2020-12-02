/* 	3109 빵집  
	6868KB	92ms	C++14
	
	 2차원 배열의 제일 윗 행부터 마지막 행까지 dfs를 사용해 최대한 길을 만들도록 한다. 
				윗 행에서 출발해서 방문했다가 결국 길을 완성하지 못했다면 그 경로는 아래 행에서 경로를 탐색할 때 굳이 방문할 필요가 없어진다.
				(그리디 알고리즘으로 이해할 수 있다.)
				  
	시행 착오 : 2차원 배열의 방문 위치를 표시할 때 현재 성공한 개수에 +48을 해 (0~9)숫자를 나타내는 문자로 표현하고 싶었지만
	 		    R값이 커지면 char 범위를 넘어가게 된다. 시간이 오래 걸리지만 char범위를 넘어가도 결국 답이 나오는 경우가 있었는데
				컴파일러에서 어떻게 처리되는 건지 궁금하다.   
	
	https://www.acmicpc.net/problem/3109 
*/

#include <iostream>
//#include <fstream>

using namespace std;
typedef pair<int,int> pii;

int R,C,Answer = 0;
char place[10000][500];
int dir[3] = {-1,0,1};

bool inRange(int r){
	return (0<=r && r<=R-1);
}

bool Search(int r, int c){
	if(c==C-1) return true;
	
	bool Arrival = false;
	for(size_t n=0; n<3; n++){
		int D = dir[n];
		if(inRange(r+D)){
 			 if(place[r+D][c+1]=='.'){
				place[r+D][c+1] = 'x'; // N+48 로 바꾸면 시간이 훨씬 오래걸려서 헤맴. 
				Arrival = Search(r+D, c+1);
				if(Arrival) break;
			}
		}		
	}
	return Arrival;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
// 	ifstream ifs("3109tc.txt");
//	ifs >> R >> C;
 	
	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++)
			cin >> place[i][j];
//			ifs >> place[i][j];
	}
//	ifs.close();

	for(size_t i=0; i<R; i++){
		if(Search(i,0)) 
			Answer++;
	}
	
	cout << Answer;
	
	return 0;
}
