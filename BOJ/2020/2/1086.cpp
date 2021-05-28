#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define REVFOR(i,e,b) for(int i=e; i>=b; i--)

using namespace std;
typedef long long int ll;

//필요한 것:
// 각 수(길이가 50까지이기에 string이 필요하다) 를 K로 나누었을 때 나머지,
// 각 수의 자릿수 
// dp[i][visited] 
// : 현재 고른 수의 상태가 visited 일 때,
//   현재까지 나머지가 i일 때 나누어지는 케이스의 개수 
  
int N, K;
int visited = 0;
string nums[16];
int numRmdr[16];
int tenRmdr[51];

ll dp[100][(1<<15)-1];
int nextRest; 
 
ll answer = 0;

int getRmdr(string num){
	int rst = 0;
	FOR(i, 0, num.size()-1)
		rst = (rst*10 + (int)((num[i])-'0')) % K;

	return rst;
}

int getNextRmdr(int curRest, int next){
	return	(curRest * tenRmdr[nums[next].length()] + numRmdr[next] ) % K;
}

ll getDivs(int curRmdr){
	if(visited == ((1<<N)-1) ) return (curRmdr == 0);

	ll& rst = dp[curRmdr][visited];
	if(rst != -1) 
		return rst;
	
	rst = 0; 
	FOR(next, 1, N){
		if((visited & (1 << (next-1))) == 0){
			visited |= ((1 << (next-1)));
			nextRest = getNextRmdr(curRmdr, next);
			rst += getDivs(nextRest);
			visited ^= ((1 << (next-1)));
		}
	}
	return rst;
}


ll gcd(ll a, ll b) {

  while (b != 0) {
    ll temp = a % b;
    a = b;
    b = temp;
  }

  return abs(a);
}

void printAnswer(){
	if(answer == 0) {
		cout << "0/1";
		return;
	}
	
	ll divisor = 1;
	FOR(i, 1, N) divisor *= i;
	if(answer == divisor) cout << "1/1";
	else {
	  ll gcd_result = gcd(answer, divisor);
	
	  answer /= gcd_result;
	  divisor /= gcd_result;
	
	  cout << answer << "/" << divisor;
	}
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	FOR(i,1,N)
		cin >> nums[i];	
	cin >> K;
	
	FOR(i,1,N) numRmdr[i] = getRmdr(nums[i]);

	tenRmdr[0] = 1;
	FOR(i, 1, 50) tenRmdr[i] = tenRmdr[i-1] * 10 % K;
	FOR(i, 0, K-1) fill(dp[i], dp[i]+(1<<N), -1);

	answer = getDivs(0);
	
	printAnswer();
	
	return 0;
}

