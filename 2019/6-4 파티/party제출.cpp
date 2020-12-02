#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int shortestPath(vector < vector< pair<int,int> > > & map, int start, int dest, int N){
	priority_queue< pair<int, int> ,
					vector< pair<int, int> > ,
					greater< pair<int, int> > 
				  > pathQueue;
				  
	int curWeight, curNode;
	int dist[N+1]; fill_n(dist, N+1, INT_MAX); dist[start] = 0; 
	
	pathQueue.push( {0 , start} );
	
	while(!pathQueue.empty())
	{
		curWeight = pathQueue.top().first;  curNode = pathQueue.top().second;
	//	cout << "CURRENT NODE : " << curNode << " CURRENT WEIGHT : " <<  curWeight<<endl <<endl;
		pathQueue.pop();
		
//		if(curWeight >= dist[curNode]){
//		 cout << "dist[" << curNode << "] : " << dist[curNode] <<endl <<endl; 
//		 continue;
//		}
		
		for(size_t i=0; i<map[curNode].size(); i++){
			int nextNode = map[curNode][i].first;
			int curDist = dist[nextNode];
			int nextDist = curWeight + map[curNode][i].second;
	//		cout << "CHECK NODE : " << nextNode << "  dist[" << nextNode << "] : " << curDist << 
	//		"  dist from " << curNode << " : " << nextDist <<endl <<endl;
			if( curDist > nextDist){
				dist[nextNode] = nextDist;
				pathQueue.push( pair<int,int>(nextDist, nextNode) );
			}			
		}	
			
	}
//	cout<< "dist : " <<dist[dest]<<endl;
	return dist[dest];
}

int main(void){
	int N,M,X,s,max = 0;
	int start = 1;
	cin >> N >> M >> X;
	vector < vector< pair<int,int> > >  map(N+1, vector<pair <int, int> >());
	
	for(size_t i=0; i<M; ++i){
		cin >> s; 
	//	cout << "s "<<s<<endl;
		pair<int , int> p; 
		cin >> p.first; cin >> p.second;
		map[s].push_back(p);
	}

//	for(int i=1; i<=N; ++i){
//		for(int j =0; j <map[i].size(); ++j){
//			cout << i << " " << map[i][j].first << " " << map[i][j].second <<endl;
//		}
//	}



	for(size_t i=1; i<=N; ++i){
		int curPath = 
			shortestPath(map, i, X, N) + shortestPath(map, X, i ,N);
		if(max < curPath) max=curPath;	
//		cout << i << " to "<< X << " max : " <<max <<endl<<endl;
	}
 
 
 //	cout << "finalmax : " <<max <<endl;

	cout << max;

	return 0;
}
