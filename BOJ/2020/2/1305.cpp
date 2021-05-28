#include <bits/stdc++.h>

using namespace std;

string s;
int pi[2000001];
int L;
int maxLen;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> L;
	cin >> s;
	
	maxLen = L;
	int i, j;
	
	for(j=0, i=1; i < L; i++){
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[j] == s[i])
			pi[i] = ++j;		
	}	

//	for(int i=0; i<L; i++)
//		cout  << pi[i];
//	cout << '\n';
	cout << L - pi[L-1]; 

	return 0;
}
