/* 욕심쟁이 판다 1937번 
	6872KB	96ms	C++14 	2872B
		
  시행 착오 : 1) 첫 시도는 대나무 크기와 좌표를 index 벡터에 저장한 후 크기를 기준으로 내림차순으로 정렬한 후,
  			  문제대로라면 마지막에 도착하게 될 큰 수부터 차례로 역 순으로 DFS를 진행하였다. 
			   DFS시 노드(좌표) 방문 기준은 현재 위치한 대나무 양보다 작느냐, 그리고 노드의 Cache 값(이동 수를 저장한 배열)
			  이  현재 위치의 Cache 값+1 (방문 시 +1)보다 작느냐 이다.  크거나 같으면 방문했을 시 똑같은 작업을 중복해서 
			  진행하므로 방문할 필요가 없다. 
			   마지막으로 Cache를 정렬하여 제일 높은 방문의 수를 출력하도록 하였다. 이 경우 시간초과가 떴다.
			   
			  2) 마지막 정렬 대신 전역변수를 사용해 최대값 갱신하는 방식 사용해도 시간 초과.
			  (자체 생성한 테스트 케이스 사용 시 많은 데이터에서는 이 방법이 더 빨랐다.)
			  
			  3) scanf, printf 사용했지만 조금 더 진행되고 시간 초과. 자체 테스트 케이스 사용 시에는 cin, cout 사용해도 시간이 얼마 안걸렸는데
			 알고리즘 상의 문제가 있는 것 같다. 입출력은 c언어 타입을 쓰기로 함. 
		
			  4) * 테스트 케이스를 1부터 250000 까지 순서대로 기입된 것을 썼더니 4초 가까이 걸리는 것을 확인. 
			  	 ex) 1 2 3 .... 500
			   	   501 502... 1000
			   (재귀가 굉장히 많이(->얼마나?) 호출될텐데 백만번 작업에 1초라고 치면 함수 단위에서 작업을 줄이던지 재귀 호출 수를 줄이던지 해야 할 것 같다.) 
			  
			  5) ※ 우선 index 벡터를 정렬한다 해놓고 정렬하지 않은 실수가 있었는데 이를 수정해도 시간초과가 났다.  
			 
			  6) * 테스트 케이스를 1부터 250000 까지 지그재그로 기입된 것을 썼더니 자체적으로는 메모리 터지는 것을 확인. 
				  ex) 1 2 3 .... 500
			   	  1000 999 998 ... 501  
			   	이 경우 재귀가 최대로 깊게 호출될 것.  메모리제한 256M, 재귀 깊이 최대 25만 이라고 치면 제출 시 메모리 부족할 일은 없어 보임
			   그리고 n이 150만 되도 3초가 넘어간다.	 
			   
			  7) 생각해보니 이런 식으로 해도 방문 했던 곳들을 재방문할 시 현재 step이 더 크면 진행해야 하니 비효율적일 수 밖에 없었다... 
			     
	==================================================================================================================================================			 
			 
	해 결 :	  8)  괜히 어렵게 생각하고 있었던 것 같다.  DFS(재귀호출) 방식을 사용하지 않고 큰 값부터 내림차순으로 노드 하나씩 사방을 탐색하면서 
			     캐시에 저장된 주변 노드의 움직임 횟수를 사용해 현재 노드의 움직임 횟수를 정하고 캐시에 저장함을 반복하면 해결될 일이었음.  
			    
			  9) 다른 사람의 코드를 보니 DFS를 사용하는게 더 빨랐다.(30ms대) 내가 작성한 함수에 비효율적인 부분이 있었던 것. 
			  	 동적 계획법을 사용할 때 기저를 설정하고 이를 반환 값으로 둔 다음에 사용해야 되는데 재귀 호출 전 마다 특정값을 결정해서
				 저장한 다음 호출된 함수에서 사용한 부분이 비효율적이 었던 것. 아래 함수에 표시. 
*/

#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

vector<pair<int, pii> > index;
int MAP[500][500];
int Cache[250000];
int n;

int rdir[4] = {-1,1,0,0};
int cdir[4] = {0,0,-1,1};

/* DFS를 사용한 함수 - 비효율적으로 짜여짐 */ 
//void DP(int r, int c, int val){  
//	
//	int steps = Cache[r*n+c];
//	for(size_t i=0; i<4; i++){	
//		int nextr = r+rdir[i]; int nextc = c+cdir[i]; // Check next region
//		
//		if(0<=nextr && nextr <= n-1 && 0 <= nextc && nextc <= n-1){  // In Range 
//			if(val > MAP[nextr][nextc]  && steps+1 > Cache[nextr*n+nextc]){  // 작아야지 갈 것
/*-----------잘못된 부분------------------------------------------------------*/
//				 Cache[nextr*n+nextc] = steps+1;							  
/*----------------------------------------------------------------------------*/
////				 if(steps+1 > MAX ) MAX = steps+1; 
////				 cout << r << ", " << c << "--> " << nextr << ", " << nextc << " -> next cache : " << Cache[nextr*n+nextc] <<endl;
//				 DP(nextr, nextc, MAP[nextr][nextc]);			
//			}		
//		}
//	}
//}

int DP(int r, int c, int val){
	
	int caches[4]={0,0,0,0};
	for(size_t i=0; i<4; i++){
		int nextr = r+rdir[i];
		int nextc = c+cdir[i];
		if(0<=nextr && nextr <= n-1 && 0 <= nextc && nextc <= n-1){ 
			if(MAP[nextr][nextc] > val) caches[i] = Cache[nextr*n+nextc];
		}
	}
	
	int MAX = max(max(caches[0], caches[1]), max(caches[2], caches[3]));
	if(MAX==0)	
		return 1;
	return MAX+1;
}

bool func(pair<int,pii> a, pair<int,pii> b){
	return a.first > b.first;
}
bool func2(int a, int b){
	return a>b;
}

void print_MAP(){
	printf( "================MAP=============================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", MAP[i][j]);
		printf("\n");
	}
	printf( "================================================\n");
}

void print_CACHE(){
	printf( "===============CACHE============================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			printf("%d ", Cache[i][j]);
		printf("\n");
	}	
	printf( "================================================\n");

}

int main(void){

//	ifstream ifs("1937tc.txt");
//	ifs >> n;
	scanf("%d", &n);

	index = vector<pair<int, pii> >(n*n);
	int p;
	
	fill(Cache, Cache+n*n, 0);

	for(size_t i=0; i<n; i++){  	// row		
		for(size_t j=0; j<n; j++){  // col
//			ifs >> p; 
			scanf("%d", &p);

		    MAP[i][j] = p;
		    index[i*n+j] = (make_pair(p , pii(i,j)));
		}
	}
	
//	ifs.close();

	sort(index.begin(), index.end(), func);

/*  DFS사용 방식 (시간 초과) 
	for(int i=0; i<n*n; i++){
		int r = index[i].second.first; 
		int c = index[i].second.second;
		if(Cache[r*n+c]==0){
			Cache[r*n+c]++;
			DP(r, c, index[i].first);
		}
	}
*/		

	for(int i=0; i<n*n; i++){
		int r = index[i].second.first; 
		int c = index[i].second.second;
		Cache[r*n+c] = DP(r, c, index[i].first);	// 큰 수(대나무) 부터  
	}

	
	sort(Cache, Cache+n*n, func2);
	printf("%d", Cache[0]); 
	
	return 0;
} 
