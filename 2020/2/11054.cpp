#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000];
int fr[1000];
int re[1000];

int main(){
	cin >> N;
	fill_n(fr, N, 1);
	fill_n(re, N, 1);
	
	for(size_t i=0;i<N;i++) cin >> A[i];
	//fr
	for(size_t i=0;i<N;i++) {
		for(ssize_t j=i-1; j>=0; j--){
			if(A[j]<A[i] && fr[j]+1 > fr[i])
				fr[i] = fr[j]+1;
		}
	}
	//re
	for(ssize_t i=N-1; i>=0; i--) {
		for(size_t j=i+1; j<N; j++){
			if(A[j]<A[i] && re[j]+1 > re[i])
				re[i] = re[j]+1;
		}
	}

	for(size_t i=0; i<N; i++)
		fr[i] += re[i];
	sort(fr, fr+N);
	cout << fr[N-1]-1;
	
	return 0;
}
