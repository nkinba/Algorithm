#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#define r first
#define c second
using namespace std;
typedef pair<int,int> pii;
int N,W;
int ans = 1<<20;

pii p[1000];



void func(pii f1, pii f2, int idx, int pre){
 	if(pre > ans) return;
	if(idx == W){
		if(ans > pre)
			 ans = pre;
		return;
	}
	int d1 = abs(p[idx].r - f1.r) + abs(p[idx].c - f1.c);
	int d2 = abs(p[idx].r - f2.r) + abs(p[idx].c - f2.c);
	

	func(p[idx], f2, idx+1, pre+d1);
    func(f1, p[idx], idx+1, pre+d2);
    return;
}

int main(){
	cin >> N >> W;
	for(int i=0; i<W; i++)
		cin >> p[i].r >> p[i].c;
		
	func(pii(1,1), pii(N,N), 0, 0);
	cout << ans <<endl;
	for(int i=0; i<W; i++)
		cout << snap[i] <<endl;
	return 0;
}
