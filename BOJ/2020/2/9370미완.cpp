#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

#define FOR(i,b,e) for(int i=b; i<=e; i++)
#define wgt first
#define num second
#define MAX 200000000
			
using namespace std;

typedef pair<int,int> pii;

int T;
int n,m,t;
int s,g,h;
int a,b,d;

priority_queue<pii> Q;
vector<pii> costs[2001];
int dest[101];

int distFromS[2001];
int distFromG[2001];
int distFromH[2001];
int sTog, sToh, gToh, target;

int curNode, nextNode, curDistSum, stepResult;

void findDest(int start, int* dist){

	fill(dist+1, dist+n+1, MAX);
	dist[start] = 0;
	Q.push(pii(0, start));
	
	while(!Q.empty()){
		
		curDistSum = -Q.top().wgt;
		curNode = Q.top().num;
		Q.pop();
		
		if(dist[curNode] >= curDistSum){
			vector<pii>& nears = costs[curNode];
			
			for(int i = 0; i< nears.size(); i++) {
				nextNode = nears[i].num;
				stepResult = curDistSum + nears[i].wgt;
				if( stepResult < dist[nextNode] ){
					dist[nextNode] = stepResult;
					Q.push(pii(-stepResult, nextNode));
				}
			}
		} 
	}
	
	return;
}

void printResult(){
cout << "\nPrint Result\n";
	FOR(i, 1, n)
		cout <<distFromS[i] << " ";
	cout <<'\n';
	FOR(i, 1, n)
		cout <<distFromG[i] << " ";
	cout <<'\n';
	FOR(i, 1, n)
		cout <<distFromH[i] << " ";
	cout <<'\n';		
}

int main(void){
	ifstream ifs("9370inp.txt");

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
//	ifs >> T;
	FOR(testCase, 1, T){
		cin >> n >> m >> t >> s >> g >> h;
//		ifs >> n >> m >> t >> s >> g >> h;

		fill(costs+1, costs+n, vector<pii>());

		FOR(road, 1,  m){
			cin >> a >> b >> d;
//			ifs >> a >> b >> d;
			if((a==g && b==h) || (a==h && b==g)) gToh = d;
			costs[a].emplace_back(pii(d, b));
			costs[b].emplace_back(pii(d, a));
		}
		
		FOR(x, 0, t-1) 
			cin >> dest[x];
//			ifs >> dest[x];
		
		findDest(s, distFromS);
		findDest(g, distFromG);
		findDest(h, distFromH);
//		printResult();
		sTog = distFromS[g];
		sToh = distFromS[h];
		
		sort(dest, dest+t);
		
		FOR(x, 0, t-1){
			int s_g_h_t;
			int s_h_g_t;
			target = dest[x];
//			if(abs(sTog - sToh) == gToh){
//				if(sTog > sToh && sTog + distFromG[target] <= distFromS[target])
//					cout << target << " ";
//				else if( sToh > sTog && sToh + distFromH[target] <= distFromS[target])
//					cout << target << " ";	
//			}
//			else {
//				if(sTog >= sToh && sToh + gToh + distFromG[target] <= distFromS[target])
//					cout << target << " ";
//				else if(sToh > sTog && sTog + gToh + distFromH[target] <= distFromS[target])
//					cout << target << " ";
//			}
			s_g_h_t = sTog + distFromH[target];
			s_h_g_t = sToh + distFromG[target] + gToh;
			if( sToh >= sTog && s_g_h_t <= distFromS[target] && s_g_h_t < MAX)
				cout << target << " ";
			else if(sToh < sTog && s_h_g_t <= distFromS[target] && s_h_g_t < MAX)
							cout << target << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
