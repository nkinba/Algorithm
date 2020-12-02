#include <bits/stdc++.h>

#define w first
#define h second

using namespace std;

typedef pair<int,int> pii;

vector<pii> info(50);
vector<int> ranks(50);

int main(void){
	int n; cin >> n;
	
	for(int i=0; i<n; i++)
		cin >> info[i].w >> info[i].h;
		
	for(int i=0; i<n; i++){
		int c=0;
		for(int j=0; j<n; j++){
			if(i==j) continue;
			if(info[i].w < info[j].w && info[i].h < info[j].h) c++;			
		}
		ranks[i] = c+1;
	}
	
	for(int i=0; i<n; i++)
		cout << ranks[i] << " ";
		
	return 0;
}
