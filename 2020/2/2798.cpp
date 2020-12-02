#include <bits/stdc++.h>

using namespace std;

int N,M,ans=0;
vector<int> inps;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> N >> M;

	inps = vector<int>(N);	
	
	for(size_t i=0; i<N; i++)
		cin >> inps[i];
	
	for(size_t i=0; i<N; i++){
		for(size_t j=i+1; j<N; j++){
			for(size_t k=j+1; k<N; k++){
				int sum = inps[i] + inps[j] + inps[k];
				if(sum <= M) ans = max(ans, sum); 
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
