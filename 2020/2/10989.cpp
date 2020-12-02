#include <bits/stdc++.h>

using namespace std;

int dat[10000];

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n,inp; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> inp;
		dat[inp-1]++;
	}
	
	for(int i=0; i<10000; i++){
		for(int j=0; j<dat[i]; j++)
			cout << i+1 << "\n"; 
	}
	
	return 0;
}
