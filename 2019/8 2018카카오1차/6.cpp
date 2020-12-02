#include <iostream>
#include <fstream>
#include <set>

using namespace std;
// 1: down 2: right 3: up

int m,n,s=1,ans=0;
char** board;
set<int> blocks;

void eraseBlocks(){
	set<int>::iterator iter;
	for (iter = blocks.begin(); iter != blocks.end(); ++iter){
		int pos = *iter;
		int x = pos/n; int y = pos%n;
		board[x][y]='-';
   }
   
   	
			for(size_t i=0; i<m; ++i){
		for(size_t j=0; j<n; ++j)
			cout << board[i][j] << " ";
		cout <<endl;
	}
	cout <<endl;
	
   
   
   for(int i=0; i<n; ++i){
   		
		for(int j=m-1; j>0; --j){
   			if(board[j][i] == '-' ){
   					//		cout << "Å­¹È½¼"<<endl;

				int k = j-1;
			//	cout << j << " " << k <<endl;
				int l;
				while( k>=0 && board[k][i]=='-')
					--k;
				l=k;
				int m=0;	
			//	cout << k << " " << l <<endl;
				while( l>=0 && board[l][i]!='-'){
					
					board[j-m][i] = board[l][i];	
					board[l][i]='-';			   	
					--l; ++m;	
			//	cout << l << " " << m <<endl;

				}

		   }
		}
   }
   
   	
			for(size_t i=0; i<m; ++i){
		for(size_t j=0; j<n; ++j)
			cout << board[i][j] << " ";
		cout <<endl;
	}
	cout <<endl;
	
	
   blocks.clear();
   return;
}

void checkDumps(int x, int y, int dir){
	
	char c = board[x][y];
	if(!isalpha(c))  return;
	switch(dir){
		case 1 : {	
			if(	x < m-1 && board[x+1][y] == c) {
	//			cout << "go down" <<endl;
				checkDumps(x+1, y,2);
			}
			break;
		}
		case 2: {
			if( y < n-1 && board[x][y+1] == c) {
		//		cout << "go right" <<endl;
				checkDumps(x, y+1,3);
			}
			break;
		}
		case 3: {
			if( x > 0 && board[x-1][y] == c) {
				//find a dump
		//		cout << "find a dump" <<endl;
				++s;
				blocks.insert(x*n+y);
				blocks.insert((x-1)*n+y);
				blocks.insert(x*n+(y-1));
				blocks.insert((x-1)*n+(y-1));
			}
			break;
		}
		default :{
			break;
		}
	}
	return;
}


int main(){
	ifstream ifs;
	ifs.open("3.txt");
	ifs >> m >> n;
	
	board = new char*[m];
	for(size_t i=0; i<m; ++i){
		board[i] = new char[n];
		for(size_t j=0; j<n; ++j)
			ifs >> board[i][j];
	}
	
		cout <<endl;
	
			for(size_t i=0; i<m; ++i){
		for(size_t j=0; j<n; ++j)
			cout << board[i][j] << " ";
		cout <<endl;
	}
	cout <<endl;
	
	while(s!=0){
		
		
		s=0;
		for(size_t i=0; i< (m*n); ++i)
			checkDumps( i/n, i%n ,1);
		cout << blocks.size() <<endl;
		ans+=blocks.size();
		eraseBlocks();	
		cout << "s : "<<s <<endl;
	}

cout << "ans : " <<ans <<endl;	
	
	return 0;
	
}
