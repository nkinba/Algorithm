#include <bits/stdc++.h>

using namespace std;

int A[100][100];
int N,M,K,v;
int ans[100][100]={{0,},};

int main(void){
	 cin >> N >> M;
	 for(int i=0; i<N; i++){
	 	for(int j=0; j<M; j++)
	 		cin >> A[i][j];
	 }	
	 cin >> M >> K;
	 for(int i=0; i<M; i++){
	 	for(int j=0; j<K; j++){
	 		cin >> v;
			for(int k=0; k<N; k++)
				ans[k][j]+=(A[k][i] * v);	
		 }
	 }
	
	 for(int i=0; i<N; i++){
	 	for(int j=0; j<K; j++)
	 		cout << ans[i][j] << " ";
		cout << '\n'; 
	 }
}
