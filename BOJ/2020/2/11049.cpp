#include <bits/stdc++.h>

#define r first
#define c second

using namespace std;

typedef pair<int,int> matrix;

int mul[500][500]={{0,},};
int N,r,c;
int b,e,m,len;
matrix mat[500];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(size_t i=0; i<N; i++)
		cin >> mat[i].r >> mat[i].c;
	
	for(len = 1; len < N; len++){
		for(b = 0; b + len < N; b++){
			e = b + len;
			mul[b][e] = INT_MAX;
			for(m = b; m < e; m++)
				mul[b][e] = min(mul[b][e], mul[b][m] + mul[m+1][e] + mat[b].r * mat[m].c * mat[e].c);
		}
	}

	cout << mul[0][N-1];
	return 0;
}

