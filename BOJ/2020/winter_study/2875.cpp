/* 	2875 대회 or 인턴  
	1980KB	0ms	C++14 358B
 	
 	여학생, 남학생, 필요 인턴 수가 주어지고 
	2명의 여학생, 1명의 남학생이 팀을 이뤄야 하는 와중에 전체에서 인턴 수만큼 빠져야 한다	
	이 때 구할 수 있는 최대 팀의 수를 구한다.	
	여학생, 남학생, 인턴 수의 경우에 따라 케이스를 나누어 해결  
		
 	https://www.acmicpc.net/problem/2875 
*/
#include <iostream>

using namespace std;

int main(){
	int W, M, K; // 여, 남, 인턴 수 
	cin >> W >> M >> K;
	
	int t = min(W/2, M); 
	int r = (W - t*2) + (M - t);
	
	if(r < K) {
		K -= r;
		int kn = K/3;	
		if(K%3 > 0)		
			 t -= (kn+1);
		else t -= kn;
		if(t<=0) t = 0;	
	}
	
	cout << t;	
		
	return 0;
	
} 
