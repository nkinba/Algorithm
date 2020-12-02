#include <bits/stdc++.h>

using namespace std;

int N;
int mem[1000001];

void f(int n, int c){
	mem[n] = c;
	
	if(n == 1)
		return;
	
	if(n%2==0 && c+1 < mem[n/2])
		f(n/2, c+1);
	
	if(n%3==0 && c+1 < mem[n/3])
		f(n/3, c+1);
	
	if(n > 1 && c+1 < mem[n-1])
		f(n-1, c+1);
}

int main(){
	cin >> N;
	fill(mem, mem+N+1, 1000001);
	f(N,0);
	cout << mem[1];
	return 0;
}
