#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int m, Q, n, x, fRet;
int** fResultTable;

void setfResultTable(){
	FOR(j, 1, 19){
		FOR(i, 1, m)
			fResultTable[i][j] = fResultTable[ fResultTable[i][j-1] ][j-1];
	}			                                          
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m;
	
	fResultTable = new int*[m+1];
	FOR(i, 1, m) 
		fResultTable[i] = new int[20]; 
	
	FOR(i, 1, m) {
		cin >> fRet;
		fResultTable[i][0] = fRet;
	} 
	
	setfResultTable();
	
	cin >> Q;
	
	FOR(i, 1, Q){
		cin >> n >> x;
		for(int jump = 0; n > 0; jump++){
			if(n & 1) 
				x = fResultTable[x][jump];
			n >>= 1;	
		}
		cout << x << '\n';
	}
	
//	FOR(i, 1, m){
//		FOR(j, 0, 19)
//			cout << fResultTable[i][j] << " ";
//		cout <<endl;
//	}
	
	delete[] fResultTable; 
	
	return 0;
}
