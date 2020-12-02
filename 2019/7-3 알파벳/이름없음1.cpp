#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int MAX=1;
int R,C;
char mat[20][20];
set<char> SET;
//set<char>::iterator it;


void start(int r, int c, int& s){
	++s;
	if(MAX < s) MAX = s;
	

	if( c>0 && (SET.find(mat[r][c-1]) == SET.end() )){
		SET.insert(mat[r][c-1]);
//		cout << "1" <<endl;
		start(r, c-1, s);
	}

	if( r>0	&& (SET.find(mat[r-1][c]) == SET.end()) ){
		SET.insert(mat[r-1][c]);
//				cout << "2" <<endl;
		start(r-1, c, s);
	}
		
	if( c<C-1 && (SET.find(mat[r][c+1]) == SET.end() )){
		SET.insert(mat[r][c+1]);
//				cout << "3" <<endl;
		start(r, c+1, s);
	}
	
	if( r<R-1 && (SET.find(mat[r+1][c]) == SET.end() )){
		SET.insert(mat[r+1][c]);
//				cout << "4" <<endl;
		start(r+1, c, s);
	}
	
	SET.erase(mat[r][c]);
	--s;
	return;
}

int main(void){
	ifstream ifs("1.txt");
	
	int s=0;   
	ifs >> R >> C;

	for(size_t i=0; i<R; i++){
		for(size_t j=0; j<C; j++){
			ifs >> mat[i][j];
		}
	}
	
	SET.insert(mat[0][0]);
	start(0,0,s);
	cout << MAX <<endl;
	ifs.close();
	return 0;
}
