//dp[n+1] = sigma(k=0~n) (nCk * dp[n-k]);

#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef long long ll;

int N, M, a, b, S;
int parents[5001];
ll dp[5001];
ll cnt = 0;
ll fact[5001], factInv[5001];
ll mod = 1000000007; 

int findRoot(int cur){
	if(parents[cur] == cur) return cur;
	return parents[cur] = findRoot(parents[cur]);
}

int uni(int a, int b){
	int aR = findRoot(a);
	int bR = findRoot(b);
	if(aR == bR) return 0;
	
	(aR > bR) ? (parents[aR] = bR) : (parents[bR] = aR);

	S--;
	return 1;
}

ll mpow(ll x,ll m) {
    if(!m) return 1;
    ll tmp = mpow(x,m/2);
    tmp = tmp*tmp % mod;
    if(m % 2) return tmp*x%mod;
    return tmp;
}
 
ll Com(ll x,ll r) {
    return fact[x]*factInv[r]%mod*factInv[x-r]%mod;
}

void getDp(int i){
	int n = i - 1;
	ll rst = 0;
	for(int k = 0; k <= n; k++){
		rst += Com(n, k) * dp[n - k] % mod;
	}
	dp[i] = rst%mod;
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>> N >> M;
	S = N;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	
	fact[0] = 1;
    for(int i = 1;i <= 5000;i++) fact[i] = fact[i-1]*i%mod;
    factInv[5000] = mpow(fact[5000],mod-2);
    for(int i = 4999 ;i >= 0;i--) factInv[i] = factInv[i+1]*(i+1)%mod;
	for(int i=4; i<=S; i++) getDp(i);
	
	FOR(i, 1, N) parents[i] = i;
	FOR(i, 1, M){
		cin >> a >> b;
		uni(a, b);
		
		cout << dp[S] << '\n';
	}

	return 0;
}
