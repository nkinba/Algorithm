#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPath(vector < vector< pair<int,int> > > & map, int start, int dest, int N){

	priority_queue< pair<int, int> ,
					vector< pair<int, int> > ,
					greater< pair<int, int> > 
				  > pathQueue;
				  
	int curWeight, curNode, sum=0;
	int dist[N+1]; fill_n(dist, N+1, 101); dist[start] = 0; 
	pathQueue.push( {0 , start} );
	
	while(!pathQueue.empty())
	{
		curWeight = pathQueue.top().first;  curNode = pathQueue.top().second;
	//	cout << curWeight << " " << curNode <<endl;
		pathQueue.pop();
		if(curWeight > dist[curNode]){
		 continue;
		}
		
		for(size_t i=0; i<map[curNode].size(); i++){
			int nextNode = map[curNode][i].first;
			int curDist = dist[nextNode];
			int nextDist = curWeight + map[curNode][i].second;
			if( curDist > nextDist){
				dist[nextNode] = nextDist;
				pathQueue.push( {nextDist, nextNode} );
			}			
		}	
			
	}
//	cout<< "dist dest " <<dist[dest]<<endl;
	sum+=dist[dest];
	
	
	fill_n(dist, N+1, 101); dist[dest] = 0; 
	pathQueue = priority_queue< pair<int, int> ,
					vector< pair<int, int> > ,
					greater< pair<int, int> > 
				  > ();
	pathQueue.push( {0,dest} );	
		
	while(!pathQueue.empty())
	{
		curWeight = pathQueue.top().first;  curNode = pathQueue.top().second;
		pathQueue.pop();
		if(curWeight > dist[curNode]){
		 continue;
		}
		
	for(size_t i=0; i<map[curNode].size(); i++){
			int nextNode = map[curNode][i].first;
			int curDist = dist[nextNode];
			int nextDist = curWeight + map[curNode][i].second;
			if( curDist > nextDist){
				dist[nextNode] = nextDist;
				pathQueue.push( {nextDist, nextNode} );
			}			
		}	
	}
	
//	cout<< "dist start " <<dist[start]<<endl;
	sum+=dist[start];
	return sum;
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
//			cout << map[i][j].first << " " << map[i][j].second <<endl;
//		}
//	}
//


	for(size_t i=1; i<=N; ++i){
		int curPath = shortestPath(map, i, X, N);
		if(max < curPath) max=curPath;	
//		cout << "max : " <<max <<endl;
	}
 
 
 //	cout << "finalmax : " <<max <<endl;

	cout << max;

	return 0;
}
