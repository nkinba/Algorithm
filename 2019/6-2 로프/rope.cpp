#include <iostream>
//#include <cstdlib>
#include <algorithm>
using namespace std;

int cmp(const void* a, const void* b){
	int n =*(int*)a;  int m=*(int*)b;
	if(n>m) return 1;
	else if(n<m) return -1;
	else return 0;
}

int main(void){
	int n,max=0;
	cin >> n;
	int ropes[n];
	for(size_t i=0; i<n; i++) cin >> ropes[i];
	qsort(ropes, n , sizeof(int), cmp );
		
	for(size_t i=0; i<n; i++){
		int cnt = n-i;
		if(max < ropes[i]*cnt) max = ropes[i]*cnt;
	}

	cout << max;
	return 0;
}

