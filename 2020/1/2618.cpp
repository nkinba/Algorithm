// https://www.acmicpc.net/problem/2618
//	25556KB	56ms (20201206)

#include <iostream>
#include <cmath>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

#define r first
#define c second

#define val first
#define next second

#define MAX 1<<20

using namespace std;

typedef pair<int,int> pii;

int N, W, c, n;

// [current Index] : 1 ~ 1000(N) + 2 (1,2는 경찰차 1,2의 초기 위치) 
// [other Car] : 현 위치 외 다른 곳에 위치한 경찰차 번호(1 or 2) 
// [other Index] : 1 ~ 999(N-1) + 2 (other Car가 위치한 사건 인덱스) 
// first(val) : Mininum Distance, 
// second(next) : 다음 사건을 처리할 경찰차 번호 (1 or 2)
pii sel[1001 + 2][3][1000 + 2]; 

// 좌표  
pii p[1001 + 2];

	// 현 위치,  다른 위치의 차번호,  그 차의 위치. 
pii getMin(int curPos, int another, int anotherPos){
	if(curPos == W + 2) {
		sel[curPos][another][anotherPos] = pii(0,-1);
		return pii(0, -1);
	}
	
	int cur;
	int nextCar;
	int restDist, thisDist;
	
	cur = ( (another == 1) ? 2 : 1 );
	
	pii& rst = sel[curPos][another][anotherPos];
	if(rst.val) return rst;
	
	restDist = MAX;
	FOR(car, 1, 2){
		pii stepResult = getMin( curPos + 1, 
								 ( (car == cur) ? another : cur ),
								 ( (car == cur) ? anotherPos : curPos ) 
								); 
		
		thisDist = ( ( car == cur) 
					?( abs( p[curPos].r - p[curPos+1].r) + abs( p[curPos].c - p[curPos+1].c) )
					:( abs( p[anotherPos].r - p[curPos+1].r) + abs( p[anotherPos].c - p[curPos+1].c)));
	
		if(restDist  > stepResult.val + thisDist ){
			restDist = stepResult.val + thisDist;
			nextCar = car;
		};	
	}
	
	rst = pii(restDist, nextCar);
	return rst;
}

  
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> W;
	
	p[1] = pii(1, 1);
	p[2] = pii(N, N);
	FOR(i, 3, W+2) 
		cin >> p[i].r >> p[i].c;
		
	cout << getMin(2,1,1).val << '\n';	
	 
	int now = 2 , another = 1,  anotherPos = 1; 
	pii checkPoint = sel[now][another][anotherPos];
	
	while(checkPoint.next != -1){
		int nextCheck = checkPoint.next;
		cout << nextCheck << '\n';
		if(another == nextCheck){
			another = ((another == 1) ? 2 : 1);
			anotherPos = now;
		}
		now++;
		checkPoint = sel[now][another][anotherPos];
	}
 
	return 0;
}
