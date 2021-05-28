/* 1068번 트리
    특정 노드 제거 시 리프 노드의 개수를 구하는 문제  
	1984KB	0ms	C++14 1106B
	
	https://www.acmicpc.net/problem/1068 

*/ 

#include <iostream>
#include <vector>

using namespace std;

int N;

struct node{
	static int num;
	static int leaf;
	int val;
	node* parent;
	vector<node*> children;
	
	node(){
		val = num++;
		parent = nullptr;
	}
};

int node::num = 0;
int node::leaf = 0;
node* Nodes;

void print_tree(){
	for(size_t i=0; i<N; i++){
		cout << i << ":";
		for(size_t j=0; j<Nodes[i].children.size(); j++)
			cout << Nodes[i].children[j] << " ";
		cout <<endl;
	}	
	cout << "LEAVES : " <<node::leaf;	
}

void getRemovedLeaves(node& cur){
	int n = cur.children.size();
	if(n==0){
		node::leaf--;
		return;
	}
	while(n)
		getRemovedLeaves(*cur.children[--n]);	
}

int main(void){
	cin >> N;	
	Nodes = new node[N];
	node::leaf = N;
	
	int p,d; 
	for(size_t i=0; i<N; i++){
		cin >> p; 
		if(p!=-1){
			if(!Nodes[p].children.size()) node::leaf--;
			Nodes[p].children.push_back(&Nodes[i]);
			Nodes[i].parent = &Nodes[p];
		}
	}	
		
//	print_tree();
	
	cin >> d;
	getRemovedLeaves(Nodes[d]);	
	
	if(Nodes[d].parent!=nullptr) {
	 	if(Nodes[d].parent->children.size()==1) 
		 	node::leaf++;
	}
	cout << node::leaf;
	return 0;
}
