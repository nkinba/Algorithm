#include <iostream>
#include <map>
#include <climits>

using namespace std;

int shortestPath(int N, map<int, map<int ,int> >& mp, int start, int dest){
	int go, back, curPos, nextPos, minWeight; 
	int sPath[N+1]; fill_n(sPath,N+1,INT_MAX);
	int check[N+1]; fill_n(check,N+1,false);

	map<int,int>::iterator Iter_Node;
	
	//왔다 
	sPath[start]=0; check[start]=true; curPos = start;
	while(check[dest]==false){
		int curWeight = sPath[curPos];
	
		for( Iter_Node = mp[curPos].begin(); Iter_Node != mp[curPos].end(); ++Iter_Node){
	   		
			int checkPos = Iter_Node->first;   		
			sPath[ checkPos ] = min(  sPath[ checkPos ]	, curWeight + Iter_Node->second );	
			if(minWeight > sPath[ checkPos ] && check[ checkPos ]==false){
				minWeight = sPath[ checkPos ];
				nextPos = checkPos;
			}
		}
//		cout << "next : "<<nextPos <<endl;
		curPos = nextPos; check[curPos]=true, minWeight=101;
	}
	go = sPath[dest];
//	cout << "go : " <<go <<endl;
	//

	fill_n(sPath,N+1,101);
	fill_n(check,N+1,false);
	//갔다
	sPath[dest]=0; check[dest]=true; curPos = dest;
	while(check[start]==false){
		int curWeight = sPath[curPos];
		for( Iter_Node = mp[curPos].begin(); Iter_Node != mp[curPos].end(); ++Iter_Node){
	   	
		   	int checkPos = Iter_Node->first;   		
		   	sPath[ checkPos ] = min(  sPath[ checkPos ]	, sPath[curPos] + Iter_Node->second );		
			if(minWeight > sPath[ checkPos ] && check[ checkPos ]==false){
				minWeight = sPath[ checkPos];
				nextPos = checkPos;
			}
		}
		curPos = nextPos; check[curPos]=true, minWeight=101;
	}
	back = sPath[start];
	//	cout << "back : " <<back<<endl;

	//		
	return go+back;	
} 


int main(void){
	int N,M,X,s=1 ,max = 0;
	int start = 1;
	map<int ,int> node;
	map<int , map<int ,int> > MAP; 
	
	// 입 
	cin >> N >> M >> X;
	for(size_t i=0; i<M; ++i){
		cin >> s; 
		if(s!=start){
			MAP[start] = node;
			start = s;
			node.clear(); 	
		}
		pair<int , int> p; 
		cin >> p.first; cin >> p.second;
		node.insert(p);
		if(start==N) MAP[start] =node;
	}

	// 력 

	// 구  
	for(size_t i=1; i<=N; i++){
	//	cout << "start : "<< i<<endl;
		int start=i; int dest=X;
		int w = shortestPath(N,MAP,i,X);
		if( w > max ) max = w;
	}	
	
//	cout << "MAX :  " << max;
	// 하 기  
	
	cout << max;
//	for(int i=0; i<=N; i++ )
//	{
//	   map<int , int>::iterator Iter_PPos;
//	   	for( Iter_PPos = MAP[i].begin(); Iter_PPos != MAP[i].end(); ++Iter_PPos)
//			cout << i << " " << Iter_PPos->first << " " << Iter_PPos->second << endl; 
//	
//	}

	return 0;
}
