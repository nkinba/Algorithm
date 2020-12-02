#include <bits/stdc++.h>

using namespace std;

int n;
int glass[10000];
int mem[10000] = {0,};

int main(){
	cin >> n;
	for(size_t i=0; i<n; i++) cin >> glass[i];
	
	mem[0] = glass[0];
	mem[1] = glass[0]+glass[1];
	int arr[3] = {glass[0]+glass[1],
				  glass[0]+glass[2],
				  glass[1]+glass[2]}
	mem[2] = *max_element(arr, arr+3);
	
	for(size_t i=3; i<n; i++)
		mem[i] = max(max( 
						glass[i] + mem[i-2],
						glass[i] + glass[i-1] + mem[i-3]),
						mem[i-1]
					);

//	sort(mem, mem+n);
	cout << mem[n-1];
	
	return 0;
}
