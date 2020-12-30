#include <bits/stdc++.h>

using namespace std;

string s;
int tokenCnt;
int pi[1000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while(1){
		tokenCnt = 0;
		getline(cin, s, '\n');
		if(s == ".") break;
		
		fill(pi, pi+s.size(), 0); // 없으면 틀린다?? 
		int i, j;
		
		for(j=0, i=1; i<s.size(); i++){
			while(j > 0 && s[j] != s[i])
				j = pi[j-1];
			if(s[j] == s[i])
				pi[i] = ++j;
			
		}	
		
//		int c = s.size()-1;
//		int tokenLen = c - pi[c] + 1;

//		while(1){
//			if(c+1 - tokenLen < 0 ){
//				tokenCnt = 1;
//				break;
//			}
//			c -= tokenLen;
//			tokenCnt++;
//			if(c < 0) break;
//		}
//		cout << tokenCnt << '\n';

// 		아래는 더 간단한 방식
		if(j == 0) pi[i-1] = 0;
		cout << (
					( i %  (i - pi[i - 1]) )
					? 1
					: ( i / ( i - pi[i - 1])  )
				)
			<< '\n';	

	}

	return 0;
}
