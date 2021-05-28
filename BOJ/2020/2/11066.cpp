//11066 파일합치기
// 2996KB 136ms 
//...
// Knuth Optimization을 사용하여 O(N^3) 을 O(N^2)으로 줄일 수 있다.
// 

 
#include <bits/stdc++.h>

using namespace std;

int T,K;
int b, mid, e, len;

int chaps; 
int partSums[500];
int dp[500][500];
int KnuthRange[500][500];

int main(void){
	cin >> T;
	for(size_t t=0; t<T; t++){
		
		cin >> K;
		for(size_t i=0; i<K; i++){
			cin >> chaps;
			(i > 0) ? 
			(partSums[i]= (chaps + partSums[i-1])) :
			(partSums[i]= chaps);
		}

// 		O(N^3) 	
//		for(len = 1; len < K; len++){
//			for(b = 0; b + len < K; b++){
//				e = b + len;
//				dp[b][e] = INT_MAX;
//				for(mid = b; mid < e; mid++){
//					int partSum = ( (b==0)
//								  ? (partSums[e])
//								  : (partSums[e] - partSums[b-1]) );
//					dp[b][e] = 
//						min(dp[b][e], 
//						    dp[b][mid] + dp[mid+1][e] + partSum);										
//				}
//			}	
//		}

		
//		O(N^2) Knuth Optimization 
		for(size_t i=0; i<K; i++)
			KnuthRange[i][i]=i;
		
		for(len = 1; len < K; len++){
			for(b = 0; b + len < K; b++){
				e = b + len;
				dp[b][e] = INT_MAX;
//				for(mid = b; mid < e; mid++){					 		  
				for(mid = KnuthRange[b][e-1]; mid <= KnuthRange[b+1][e]; mid++){
					int partSum = ( (b==0)
								  ? (partSums[e])
								  : (partSums[e] - partSums[b-1]) );
								  
//					dp[b][e] = 
//						min(dp[b][e], 
//						    dp[b][mid] + dp[mid+1][e] + partSum);						
					int result = dp[b][mid] + dp[mid+1][e] + partSum;
					if(dp[b][e] > result){
						dp[b][e] = result;
						KnuthRange[b][e] = mid;
					}											
				}
			}	
		}	
		cout << dp[0][K-1]<<'\n';
	}
	
	return 0;
}

