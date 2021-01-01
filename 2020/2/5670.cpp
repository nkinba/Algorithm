// 소멸자와 delete 함수를 동시 선언할 시 에러 발생
// delete가 소멸자를 호출 

#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N;
string inpStr;
int cnts;
 
struct Trie {
	bool isTerm;
	Trie* children[26];
	int childrenCnt;
	
	Trie() : isTerm(false), childrenCnt(0) {
		fill(children, children+26, nullptr);
	}

//	~Trie(){
//		for(int i = 0; i < 26; i++){
//				if(children[i])
//					delete children[i];
//		}
//	}
	
	void insert(const string& str, int restChar){
		if(restChar == 0) {
			isTerm = true;
			return;
		}	
		int alphabetIdx = str[str.size() - restChar] - 97;
		
		if(children[alphabetIdx] == nullptr){
			children[alphabetIdx] = new Trie();
			childrenCnt++;
		}
		
		children[alphabetIdx]->insert(str, restChar-1);
		
		return;
	}
	
	bool isMember(const string& str, int restChar){
		if(restChar == 0)
		 	return (isTerm) ? true : false;
				
		int alphabetIdx = str[str.size() - restChar] - 97;

		if(children[alphabetIdx] != 0)
			return children[alphabetIdx]->isMember(str, restChar-1);
	
		return false;
	}
	
	void deleteAll(){
		for(int i=0; i<26; i++){
			if(children[i] != nullptr){
				children[i]->deleteAll();
				delete children[i];
			}
		}
		return;
	}
	
	void getPushCounts(int curCnt){
		if(isTerm) 
			cnts += curCnt;
		
		if( (isTerm && children > 0) || (childrenCnt > 1) ) 
			curCnt += 1;
			
		for(int i=0; i<26; i++){
			if(children[i] != nullptr) 
				children[i]->getPushCounts(curCnt);
		}
		return;
	} 
	
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	
	Trie* root;
	while(cin >> N){
		cnts = 0;
		root = new Trie();
		FOR(n, 1, N){
			cin >> inpStr; 
			root->insert(inpStr, inpStr.size());
			
		}
		
		root->isTerm = true;
		root->getPushCounts(0);
		
//		cout << cnts << " , "<< N << endl;
		cout << ((double)(cnts))/N << '\n';
		
		root->deleteAll();	
		delete root;
	}
	
	return 0;
}
