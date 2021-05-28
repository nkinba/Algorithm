#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt = 0;

ll A,B,C;

ll f(ll B){
	cnt++;
	ll v;
	if(B==1) v = A;
	else {
				
		if(B%2) v = f(B-1)*A%C;
		else v = (f(B/2)%C)*(f(B/2)%C)%C;

// 아래 로직은 시간초과. 
//		v = (f(B/2)%C)*(f(B/2)%C)%C;
//		if(B%2){
//			v*= A;
//			v %= C;
//		}

	}
	return v;	
}

int main(void){
	cin >> A >> B >> C;	
	cout << f(B)%C;
	return 0;
}
