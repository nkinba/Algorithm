// 팩토리얼을 구하는 문제  

#include <bits/stdc++.h>

using namespace std; 

int f(int i){
	return (i==0) ? 1 : (i*(i==1 ? 1 : f(i-1)));
}

int main(){
	int i;
	cin >> i;
	cout << f(i);
	return 0;
}
