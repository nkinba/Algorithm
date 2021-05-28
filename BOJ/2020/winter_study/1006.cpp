#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//typedef pair<short, short> pss;
//typedef pair< pss, short> pps;
typedef map< short, vector<short> > msv;

class node{
public:
	node* prev;
	node* next;
	node* vert;
	short val;
	short id;
	
	void print(){
		cout << "ID : " << id <<"\tVALUE : " << val << "\tPREVIOUS : " << prev->id 
			<< "\tNEXT : " <<next->id << "\tVERTICAL : " << vert->id <<endl;
	}
};

class Onetagon{
	short Nodenum;
	node* Nodes;
public:
	Onetagon(const short Num){
		Nodenum = Num;
		Nodes = new node[Num*2];
	}
	
	~Onetagon(){
		delete Nodes;
	}
	
	bool getNodes(istream& is){
		for(size_t i=0; i<Nodenum*2; i++){
			is >> Nodes[i].val;
			Nodes[i].id = i+1;   
			if(i<Nodenum) {            
				Nodes[i].prev = &Nodes[(i+Nodenum-1)%Nodenum];
				Nodes[i].next = &Nodes[(i+1)%Nodenum];
				Nodes[i].vert = &Nodes[i+Nodenum];
			}
			else {						 
				Nodes[i].prev = &Nodes[(i+Nodenum-1)%Nodenum + Nodenum];
				Nodes[i].next = &Nodes[(i+1)%Nodenum + Nodenum];
				Nodes[i].vert = &Nodes[i-Nodenum];
			}
		}
	}
	void print(){
		cout << "============================================================================" <<endl;
		for(size_t i=0; i<Nodenum*2; i++)
			Nodes[i].print();
		cout << "============================================================================" <<endl;
	}
	
	node& operator[](const int i){
		return Nodes[i];
	}
	
};

int T,N,W;
short answer = 0;
short rest;
vector<bool> Visited;
msv CoverPair;

short GetOptimisticCover(int i){

	short Covers = 0;
	vector<short>& nextNodes = CoverPair[i];
	short next;
	for(size_t i=0; i<nextNodes.size(); i++){
		next = nextNodes[i];
		if(!Visited[next]){
			Visited[next] = true; 
			cout << "GO TO NEXT NODE : " << next <<endl;
			Covers += (1+GetOptimisticCover(next));
		}	
	}
	
	return Covers;
}

int main(void){
	cin >> T;
	while( (T--) > 0){ 
		
		cin >> N >> W;
		
		Visited = vector<bool>(N*2 + 1, false);
		rest = N*2;	
		
		Onetagon TC = Onetagon(N);
		TC.getNodes(cin);
		TC.print(); 
		
		node Start = TC[0];
		for(size_t i=0; i<N*2; i++){
			short HorSumVal = (TC[i].val + TC[i].next->val);
			if( (TC[i].val + TC[i].next->val) <= W){
				CoverPair[i+1].push_back(TC[i].next->id);  // key : node id , value : 이어진 node들의 id 
				CoverPair[TC[i].next->id].push_back(i+1);  			
			}
		}	
		for(size_t i=0; i<N; i++){
			short VerSumVal = (TC[i].val + TC[i].vert->val);
			if( (TC[i].val + TC[i].vert->val) <= W){
				CoverPair[i+1].push_back(TC[i].vert->id);  // key : node id , value : 이어진 node들의 id 
				CoverPair[TC[i].vert->id].push_back(i+1);  			
			}
		}	
		msv::iterator i;
		for(i=CoverPair.begin(); i!=CoverPair.end(); i++){
			cout  << i->first << " : " ;
			for(size_t j=0; j<i->second.size(); j++)
			 cout << i->second[j] << " ";
			cout <<endl;
		}	
	
		for(i=CoverPair.begin(); i!=CoverPair.end(); i++){
				short start = i->first;
				if(!Visited[start]){
					Visited[start] = true;
					short res = GetOptimisticCover(start)/2;
					cout << "START FROM : " <<start << ", RESULT : " <<res <<endl;
					answer += res;
					rest -= (res*2);
				}
		}
		
		answer += rest;
		cout << answer;
		
		CoverPair.clear();
		Visited.clear();
	}
	return 0;
}

