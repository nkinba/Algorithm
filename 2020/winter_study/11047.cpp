/*  11047 동전 0 
	1984KB	0ms	C++14
  	
	가치가 주어진 동전들로 최소한을 사용해 정해진 값을 채운다. 
	그리디 알고리즘 사용  
	
	https://www.acmicpc.net/problem/11047 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int M[10];
int P,N;

int main(void){
	int ans = 1<<30;
	cin >> N >> P;  // 동전 수와 정해진 값  
	for(int i=0; i<N; i++)
		cin >> M[i]; // 동전의 가치들 
	
	for(int i=0; i<N; i++){
		int a = 0;
		int p = P;
		for(int j=i; j>=0; j--){
			a += p/M[j];
			p = p%M[j];
		}
		ans = min(ans, a);	
	}
	
	cout << ans;
	return 0;
}
