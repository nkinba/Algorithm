/* 9237 이장님 초대
2376KB	12ms	C++14 	445B
https://www.acmicpc.net/problem/9237 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);cin.tie(0); // 사용 시 시간 대폭 감소 
	int n,d,m=0;
	cin >> n;
	vector<int> v(n);
	for(size_t i=0; i<n; i++){
		cin >> d; 
		v[i] = d;
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<n; i++){
		m = max(m, v[i]+i);
	}
	cout << m+2;
	return 0;
} 
