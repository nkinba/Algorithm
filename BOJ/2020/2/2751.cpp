#include <bits/stdc++.h>

using namespace std;

int dat[1000000];

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> dat[i];
	sort(dat, dat+n);
	for(int i=0; i<n; i++) cout << dat[i] << "\n";	
	return 0;
}
