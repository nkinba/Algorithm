#include <iostream>

#define r first
#define c second

using namespace std;

typedef pair<int,int> pii;

int R,C;
int N,W;
pii p[1000];

int main(){
	 cin >> R >> C >> N >> W;
	 for(int i=0; i<W; i++)
	 	 cin >> p[i].r >> p[i].c;
	 	 
	return 0;
}
