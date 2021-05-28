#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> linked[100001];
int N, a, b;
int v[100001] = {0,};
queue<int> Q;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i=1; i<=N-1; i++){
		cin >> a >> b;
		linked[a].emplace_back(b);
		linked[b].emplace_back(a);
	}

	int i;
	v[1] = -1;
	Q.push(1);
	while(!Q.empty()){
		i = Q.front();
		Q.pop();
		for(int link : linked[i]){
			if(v[link] == 0){
				v[link] = i;
				Q.push(link);
			}
		}
	}	
	
	for(int n = 2; n <= N; n++)
		cout << v[n] <<'\n';

	return 0;
}
