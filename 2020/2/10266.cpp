#include <bits/stdc++.h>

#define CLOCKSIZE 360000
#define RINGSIZE  360000*2-1 

using namespace std;

int n, inp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	vector<int> c2Pi(CLOCKSIZE);
	
	bool* c1 = new bool[RINGSIZE];
	bool* c2 = new bool[CLOCKSIZE]; 
	fill(c1, c1 + RINGSIZE, false);; 
	fill(c2, c2 + CLOCKSIZE, false);
		
	for(int i=0; i<n; i++){
		cin >> inp;
		c1[inp] = true;
	}
		
	for(int i = 0; i < n; i++){
		cin >> inp;
		c2[inp] = true;
	}
	
	for(int i = CLOCKSIZE; i < RINGSIZE ; i++)
		c1[i] = c1[i - CLOCKSIZE];
		
	for(int i = 1, j = 0; i < CLOCKSIZE; i++){
		while(j > 0 && c2[i] != c2[j] )
			j = c2Pi[j-1];
		if(c2[i] == c2[j])
			c2Pi[i] = ++j;
	}
	
	int i,j;
	for(i = 0, j = 0; i < RINGSIZE; i++){
		while(j > 0 && c1[i] != c2[j] )
			j = c2Pi[j-1];
			
		if(c1[i] == c2[j]){
			if(++j == CLOCKSIZE){
				cout << "possible";
				break;
			}
		}
	}
	
	if(i == RINGSIZE) cout << "impossible";

	delete(c1);
	delete(c2);
	
	return 0;
}
