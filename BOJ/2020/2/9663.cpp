#include <bits/stdc++.h>

#define R first
#define C second

using namespace std;

typedef pair<int,int> pii;

vector<pii> queens(15);

int n,cnt=0;

bool check(int r, int c){
	for(size_t i=0; i<r; i++){
		int qr = queens[i].R;
		int qc = queens[i].C;
		
		if( qc == c || (qr-qc == r-c) || (qr+qc == r+c) )
			return false;
	}
	return true;
}

void f(int r){
	if(r == n){
		cnt++;
		return;
	}
	
	for(size_t i=0; i<n; i++){
		if(check(r,i)){
			queens[r] = pii(r,i);
			f(r+1);
		}
	}
}

int main(void){
	cin >> n;
	f(0);	
	cout<<cnt;
	return 0;
}
