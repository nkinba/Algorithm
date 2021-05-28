#include <bits/stdc++.h>

using namespace std;

int N, sum=0;
int t[1000];

int main(){
	cin >> N;
	for(int i=0; i<N; i++) cin >> t[i];
	sort(t, t+N);
	for(int i=0; i<N; i++)
		sum += t[i]*(N-i);
	cout << sum;
	
	return 0;
}
