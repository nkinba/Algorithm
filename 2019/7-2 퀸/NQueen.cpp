#include <iostream>
#include <vector>

using namespace std; 

typedef vector<int> row;

int N;

bool final(row& pos){
	for(size_t i=0; i<N; i++){
		if(pos[i]!=N-1) return false;	
	}
	return true;
}

void fill(vector<row>& mat, int r, int c){
	for(size_t i=0; i<N; ++i){
		for(size_t j=0; j<N; ++j){
			if(i==r && mat[i][j]==0) mat[i][j]=r+1;
			if(j==c && mat[i][j]==0) mat[i][j]=r+1;
			if((i-j)==(r-c) && mat[i][j]==0) mat[i][j]=r+1;
			if((j+i)==(c+r) && mat[i][j]==0) mat[i][j]=r+1;
		}
	}
	return;
}

void erase(vector<row>& mat, int r, int c){
	for(size_t i=0; i<N; ++i){
		for(size_t j=0; j<N; ++j){
			if(i==r && mat[i][j]==r+1) mat[i][j]=0;
			if(j==c && mat[i][j]==r+1) mat[i][j]=0;
			if((i-j)==(r-c) && mat[i][j]==r+1) mat[i][j]=0;
			if((j+i)==(c+r) && mat[i][j]==r+1) mat[i][j]=0;
		}
	}
	return;	
}

//void clear(vector<row>& mat){
//	for(size_t i=0; i<N; ++i)
//		mat[i].fill(0);
//	return;
//}

int process(vector<row>& mat){
	int s=0;
	int curPos=0;
	row pos(N);
	while(pos[0]!=N){
		while(curPos<N){
			size_t i;
			for(i=pos[curPos]; i<N; ++i)	{
				if(mat[curPos][i] == 0){
					fill(mat, curPos, i);
					pos[curPos]=i;
				//	cout << "curPos : "<<curPos << " i : " << i <<endl;	
					++curPos; 
					break;
				}
			}
			if(i>=N){
				pos[curPos]=0;
				--curPos;
				erase(mat, curPos, pos[curPos]);
				++pos[curPos];	
			}
			if(pos[0]==N) return s;
		}
		++s;
		erase(mat, --curPos, pos[curPos]);
		pos[curPos] = (pos[curPos]+1);
//		cout << "s : "<< s << " curPos : " << curPos << " pos[curPos] : " <<pos[curPos] <<endl;
	}
	return s;
}

int main(void){
	cin >> N;
	vector<row> mat(N);	
	for(row& r : mat)
		r = vector<int>(N);
	
	cout << process(mat);
	
	return 0;
}
