// 유의할 점..  size가 고정된 char array에 cin을 통해
// 입력을 처리할 시 clang(c++17) 에서는 통과가 되지만
// gcc(c++17)에서는 통과가 되지 않는다. 
// 그래서 string을 사용하는 것으로 코드를 수정하였음.
  
#include <bits/stdc++.h>
#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

int N, M, cnt = 0;
//char inpStr[500];
string inpStr;
 
struct Trie {
	bool isTerm;
	Trie* children[26];

	Trie() : isTerm(false) {
		fill(children, children+26, nullptr);
	}

	~Trie(){
		for(int i = 0; i < 26; i++){
				if(children[i])
					delete children[i];
		}
	}
	
	void insert(const string& str, int restChar){
		if(restChar == 0) {
			isTerm = true;
			return;
		}	
		int alphabetIdx = str[str.size() - restChar] - 97;
		if(children[alphabetIdx] == nullptr)
			children[alphabetIdx] = new Trie();
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
	
//	void printChildren(int lv, char str){
//		if(lv > 0){
//			for(int i=0; i<2*(lv-1); i++) cout <<'-';
//			cout << str << '\n';
//		}
//		for(int i = 0; i < 26; i++){
//			if(children[i])
//				children[i]->printChildren(lv+1, i + 97 );
//		}
//			
//		return;
//	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Trie* root = new Trie();
	cin >> N >> M;
	FOR(n, 1, N){
		cin >> inpStr; 
//		root->insert(inpStr);
		root->insert(inpStr, inpStr.size());
//		root->printChildren(0, 0);
	}
	FOR(m, 1, M){
		cin >> inpStr;
		if(root->isMember(inpStr, inpStr.size())) cnt++;
	}
	
	cout << cnt;
	return 0;
}
