#include <bits/stdc++.h> 

#define MAX 200000001
#define num first
#define wgt second

using namespace std;

typedef pair<int,int> pii;

int N, E, f, t, w, v1, v2;
int curNode, nextNode, curDistSum, stepResult;
int answer;

int dist[801];
vector<pii> edges[801];
priority_queue<pii> qi;

vector<pii> rst;

//void printDist(){
//	for(int i=1; i<=N; i++)
//		cout <<dist[i] << " ";
//		cout <<endl<<endl;
//}

void findShortest(int from, int dst1, int dst2){

	fill(dist+1, dist+N+1, MAX);
	dist[from] = 0;
	
	qi.push(pii(from, 0));
	
	while(!qi.empty()){
		curNode = qi.top().num;
		curDistSum = -qi.top().wgt;
		
		qi.pop();
		
		if(dist[curNode] >= curDistSum){
			vector<pii>& nears = edges[curNode];
			
			for(int i = 0; i< nears.size(); i++) {
				nextNode = nears[i].num;
				stepResult = curDistSum + nears[i].wgt;
				if(stepResult < dist[nextNode] ){
					dist[nextNode] = stepResult;
					qi.push(pii(nextNode, -stepResult));
				}
			}
		} 
	}
	
	rst.emplace_back(pii(dist[dst1], dist[dst2] ));
}

int main(void){
	scanf("%d%d", &N, &E);
		
	for(int e = 0; e < E; e++){
		scanf("%d%d%d", &f, &t, &w);
		edges[f].emplace_back(pii(t,w));
		edges[t].emplace_back(pii(f,w));
	}
	
	scanf("%d%d", &v1, &v2);
		
	findShortest(1, v1, v2);
	findShortest(v1, v2, N);
    findShortest(v2, v1, N);
	
	answer = min(rst[0].first + rst[1].first+ rst[2].second, 
				 rst[0].second + rst[2].first + rst[1].second);
	if(answer >= MAX) 
		printf("%d", -1);
	else printf ("%d",answer);
	
	return 0;
}
