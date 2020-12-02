#include <iostream>
#include <bitset>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr1[n]; int arr2[n]; int mat[n];
		
	for(int i=0 ; i<n; ++i)
		cin >> arr1[i];
	for(int i=0 ; i<n; ++i)
		cin >> arr2[i];
	for(size_t i=0; i<n; ++i){
		mat[i] = arr1[i] | arr2[i];
	//	cout << bitset<16>(mat[i]) <<endl;
		for(int j=n-1; j>=0; --j)
			(( ((1<<j) & mat[i])>>j) == 1 ) ? (cout << "#") : (cout << "0" ) ;
		cout << endl;
	}

//5
//9 20 28 18 11
//30 1 21 17 28
	return 0;
}
