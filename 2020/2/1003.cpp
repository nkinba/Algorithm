#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
 
int T,N;

pii mem[41] = {pii(0,0),};

void fn(int N){
	if(mem[N] != pii(0,0)) return;

	mem[1]=pii(0,1);
	mem[0]=pii(1,0);
	
	for(size_t i=2; i<=N; i++){
		mem[i].first = mem[i-1].first + mem[i-2].first;
		mem[i].second = mem[i-1].second + mem[i-2].second;			
	}
}

int main(){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		fn(N);
		cout << mem[N].first << " " << mem[N].second << "\n";
	}
	return 0;
}
