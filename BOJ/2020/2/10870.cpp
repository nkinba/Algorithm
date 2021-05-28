// i번째 피보나치 수를 구한다. 

#include <bits/stdc++.h>

using namespace std;

int f(int i){
	int ret;
	if(i==0) ret = 0; 
	else if(i==1) ret = 1;
	else ret = f(i-1)+f(i-2);
	return ret;
}

int main(){
	int i;
	cin >> i;
	cout << f(i);
	return 0;
}
