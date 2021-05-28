#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

#define term get<0> 
#define dist get<1>
#define node get<2>

#define MAX 10000001

using namespace std;

typedef tuple<int,int,int> tiii;

int T, N, M, K, u, v, c, d;
vector<tiii> cost[101];
priority_queue<tiii> Q;

int minTerm[101] = {0,};
int distRst[101] = {0,};

int curNode, curTermSum, curDistSum;
int nextNode, nextTerm, nextDist, termResult, distResult;
int answer;

void print(){
	cout << "\nMINTERMS " <<endl;
	FOR(t, 1, N)
		cout << minTerm[t] << " ";
		
	cout << "\n\nDISTANCES "<<endl;
	FOR(d, 1, N)
		cout << distRst[d] << " ";
	cout <<"\n\n";
}

void findMinD(){
	fill(minTerm+2, minTerm+N+1, MAX);
	fill(distRst+1, distRst+N+1, 0);
	minTerm[1] = 0;
	Q.push(tiii(0,0,1));
	
	while(!Q.empty()){
//	print();
		curNode = node(Q.top());
		curTermSum = -term(Q.top());
		curDistSum = dist(Q.top());
		
//		cout << "\ncurNode : " << curNode <<endl;
//		cout << "curTermSum : " << curTermSum <<endl;
//		cout << "curDistSum : " << curDistSum <<endl;
		
		if(curNode == N){
//			cout << "check Destination..." <<endl;
			if(curDistSum <= M){
//				cout << "Dist Is In Range... "<<endl;
				answer = min(answer, curTermSum);
//				cout << "Renewed Answer : " << answer <<endl;
			}
			Q.pop();
		}
		else{
			vector<tiii>& nextNodes = cost[curNode];
			Q.pop();
			
			if(minTerm[curNode] >= curTermSum){
				FOR(i, 0, nextNodes.size()-1){
					nextNode = node(nextNodes[i]);
					nextTerm = term(nextNodes[i]);
					nextDist = dist(nextNodes[i]);
					termResult = curTermSum + nextTerm;
					distResult = curDistSum + nextDist;
					
		//			cout << "\nnextNode : " << nextNode <<endl;
		//			cout << "nextTerm : " << nextTerm <<endl;
		//			cout << "nextDist : " << nextDist <<endl;
		//			cout << "termResult : " << termResult <<endl;
		//			cout << "distResult : " << distResult <<endl;	
							
					if(termResult <= minTerm[nextNode]){
		//				cout << "Renew.. Push " << nextNode << " Into Q..."<<endl;
						minTerm[nextNode] = termResult; 
						distRst[nextNode] = distResult;
						Q.push(tiii(-termResult, distResult, nextNode));
					}
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

	cin >> T;
	FOR(t, 1, T){
		answer = MAX;
		
		cin >> N >> M >> K;
		fill(cost+1, cost+N+1, vector<tiii>());
		
		FOR(k, 1, K){
			cin >> u >> v >> c >> d;
			cost[u].emplace_back(tiii(d, c, v));
		}
	
		findMinD();
//		print();
		
//		cout << "\n============ANSWER IS " ;
		if(answer == MAX) cout << "Poor KCM\n";
		else cout << answer << '\n';
		
	}
	
	return 0;
}
