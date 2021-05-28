#include <bits/stdc++.h>

using namespace std;

int n=0;
int inp;
char* m;

void print(){
	for(int i=0; i<inp; i++){
		for(int j=0; j<inp; j++)
			cout << m[i*inp+j];
		cout <<endl;
	}
}

void f(int x, int y, int n){
	if(n<3) return;

	int r = n/3;
	
	for(int i = x+r; i <= x+r*2-1; i++){
		for(int j = y+r; j <= y+r*2-1; j++){	
			m[i*inp+j]=' ';
		}
	}
	
	for(int i=0; i <= 2; i++){
		for(int j=0; j <= 2; j++){
			f(x+n/3*i, y+n/3*j, n/3);
		}
	}

}

int main(){
	cin >> inp;
	m = new char[inp*inp];
	fill(m, m+inp*inp, '*');
	f(0, 0, inp);
	print();
	return 0;	
}
