#include <iostream>
#include <algorithm>

using namespace std;
void print(int* a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] <<" ";
	cout <<endl;
	return ;	
}

int main(void){
	int* a= new int [10];
	int* b= new int [10];
	copy(a, a+10,b);
	print(b,10);
	
	return 0;
}
