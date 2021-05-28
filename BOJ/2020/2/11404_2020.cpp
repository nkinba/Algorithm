#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<e; i++)
#define MAX 10000001

using namespace std;

int n,m,a,b,c;
int Cost[101][101];

void fw(){
	FOR(i, 1, n+1){
		FOR(j, 1, n+1){
			FOR(k, 1, n+1)
				Cost[j][k] = min(Cost[j][k], Cost[j][i]+Cost[i][k]);
		}
	}

	FOR(i, 1, n+1){
		FOR(j, 1, n+1)
			cout << ((Cost[i][j] == MAX) ? 0 : Cost[i][j] )  << " ";
		cout <<endl;
	}
} 

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	FOR(i, 1, n+1){
		FOR(j, 1, n+1)
			Cost[i][j] = ( (i==j) ? 0 : MAX );
	}
	
	FOR(i, 0, m){
		cin >> a >> b >> c;
		Cost[a][b] = min(Cost[a][b], c);
	}
	
	fw();

	return 0;
}
