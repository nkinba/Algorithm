#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, Q, a, b;

vector<int> graph[200001];
int parents[200001] = {0,};
int deg[200001] = {0,};
queue<int> oneDegs;

int findRoot(int c){
	if(parents[c] == c) return c;
	return parents[c] = findRoot(parents[c]);
}

void uni(int x, int y){
	int xR = findRoot(x);
	int yR = findRoot(y);
	if(xR > yR) parents[xR] = yR;
	else if(yR > xR) parents[yR] = xR;

	return;
}

int main(void){

 	scanf("%d%d", &N, &Q);
 	
 	FOR(n, 1, N){
 		parents[n] = n;
 		scanf("%d%d", &a, &b);
 		graph[a].push_back(b);
 		graph[b].push_back(a);
 		deg[a]++; 
		deg[b]++;
	 }
	 
	FOR(d, 1, N){
		if(deg[d]==1) oneDegs.push(d);
	}	
 	
 	while(!oneDegs.empty()){
 		int qSize = oneDegs.size();
 		FOR(i, 1, qSize){
 			int node = oneDegs.front();
 			oneDegs.pop();
 			if(deg[node] == 1){
 				for(int nextNodes : graph[node]){
 					if(deg[nextNodes] > 1) {
						 if(--deg[nextNodes] == 1)
							 oneDegs.push(nextNodes); 
 						uni(node, nextNodes);
					 }
				 }
				deg[node]--;
			 }
		 }
	 }

	 FOR(q, 1, Q){
 		scanf("%d%d", &a, &b);
 		int aR = findRoot(a); 
 		int bR = findRoot(b);
		if(findRoot(a) == findRoot(b)) 
		  	printf("%d", 1 );
		else
			printf("%d", 2 );
		printf("\n");
	 }

	return 0;
}
