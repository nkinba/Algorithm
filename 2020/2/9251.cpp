#include <bits/stdc++.h>

using namespace std;

int M[1001][1001];
string str1, str2;

int main(){
	cin >> str1 >> str2;
	int row1 = str1.length();
	int col2 = str2.length();
	fill_n(M[0], col2+1, 0);
	for(size_t r=1; r<=row1; r++) M[r][0] = 0;
	
	for(size_t i=1; i<=row1; i++){
		for(size_t j=1; j<=col2; j++){ 
			M[i][j] = max(
							max( M[i-1][j], M[i][j-1] ),
				 		    M[i-1][j-1] + ((str1[i-1]==str2[j-1]) ? 1 : 0 )
				 		  );
				      
		}
	}

	cout << M[row1][col2];	
	return 0;
}
