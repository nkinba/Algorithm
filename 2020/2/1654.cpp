// Parametric Search  : 최적화 문제(최적값) -> 결정 문제(Yes Or No) 

#include <iostream>
#include <algorithm>

using namespace std;

int K,N;
int LANS[10000];

int bs(){
	long long b = 1;
	long long e = LANS[K-1];
	long long m;
	long long cnt;
	while(b <= e){
		cnt = 0;
		m = (b+e)/2;
		cout << b << "  "<< m << "  "<<e  <<endl;
		for(size_t i=0; i<K; i++)
			cnt += (LANS[i]/m);	
		cout << cnt <<endl;
		if(cnt >= N) b = m+1; // YES
		else e = m-1; // NO
	}
	return e;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> K >> N;
	for(size_t i=0; i<K; i++) cin >> LANS[i];
	
	sort(LANS, LANS+K);
	cout << bs();
	
	return 0;
}
