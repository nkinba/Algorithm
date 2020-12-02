/* 1991 트리 순회 
0ms 단순한 트리 순회. 중위 전위 후위순회 구현 
구조체와 멤버 변수로 포인터를 사용해 메모리가 많이 들었지만 이후에 트리 관련 문제 풀 때 갖다 쓸 수 있을 것이라 생각 
https://www.acmicpc.net/problem/1991 
*/
#include <iostream>

using namespace std;

int N;

struct node{
	char val;
	node* left;
	node* right;

	node(){
	}

	node(char v, node* l, node* r){
		val = v;
		left = l;
		right = r;
	}
};

node* Nodes;

void print_tree(){
	for(size_t i=0; i<N; i++){
		cout << Nodes[i].val << " " <<Nodes[i].left->val << " " << Nodes[i].right->val << endl;
	}		
}

void inorder_traversal(node& R){
	// v l r
	cout << R.val;
	if(isalpha(R.left->val))
		inorder_traversal(*R.left);
	if(isalpha(R.right->val))
		inorder_traversal(*R.right);
	
}

void preorder_traversal(node& R){
	// l v r
	if(isalpha(R.left->val))
		preorder_traversal(*R.left);
	cout << R.val;
	if(isalpha(R.right->val))
		preorder_traversal(*R.right);
	
}
void postorder_traversal(node& R){
	// l r v
	if(isalpha(R.left->val))
		postorder_traversal(*R.left);
	if(isalpha(R.right->val))
		postorder_traversal(*R.right);
	cout << R.val;
}

int main(void){
	cin >> N;	
	Nodes = new node[N];
	char v,l,r;
	for(size_t i=0; i<N; i++){
		cin >> v >> l >> r;
		Nodes[v-65] = node(v, &Nodes[l-65], &Nodes[r-65]);
	}	

	node root = Nodes[0];
//	print_tree();
	inorder_traversal(root); cout <<endl;
	preorder_traversal(root); cout <<endl;
	postorder_traversal(root);	cout <<endl;
		
	return 0;
}
