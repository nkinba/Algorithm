/* 1967번 트리의 지름 
	리프노드로부터 타고 올라가면서 각 노드의 간선 중 최대 가중치 간선 을 구하는 일 O(N)	 
	다시 타고 내려가면서 각 노드에서의 최대 가중치 합 구하는 일 O(N)  (간선 두 개 선택해서 가중치 합과 자식 노드의 최대 가중치 간선 더한다)  
	틀려서 아직 미해결
	https://www.acmicpc.net/problem/1967 
 
*/
 
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
 
int N;
struct node{
	int num = 1; 			// 노드 번호 
	node* p = nullptr;  // 부모 노드 포인터  
	vector<node*> c;    // 자식 노드 포인터 벡터 
	vector<int> g;	    // 자식 노드로의 가중치 
	
	node(){}			// 디폴트 생성자 
	
	node(node* pa, int num, int val){  // 부모노드 포인터 ,  노드 번호, 가중치 
		this->p = pa;
		this->num = num;
		pa->g.push_back(val);
	}
};

map<int, node> Nodes;			// 전체 노드 
map<int, int> maxBranch;      // 각 노드에서 자식으로의 최대 가중치 


void print_tree(){
	map<int,node>::iterator it;

	for(it=Nodes.begin(); it!=Nodes.end(); it++){
		cout << "------------------------------"<<endl;
		cout << "NUM : " << it->first<<endl;
		node& n = it->second;
		if(n.p!=nullptr)
			cout << "PARENT : " <<  n.p->num <<endl;
		cout << "CHILDREN : ";
		for(size_t i=0; i<n.c.size(); i++)
			cout << n.c[i]->num << " ";
		cout <<endl;
		cout << "WEIGHTS : ";
		for(size_t i=0; i<n.g.size(); i++)
			cout << n.g[i]<< " ";
		cout <<endl;
	}
}

// maxBranch를 완성시킨다 
void getMaxBranchWeight(){	
	map<int,node>::reverse_iterator rit;
	for(rit = Nodes.rbegin(); rit!=Nodes.rend(); rit++){
		int m = 0;
		node& n = rit->second;
		for(size_t i=0; i<n.g.size(); i++){
			m = max(m, n.g[i]+maxBranch[n.c[i]->num]);	
		}
		maxBranch[n.num] = m;
	}
}

int getLongestPath(){
	int m = 0;
	map<int,node>::iterator it;
	it = Nodes.begin();
	if(it->second.c.size()==1){
		m = max(m, maxBranch[1]);
		it++;
	}

	for( ; it != Nodes.end(); it++){
		node& n = it->second;
		if(n.c.size() > 1){
			set<int, greater<int> > weights;	
			for(size_t i=0; i<n.g.size(); i++){
				weights.insert(n.g[i] + maxBranch[n.c[i]->num]);			
			}
			set<int>::iterator sit = weights.begin();
			int r,l; r= *(sit++); l = *sit;
//			cout << "NOW : " << n.num << " , " << r << " + " << l <<endl;
			m = max(m, r+l);
//			m = max(m, *(sit++) + *sit);
		}
	}
		
	return m;
} 

int main(){
	cin >> N;
	Nodes[1] = node();
	
	int p,c,g;
	for(size_t i=1; i<N; i++){
		cin >> p >> c >> g;
		Nodes[c] = node(&(Nodes[p]), c, g);
	    (Nodes[p].c).push_back(&Nodes[c]);
	}	
	
//	print_tree();
	
	getMaxBranchWeight();	
	
//	for(size_t i=0; i<maxBranch.size(); i++)
//		cout << i<<" : " <<maxBranch[i] <<endl;
	cout << getLongestPath();

	return 0;
}
