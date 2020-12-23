/* 1949 우수 마을 
	3644	12ms	C++14 	1994B
	 
	트리의 경우 사이클이 없으므로 맨 처음 입력받는 노드를 Root로 하여 
	트리를 preorder로 트리를 순회하면서 각 노드에서 우수 마을일 때와 아닐 때의 인구 수 합을 비교하는 
	동적 계획법으로 풀었음 
	 	 
	 https://www.acmicpc.net/problem/1949 
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[2][10001] ={{0,},};
	
struct node{
	static int count;
	int val,num;
	vector<node*> links;
	
	node(){	num = ++count;}
	node(int val){ 
		this->val = val;
	}
};
int node::count = 0;
node* Nodes;

int process(node& R, bool type, int from){
	int now = R.num;
	int& res = dp[type][now];
	
	if(res) return res;
	
	vector<node*>& nextNodes = R.links;
	for(node* next : nextNodes){
			if(next->num == from) continue;
			
			if(!type)
				res += max(process(*next, !type, now), process(*next, type, now));
			else
				res += process(*next, !type, now);
		
	}
	if(type) res += R.val;
//		cout << "Now Node Num is " << R.num << " , " << type <<endl; cout << "result : " << res <<endl;

	return res;
}

void printNodes(){
	for(size_t i=0; i<N; i++){
		cout << "NODE NUM : " << Nodes[i].num << " |  VALUE : " << Nodes[i].val <<endl;
		cout << "HAS LINKS TO {" ;	
		for(size_t j=0; j<Nodes[i].links.size(); j++)
			 cout << Nodes[i].links[j]->num << ", ";
		cout <<"}"<<endl;
	}
}

int main(void){
	int v,b,e;
	cin >> N;
	Nodes = new node[N];
	for(size_t i=0; i<N; i++){
		cin >> v;
		Nodes[i].val = v;	
	}
	for(size_t i=0; i<N-1; i++){
		cin >> b >> e;
		Nodes[b-1].links.push_back(&Nodes[e-1]);
		Nodes[e-1].links.push_back(&Nodes[b-1]);
	}		
//	printNodes();
	
	int Max = process(Nodes[0], true, Nodes[0].num);
//	cout << "----------------------------------------"<<endl;
	cout << max(Max, process(Nodes[0], false, Nodes[0].num));	
			
	return 0;
}
