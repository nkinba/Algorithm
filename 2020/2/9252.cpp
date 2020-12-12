//https://www.acmicpc.net/problem/9252 (LCS2)
// 2차원 배열에 드 문자열의 해당 위치(i,j)에서의 LCS를 저장하는
// 메모리를 매우 많이 드는 방식...
//----------------------------------------------------------------- 
#include <iostream>
#include <string>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef pair<int, string> pis;

string str1, str2;
pis MAP[1001][1001];

void f(){
	FOR(i, 1, str1.size()){
		FOR(j, 1, str2.size()){
			if(str1[i-1] == str2[j-1])
				MAP[i][j] = pis( MAP[i-1][j-1].first + 1, MAP[i-1][j-1].second + str1[i-1]);
			else 
				MAP[i][j] = ( ( MAP[i-1][j].first >= MAP[i][j-1].first)
							? ( MAP[i-1][j])	
							: ( MAP[i][j-1] )
							);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	FOR(i, 0, 1000) fill(MAP[i], MAP[i]+1001, pis(0, "\n") );
	
	cin >> str1 >> str2;
	f();
	cout 
	<< MAP[str1.size()][str2.size()].first 
	<< MAP[str1.size()][str2.size()].second;

	return 0;
}
//----------------------------------------------------------------- 

// 훨씬 빠르고 메모리를 적게 차지하는 방식( 타 코드 참조)

 
