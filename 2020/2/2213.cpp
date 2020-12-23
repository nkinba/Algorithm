#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define nextNum first
#define checkOrNot second 

#define value first
#define leaves second

using namespace std;

typedef pair<int,bool> pib;
typedef pair<int, vector<pib>> branchInfo;

int N;
branchInfo dp[2][10001] ={{branchInfo(0, vector<pib>())},};
vector<int> independentSet;
queue<branchInfo*> nodeQ;

struct node{
	static int count;
	int val,num;
	vector<node*> links;
	
	node(){	num = count++;}
	node(int v) : val(v) {}	
};

int node::count = 0;
node* Nodes;

branchInfo process(node& R, bool check, int from){
	int now = R.num;
	branchInfo& res = dp[check][now];
	
	if(res.value) return res;
	
	vector<node*>& nextNodes = R.links;
	for(node* next : nextNodes){
			if(next->num == from) continue;
			
			branchInfo skipNext = process(*next, false, now);
			
			if(!check){
			    branchInfo checkNext =  process(*next, true, now);
			    
				if(skipNext.value <= checkNext.value){
					res.value += checkNext.value;
					res.leaves.emplace_back(pib(next->num, true));
				}
				else {
					res.value += skipNext.value;
					res.leaves.emplace_back(pib(next->num, false));
				}
				
			} 
			else {
				res.value += skipNext.value;
				res.leaves.emplace_back(pib(next->num, false));
			}	
	}
	
	if(check) res.value += R.val;
//		cout << "Now Node Num is " << R.num << " , " << check <<endl;
//		 cout << "result : " << res.value <<endl;

	return res;
}

void printNodes(){
	for(size_t i=1; i<=N; i++){
		cout << "NODE NUM : " << Nodes[i].num << " |  VALUE : " << Nodes[i].val <<endl;
		cout << "HAS LINKS TO {" ;	
		for(size_t j=0; j<Nodes[i].links.size(); j++)
			 cout << Nodes[i].links[j]->num << ", ";
		cout <<"}"<<endl;
	}
}

void traverse(branchInfo& startNode, bool checkStart){
	if(checkStart) independentSet.emplace_back(1);
	nodeQ.push(&startNode);
	
	while(!nodeQ.empty()){
		branchInfo* curNode = nodeQ.front();
		nodeQ.pop();
		for(pib nextNodes : curNode->leaves){
			if(nextNodes.checkOrNot) independentSet.emplace_back(nextNodes.nextNum);
			nodeQ.push(&dp[nextNodes.checkOrNot][nextNodes.nextNum]);
		}	
	}
	
	sort(independentSet.begin(), independentSet.end());
	for(int setElem : independentSet) cout << setElem << " ";
	return;
}

int main(void){
	int v,b,e;
	cin >> N;
	Nodes = new node[N+1];
	for(size_t i=1; i<=N; i++){
		cin >> v;
		Nodes[i].val = v;	
	}
	for(size_t i=0; i<N-1; i++){
		cin >> b >> e;
		Nodes[b].links.push_back(&Nodes[e]);
		Nodes[e].links.push_back(&Nodes[b]); 
	}		
//	printNodes();
	branchInfo checkFirst = process(Nodes[1], true, Nodes[1].num),
			   skipFirst  = process(Nodes[1], false, Nodes[1].num);
	
	if(checkFirst.value >= skipFirst.value ){
		cout << checkFirst.value << '\n';
		traverse(checkFirst, true);
	}
	else{
		cout << skipFirst.value << '\n';
		traverse(skipFirst, false);
	}
				
	return 0;
}
