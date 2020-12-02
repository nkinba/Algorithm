
#include <iostream>
#include <queue>
#include <vector>
#include <map>

//#include <fstream>
//#include "windows.h"
//#include "psapi.h"

using namespace std;

typedef vector<int> hyperTube;
typedef vector<hyperTube> hyperTubes;
typedef vector<hyperTube*> tubePointers;

bool visited[100001];
int N,M,K;	
map<int, tubePointers> destList; 
hyperTubes htbs;

int getShortestPath(){
	int dist = 1;
	queue<int> vQueue;	
	
	visited[1] = true;
    for(size_t i=0; i<destList[1].size(); i++){
    	hyperTube* tubep = destList[1][i];
    	for(size_t j=0; j < (*tubep).size(); j++){
			int nextV =(*tubep)[j];
		
			if(nextV == N){
				if(N==1) return dist;
				else return dist+1;
			}
			else if(!visited[nextV]){
				vQueue.push(nextV);
				visited[nextV] = true;
			}
		
		} 
	}

	while(!vQueue.empty()){
		dist++;
		for(size_t i=0; i<vQueue.size(); i++){
			int curV = vQueue.front();
			vQueue.pop();
			
			tubePointers& tptrs = destList[curV];
			
			for(size_t j=0; j<tptrs.size(); j++){
				hyperTube* tptr = tptrs[j];
				for(size_t k=0; k<(*tptr).size(); k++){
					int nextV =(*tptr)[k];
					if(nextV == N ){
//						cout << "NOW "<<curV<<" AND FINALLY ARRIVED "<<nextV<<endl;
						 return dist+1;
					}
					else if(!visited[nextV]){
						vQueue.push(nextV);
						visited[nextV] = true;	
//						cout << "NOW "<<curV<<" AND NEXT IS "<<nextV<<endl;
					}
				}	
			}
		}
	}

	 return -1;
}
 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

//	ifstream ifs("5214tc.txt");

	cin >> N >> K >> M;
//	ifs >> N >> K >> M;
	htbs = hyperTubes(M);
	for(int i=0; i<M; i++){
		for(int j=0; j<K; j++){
			int v; 
			cin >> v;
//			ifs >> v;
			htbs[i].push_back(v);
			destList[v].push_back(&htbs[i]);
		}		 
	}	
//	ifs.close();
	fill(visited, visited+N+1, false);

////	PRINT
//	for(auto i : destList){
//		cout << i.first << " : ";
//		for(auto j : i.second){
//			cout << j << " ";
//		}
//		cout <<endl;
//	}
//	
//	for(int i=0; i<M; i++){
//		cout << "HYPERTUBE " << i << " : ";
//		for(int j=0; j<K; j++){
//			cout << htbs[i][j] << " ";
//		}		 
//		cout <<endl;
//	}	
	
	cout << getShortestPath();
	
	return 0;
}
