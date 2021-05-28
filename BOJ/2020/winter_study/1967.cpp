/* 1967번 트리의 지름 
 	https://www.acmicpc.net/problem/1967 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 999901

using namespace std;
 
typedef pair<int,int> pii;
 
vector<pii> links[10001];
int N, p, c, w;
int dias[10001];

int f(int c){
	vector<pii>& leaves = links[c];
	if(leaves.size() == 0) return 0;
	priority_queue<int> rads;
	int stepRst;
	for(pii leaf : leaves){
			stepRst = leaf.second + f(leaf.first);
			rads.push(stepRst);
	}	
	int first = rads.top();
	rads.pop();
	int second = ((rads.size() > 0 ) ? rads.top() : 0);
//	cout << first << " and " << second <<endl;
	
	dias[c] = ((second == 0) 
				? ( (c == 1) ? first : 0)
				: (first + second));

	return first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i=1; i<=N-1; i++){
		cin >> p >> c >> w;
		links[p].emplace_back(pii(c,w));
	}
	
	f(1);
	sort(dias+1, dias+N+1);
		cout << dias[N] <<endl;
	return 0;
}
