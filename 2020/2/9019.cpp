// 실수를 줄이기 위해 코드를 좀 꼼곰히 보자.
// 런타임 에러날 수 있는 경우?
// 배열 범위 벗어난 인자 넘길경우 (ex. arr[N] => fill(arr, arr+N+1, val) )
// 함수 반환 타입이 void가 아닌데 return 값을 선언하지 않은 경우,
// 현 환경(devc++, TDM-GCC 4.9.2 64bit) 에서는 인자타입과 반환타입이 같으면
// 그대로 반환하는지? 에러가 발생하지 않지만 원래는 syntax error가 발생한다.
 
// 목적지에 도달하지 못하는 경우가 없는 bfs에서는  while의 탈출조건을
// 조건문에 명시할 필요가 없다. while(true) 사용. 

#include <cstdio>
#include <stack>
#include <queue>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef int(*func)(int);

int T, A, B, curRegVal;
char visited[10000];  // 10M
int preRegVal[10000]; // 40M
stack<char> funcStk;

int D(int reg){
	reg = reg* 2 % 10000;
	return reg;
}

int S(int reg){
	reg = ((reg > 0) ? (reg - 1) : 9999); 
	return reg;
}

int L(int reg){
	reg = (reg % 1000 * 10) + (reg / 1000);
	return reg;
}

int R(int reg){
	reg = ( reg / 10) + ( reg % 10 * 1000 );
	return reg;
}

func calc[4] = {D, S, L, R};
char funcName[4] = {'D', 'S', 'L', 'R'};

void bfs(){
	queue<int> regQ;
	
	regQ.push(A);
	visited[A] = 'X';
	
	while(true){
		curRegVal = regQ.front();
		regQ.pop();
		
		FOR(f, 0, 3){
			int nextRegVal = calc[f](curRegVal);
			if(visited[nextRegVal] == '-'){
				regQ.push(nextRegVal);
				preRegVal[nextRegVal] = curRegVal;
				visited[nextRegVal] = funcName[f];
				if(nextRegVal == B) return;
			}
		}
	}
	
	return;
}

int main(void){
	
	scanf("%d", &T);
	FOR(t, 0, T-1){
		fill(visited, visited+10000, '-');
		fill(preRegVal, preRegVal+10000, -1);
		scanf("%d", &A);
		scanf("%d", &B);
		
		bfs();
		
		curRegVal = B;
		while(curRegVal != A){
			funcStk.push(visited[curRegVal]);
			curRegVal = preRegVal[curRegVal];
		}
		
		while(!funcStk.empty()){
			printf("%c", funcStk.top());
			funcStk.pop();
		}
		printf("\n");
	}

	return 0;
}

