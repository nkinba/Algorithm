#include <bits/stdc++.h>

using namespace std;

int N, M, b, e;
int inp[100001];
int partSums[100001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++) {
		cin >> inp[i];
		partSums[i] = partSums[i-1] + inp[i];
	} 
	for(int i=1; i<=M; i++){
		cin >> b >> e;
		cout << partSums[e] - partSums[b-1] << '\n';
	}

	return 0;
}
