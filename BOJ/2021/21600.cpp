#include <bits/stdc++.h>

using namespace std;

int N, H;
int maxH[100000] = {1,};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> H;
	for(size_t i=1; i < N; i++){
		cin >> H;
		if(H <= maxH[i-1]) {
			maxH[i] = H;
			continue;
		} 
		maxH[i] = maxH[i-1]+1;
	}
	
	sort(maxH, maxH+N);
	cout << maxH[N-1];
	
	return 0;
}

