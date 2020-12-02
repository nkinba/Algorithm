#include <bits/stdc++.h>

#define W first
#define V second

using namespace std;

typedef pair<int,int> pii;

int N,K;
pii WVPairs[101];
int maxV[101][100001];

//void print(){
//	for(size_t i=1; i<=N; i++){
//		for(size_t j=1; j<=K; j++){
//			cout << maxV[i][j] << " ";
//		}
//		cout <<endl;
//	}
//}

int main(){
	cin >> N >> K;
	for(int i=0; i<=N; i++)
		fill_n(maxV[i], K+1, 0);

	for(size_t i=1; i<=N; i++) 
		cin >> WVPairs[i].W >> WVPairs[i].V;
	
	for(size_t i=1; i<=N; i++){
		for(size_t j=1; j<=K; j++){
			if(j >= WVPairs[i].W)
				maxV[i][j] = max( maxV[i-1][j-WVPairs[i].W] + WVPairs[i].V,
							      maxV[i-1][j]);
			else
				maxV[i][j] = maxV[i-1][j];
		}
	}
	
	cout << maxV[N][K];
	
//	print();
	return 0;
}
