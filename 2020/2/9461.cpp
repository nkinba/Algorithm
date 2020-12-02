#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mem[101]={0,};

int T,N;

int main(){
	mem[0]=mem[1]=mem[2]=1;
	mem[3]=mem[4]=2;
	cin >> T;
	for(int t=0; t<T; t++){
		cin >> N;
		
		if(mem[N-1] !=0 ){
			cout << mem[N-1]<< "\n";
			continue;
		}
		
		for(size_t i=6; i<=N; i++)
			mem[i-1] = mem[i-6] + mem[i-2];

		cout << mem[N-1] << "\n";
	}
	return 0;
}
