#include <iostream>

using namespace std;

int main(void){
	int n,
	cnt=0;
	cin
	>> n;
	if
        (n%2==1){
		++cnt;

		n=(n/2)-1;
	}

	while(n!=2){

		n=(n/2);

		++cnt;
	}
	cout << cnt;

	return 0;
}
