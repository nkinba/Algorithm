/* 	1931 회의실 배정
	2764KB	32ms	C++14	
	
	시간이 주어진 회의들을 겹치지 않게 최대로 배치하는 문제.
	 
	정렬 시 끝나는 시간을 오름차순, 같을 시 시작시간 오름차순으로 수행함. 
	회의 시작 시간이 이전 회의의 끝나는 시간보다 같거나 크면 된다.  
	
	시작시간 우선으로 오름차순 정렬한 코드도 시간이 똑같이 걸린다.  (처리를 여러 가지 경우로 나눠야함) 
	
	https://www.acmicpc.net/problem/1931 
*/

#include <iostream>
#include <algorithm>

#define b first
#define e second

using namespace std;
typedef pair<int,int> pii;
pii data[100000] ;
int n;

bool func(pii x, pii y){
	if(x.e < y.e) return true;
	else if(x.e == y.e) return x.b < y.b;
	return false;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int b,e;
	int m = 1;  // 최대 회의 수 
	cin >> n;
	
	for(size_t i=0; i<n; i++){
		cin >> b >> e;
		data[i] = pii(b,e);
	}
			
	if(n==1){
		cout << 1;
		return 0;
	}
		
	sort(data, data+n, func); // 시간 값들을 정렬  
	
	int ep = data[0].e;
	for(size_t i=1; i<n; i++){
		if(data[i].b >= ep){	
			m++;
			ep = data[i].e;
		}
	}
	cout << m;
	
	return 0;
}
