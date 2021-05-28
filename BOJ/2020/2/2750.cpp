#include <bits/stdc++.h>

using namespace std;

int dat[1000];

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> dat[i];
	sort(dat, dat+n);
	for(int i=0; i<n; i++) cout << dat[i] << "\n";	
	return 0;
}
