#include <bits/stdc++.h>

using namespace std;

int N, K;

struct Trie {
	bool isTerminal;
	map<string, Trie*> children;
	
	Trie() : isTerminal(false){}
	~Trie(){
		map<string, Trie*>::iterator it;
		for(it = children.begin(); it != children.end(); it++)
		  delete it->second;
	}
	
	void insert(const string* info){
		if(*info == "\0") isTerminal = true;
		else {
			if(children.find(*info) == children.end())
				children[*info] = new Trie();
			children[*info]->insert(info+1);
		}
	}
	
	Trie* find(const string* info){
		if(*info == "\0") return this;
		if(children.find(*info) == children.end())
			return NULL;
		return children[*info]->find(info+1);
	}
	
//	bool member_exist(const string* info){
//		if(*info == "\0" && isTerminal) return true;
//		if(children.find(*info) == children.end())
//			return false;
//		return children[*info]->member_exist(info+1);
//	}
	
	void printChildren(int lv, const string& fruit){
		if(lv > 0){
			for(int i=0; i<2*(lv-1); i++) cout <<'-';
			cout << fruit << '\n';
		}
		map<string, Trie*>::iterator it;
		for(it = children.begin(); it != children.end(); ++it)
			it->second->printChildren(lv+1, it->first);
			
		return;
	}
	
};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Trie* root = new Trie();
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> K;
		string info[K+1];
		for(int j=0; j<K; j++)
			cin >> info[j];
		info[K] = "\0";
		root->insert(info);
	}
	root->printChildren(0, "");
	
	return 0;
}
