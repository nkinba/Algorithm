#include <iostream>
#include <vector>
#include <map>
#
using namespace std;

int shortestPath(vector < map<int, int> > & Map, int start, int dest, int N){
	int curNode = start , curWeight = 0, path;
	int nextNode, nextWeight;
//	vector<int> dist(N+1,101);
//	vector<bool> select(N+1,false);
	int* dist= new int[N+1];  fill_n(dist,N+1,101);
	bool* select = new bool[N+1]; fill_n(select,N+1,false);
	
	map<int,int>::iterator Iter_Node;

	dist[start]=0; select[start]=true; 

	while(curNode!=dest){
		
	//			cout << "CURRENT NODE : " << curNode << " CURRENT WEIGHT : " <<  curWeight<<endl <<endl;
		 for( Iter_Node = Map[curNode].begin(); Iter_Node != Map[curNode].end(); ++Iter_Node){
		 	nextNode = Iter_Node->first; 
			nextWeight = Iter_Node->second;
			
	//	 	cout << "NEXT NODE : " << nextNode << " NEXT WEIGHT : " <<  nextWeight<<endl <<endl;
							
		
			if( select[nextNode] == false && (dist[nextNode] > curWeight + nextWeight)) 
					dist[nextNode] = curWeight + nextWeight;

		}
		
		 int minNode=curNode, minWeight=1000000;
		 for(size_t i=1; i<=N; ++i){
			if(select[i]==false && minWeight>dist[i] ){ 
				minWeight = dist[i]; 	
				minNode = i;
			}
		 }
	//	 		 cout << "MIN NODE : " << minNode<<endl<<endl;

		 curNode = minNode;
		 curWeight = dist[curNode];
		 select[curNode]=true;
		}
	path =dist[dest];
	delete dist,select;
	return path;
}

int main(void){
	int N,M,X,s,max = 0;
	int start = 1;
	cin >> N >> M >> X;
	vector< map<int,int> > Map(N+1, map<int,int>());
	
	for(size_t i=0; i<M; ++i){
		cin >> s; 
	//	cout << "s "<<s<<endl;
		pair<int , int> p; 
		cin >> p.first; cin >> p.second;
		Map[s].insert(p);
	}

//	for(int i=1; i<=N; ++i){
//		for(int j =0; j <map[i].size(); ++j){
//			cout << i << " " << map[i][j].first << " " << map[i][j].second <<endl;
//		}
//	}



	for(size_t i=1; i<=N; ++i){
		int curPath = 
			shortestPath(Map, i, X, N) + shortestPath(Map, X, i ,N);
		if(max < curPath) max=curPath;	
	//	cout << i << " to "<< X << " max : " <<max <<endl<<endl;
	}
 
 
 //	cout << "finalmax : " <<max <<endl;

	cout << max;

	return 0;
}
