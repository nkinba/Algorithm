/* 11404 플로이드
2024KB	92ms	C++14 

플로이드 와샬 알고리즘 구현 문제
*/
 
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int Answer[101][101];
int INF = 1<<20;

int main(void){
	int f,t,c;
	cin >> n >> m;
	
	for(size_t i=1; i<=n; i++){
		for(size_t j=1; j<=n; j++){
			if(i==j) Answer[i][j] = 0;
			else Answer[i][j] = INF;
		}
	}
	
	for(size_t i=0; i<m; i++){
		cin >> f >> t >> c;
 		Answer[f][t] = min(Answer[f][t], c);
	}


	for(size_t i=1; i<=n; i++){
		for(size_t j=1; j<=n; j++){
			for(size_t k=1; k<=n; k++){
				Answer[j][k] = min(Answer[j][k], Answer[j][i]+Answer[i][k]);
			}
		}
	}

	for(size_t i=1; i<=n; i++){
		for(size_t j=1; j<=n; j++)
			cout << Answer[i][j]%INF << " ";
		cout <<endl;
	}
	
	return 0;
}
