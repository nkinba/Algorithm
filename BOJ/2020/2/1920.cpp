#include <iostream>
#include <algorithm>

using namespace std;

int N,M,n;
int A[100000];

void bs(int n){
	int b = 0;
	int e = N-1;
	int m;
	if((n < A[b]) || (A[e] < n)) {
		printf("0\n");
		return;	
	}
	while(b <= e){
//		m = (b+e)/2;
		m = b + (e-b)/2;
		if(A[m] == n){
			printf("1\n");
			return;	
		} 
		else if(A[m] > n) e = m - 1;
		else b = m + 1;   
	}
	printf("0\n");
	return;	
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) 	scanf("%d", A+i);
	scanf("%d", &M);

	sort(A, A+N);

	for(int i=0; i<M; i++){
		scanf("%d", &n);
//		1742ms, 통과	
//		printf("%d\n",(find(A, A+N, n) != A+N)); 
		

//		직접 binary Search 를 짜서 하니 자꾸 16%에서 시간초과가 발생 
//		for문 돌때마다 sort를 호출한 실수 
//		68ms
		bs(n);
				
	}		
	
	return 0;
}

// algorithm 헤더 lower / upper bound 
/*
   for (int i = 0; i < M; ++i) {
      // 값이 [a, b] 범위에 있는 데이터의 개수 계산
      if (countByRange(v1, v2[i], v2[i]) != 0)
         cout << "1"<< '\n';
      else
         cout << "0" << '\n';
   }	
   
   // 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
	int countByRange(vector<int>& v, int leftValue, int rightValue) {
	   vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	   vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	
	   return rightIndex - leftIndex;
	}
*/
