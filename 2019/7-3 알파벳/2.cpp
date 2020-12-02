#include <iostream>
//#include <fstream>

using namespace std;

int MAX=0;
int R,C;
char mat[20][20];
bool alp[26];



void start(int r, int c, int s){
	if(MAX < s) MAX = s;
	

	if( c>0 && (alp[ mat[r][c-1] - 65] == false)){
		alp[ mat[r][c-1] - 65] = true;
//		cout << "1" <<endl;
		start(r, c-1, s+1);
		
	}

	if( r>0	&& (alp[ mat[r-1][c] - 65] == false)) {
		alp[ mat[r-1][c] - 65] = true;
//				cout << "2" <<endl;
		start(r-1, c, s+1);
	}
		
	if( c<C-1 && (alp[ mat[r][c+1] - 65] == false)){
		alp[ mat[r][c+1] - 65] = true;
//				cout << "3" <<endl;
		start(r, c+1, s+1);
	}
	
	if( r<R-1 && (alp[ mat[r+1][c] - 65] == false)){
		alp[ mat[r+1][c] - 65] = true;
//				cout << "4" <<endl;
		start(r+1, c, s+1);
	}
	
	
	alp[ mat[r][c] - 65] = false;
	return;
}

int main(void){
//	ifstream ifs("1.txt");
	
	int s=1;   
	cin >> R >> C;

	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++){
			cin >> mat[i][j];
		}
	}
	
	
	fill(alp, alp+26, false);
	
	alp[ mat[0][0] - 65 ] = true;
	start(0,0,s);
	cout << MAX <<endl;
//	ifs.close();
	return 0;
}
