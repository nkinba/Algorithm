#include <iostream>

using namespace std;

int N,M;
char p[15];

void f(int idx){
	
	if(idx == M){
		 p[idx*2-1]='\n';
		 cout << p;
		 return;
	}
		
	for(size_t i=0; i<N; i++){
		p[idx*2]=(i+1)+'0';
		p[idx*2+1]=' ';
		f(idx+1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	f(0);
	return 0;
}
