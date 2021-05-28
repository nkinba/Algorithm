// 기존 runtime error 발생 이유. 
// 트리를 linked list가 아닌 array로 할 시 
// 편향 트리일 경우 index가 2^10000 까지 올라갈 수 있다.
// 노드위 수가 10,000 개 이하이지, 노드 번호가 10,000까지라고
// 명시되어 있지는 않다. 
 
#include <iostream>

using namespace std;

int inp;
struct node{
	node(int n) : num(n), left(nullptr), right(nullptr) {}
	node* left;
	node* right;
	int num;
}; 
node* root;

void traverse(node* curNode){
	if(curNode->left != nullptr)
		traverse(curNode->left);
	if(curNode->right != nullptr)
		traverse(curNode->right);
	cout << curNode->num << '\n';
	return;
}

node* insert(node* curNode){
	if(curNode == nullptr){
		curNode = new node(inp);
		return curNode;
	}	
	
	if(curNode->num > inp){
		if(curNode->left == nullptr)
			curNode->left = insert(curNode->left);
		else insert(curNode->left);
	}
	else {
		if(curNode->right == nullptr)
			curNode->right = insert(curNode->right);
		else insert(curNode->right);
	}
	return curNode;
}

int main(void){
	
	cin >> inp;
	root = new node(inp);
	
	while(cin >> inp) 
		insert(root);
		
	traverse(root);

	return 0;
}
