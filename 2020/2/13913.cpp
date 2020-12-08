//https://www.acmicpc.net/problem/13913

#include <iostream>
#include <queue>
#include <stack>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, K, t = 0;
int pre[100001];
bool visited[100001] = {false, };
queue<int> Q;
stack<int> path;

void bfs(){
	Q.push(N);
	visited[N] = true;

	while(true){
		int qSize = Q.size();
		FOR(q, 1, qSize){
			int cur = Q.front();
			if(cur == K) return;
			Q.pop();
			
			if(1 <= cur && !visited[cur-1]){
				visited[cur-1] = true;
				pre[cur-1] = cur;
				Q.push(cur-1);
			}
			
			if(cur <= 99999 && !visited[cur+1]){
				visited[cur+1] = true;
				pre[cur+1] = cur;
				Q.push(cur+1);
			}
			if(cur * 2 <= 100000 && !visited[cur*2]){
				visited[cur*2] = true;
				pre[cur*2] = cur;
				Q.push(cur*2);
			}
		}
		t++;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> K;
	fill(pre, pre+100001, -1);
	
	bfs();
	cout << t <<endl;
	
	int pathCheck = K;
	while(pathCheck != -1){
		path.push(pathCheck);
		pathCheck = pre[pathCheck];
	}
	while(!path.empty()){
		cout << path.top() << " "; 
		path.pop();
	}
	
	return 0;
}


