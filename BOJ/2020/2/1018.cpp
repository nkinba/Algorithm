#include <bits/stdc++.h>

using namespace std;

char brd[50][50];

int ans = 64;

int checkBrd(int r, int c){
	int b = 0;
	int w = 0;
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			((i+j)%2) 
			  ? ( (brd[r+i][c+j]=='W') ? (++w) : (++b) )
			  : ( (brd[r+i][c+j]=='W') ? (++b) : (++w) );
		}
	}
	return min(b,w);
}

int main(void){
	int N,M;
	cin >> M >> N;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			cin >> brd[i][j];
	} 
	
	for(int i=0; i+8<=M; i++){
		for(int j=0; j+8<=N; j++){
			int rst = checkBrd(i,j);
			ans = min(rst, ans);
		}
	}
	
	cout << ans;
	
	return 0;
}
