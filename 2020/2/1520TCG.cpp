#include <bits/stdc++.h>

using namespace std;

int main(){
	ofstream ofs("1520TC.txt");
	int M,N;
	cin >> M >> N;
	ofs << M << " " << N <<endl;
	srand((unsigned int)time(NULL));
	int n=10000;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			ofs << rand()%n << " ";
		ofs << endl;
		n /= 10;
		if(n==1) n=10000;
	}
	ofs.close();
	return 0;
}
