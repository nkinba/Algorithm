#include <bits/stdc++.h>

using namespace std;

int N,M;
int pmt[8];
bool vst[8];

void print(){
	for(size_t i=0; i<M; i++) 
		cout << pmt[i] << " ";
	cout <<'\n';
}

void f(int idx){
	
	size_t i;
	for(i=0; i<N; i++){
		if(vst[i] == false){
			vst[i] = true;
			pmt[idx] = i+1;
			if(idx == M-1)
				print();
			else
				f(idx+1);
			vst[i]= false;	
		}
	}
	
	return;
}


int main(){
	cin >> N >> M;
	fill(vst, vst+8, false);
	
	f(0);
	return 0;
}
