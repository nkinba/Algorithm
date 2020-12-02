#include <iostream>

using namespace std;

typedef int val_t;  
typedef int mat[7][7];

mat m;

void set(){
	size_t  r,c;
	for(r=0; r<7; ++r){
		for(c=0; c<7; ++c){
			if(r==0 || c==0) m[r][c]=1;
			else{ m[r][c]= m[r-1][c] + m[r][c-1];}
		}
	}
} 

int main(void){
	set();
	for(size_t r=0; r<7; ++r){
		for(size_t c=0; c<7; ++c){
			cout << m[r][c] << '\t';
			if(c%7==6) cout <<endl;
		}
	}
	return 0;
}
