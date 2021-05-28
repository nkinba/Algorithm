// ºÐÇØÇÕ  

#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	
	int ans=1;
	while(ans < n){
		int s = 0;
		int m = ans;
		int d = 1;
		while(m > 0){
			int r = m % 10;
			s += (r + r * d);
			d *= 10;
			m /= 10;
		}
		
		if(s == n) break; 
		ans++;
	}
	if(ans == n ) ans = 0;
	cout << ans;
	return 0;
}
