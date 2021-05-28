#include <iostream>
#include <queue>
#include <stack>
#define wgt first
#define dest second
#define MAX 100000000000
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii> costs[1001];
int n,m, f,t,c;
int from, to;
int curDistSum, curNode, nextNode, stepResult;
ll dist[1001];
int pre[1001] = {0, };
stack<int> stk;
priority_queue<pii> Q;

void bfs(){
	fill(dist+1, dist+n+1, MAX);
	dist[from] = 0;
	
	Q.push(pii(0, from));
	
	while(!Q.empty()){
		
		curDistSum = -Q.top().wgt;
		curNode = Q.top().dest;
		Q.pop();
		
		if(dist[curNode] >= curDistSum){
			vector<pii>& nears = costs[curNode];
			
			for(int i = 0; i< nears.size(); i++) {
				nextNode = nears[i].dest;
				stepResult = curDistSum + nears[i].wgt;
				if(stepResult < dist[nextNode] ){
					pre[nextNode] = curNode;
					dist[nextNode] = stepResult;
					Q.push(pii(-stepResult, nextNode));
				}
			}
		} 
	}
	return;

}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin  >> n >> m;
	FOR(i, 1, m){
		cin >> f >> t >> c;
		costs[f].push_back(pii(c,t));
	}
	cin >> from >> to;
	
	bfs();
	cout << dist[to] << '\n';
	
//	FOR(i,1,n) cout << dist[i] << "\n";
//	FOR(i,1,n) cout << pre[i] << "\n";
	
	int path = to;
	while(path != 0){
		stk.push(path);
		path = pre[path];
	}
	cout << stk.size() << '\n';
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	
	
}
