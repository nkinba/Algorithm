#include <iostream>

using namespace std;

typedef long long ll;

ll basis[2][2] = { {1,1}, {1,0}};
ll ans[2][2] = { {1,1}, {1,0}};
ll n;

void mul(ll A[2][2], ll B[2][2]){
	ll a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	ll b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	ll c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	ll d = A[1][0] * B[0][1] + A[1][1] * B[1][1];
	A[0][0] = a%1000000;
	A[0][1] = b%1000000;
	A[1][0] = c%1000000;
	A[1][1] = d%1000000;
}


void pow(ll mat[2][2], ll n){
	if(n==0 || n==1) return;
	pow(ans, n/2);
	mul(ans, ans);
	if(n%2) mul(ans,basis); 
}

ll f(ll n){
	if(n==0) return 0;
	pow(ans, n-1);
 
	return ans[0][0];
}

int main(){
	cin >> n;
	cout << f(n);

	return 0;
}
