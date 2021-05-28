// 통과는 되지만 1에 비해 시간ㅇ ㅣ2배로 걸려요 
//7624KB	200ms	C++14 	2389B

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool>* Map;
vector< vector<bool> > stepVisited;
vector< vector<bool> > jumpVisited;
queue< pair<int,int> > posQueue;
//         좌표정보 , K 수   

int K,W,H; 
int Move=0;

int rdir[12] = { 0, -1, 0, 1, -1, -2, -2, -1, 1 , 2 , 2 , 1};
int cdir[12] = { -1, 0, 1, 0, -2, -1,  1,  2,-2, -1,  1,  2};

//void print(){
//	for(size_t i=0; i<H; i++){
//		for(size_t j=0; j<W; j++){
//			cout  <<  Map[i][j] <<  " ";
//		}
//		cout <<endl;
//	}	
//}

int BFS(){
	int pos;

	posQueue.push(make_pair(0,0));	
	for(int i=0; i<=K; i++){
		stepVisited[0][i] = true;	
		jumpVisited[0][i] = true;	
//		Visited[0][i]= true;
	}
	
	while(!posQueue.empty()){
//		cout << "-----------MOVE : " << Move << "-----------------" <<endl;
		int queueSize = posQueue.size();
		for(int p=0; p<queueSize; p++){
			pos = posQueue.front().first;
			int Ks = posQueue.front().second;	
			if(pos == W*H-1 && Ks <= K) 
				return Move;
			int r = pos/W; int c = pos%W; 	
//			cout << "r : " <<r << " c : " << c << " K : " << Ks << endl;	
			posQueue.pop();			
			for(int i=0; i<12; i++){
				
				int nextr = r+rdir[i]; int nextc = c+cdir[i];
				// In Range
				if( 0<= nextr && nextr <= H-1 && 0 <= nextc && nextc <= W-1){
					
					if( i>=4 && Ks < K ){
						if(!jumpVisited[nextr*W + nextc][Ks+1] && Map[nextr][nextc]==0 ){  // 여기서 방문 체크할 때 Ks+1을 안했었음.. 
//							cout<< "JUMP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks+1));
							jumpVisited[nextr*W+nextc][Ks+1] = true;
						}
					}
					else if( i< 4 ){
						if(!stepVisited[nextr*W + nextc][Ks] && Map[nextr][nextc]==0 ){
//							cout<< "STEP & PUSHING " << nextr << ", " << nextc <<endl; 
							posQueue.push(make_pair(nextr*W+nextc, Ks));
							stepVisited[nextr*W+nextc][Ks] = true;
						}
						
					} 
					
				}
			}	
		}
		Move++;
	}
	
	return -1;
}

int main(void){
	cin >> K >> W >> H;
	Map = new vector<bool>[H];
	stepVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	jumpVisited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
//	Visited = vector< vector<bool> >(W*H, vector<bool>(K+1,false));
	for(int i=0; i<H; i++){
		Map[i] = vector<bool>(W);
		for(int j=0; j<W; j++){
			bool b;	 cin >> b;	Map[i][j] = b;
		}
	}
	
	cout << BFS();
	
	return 0; 
}
