#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
map<int, vector<pii>*> targetMap;
vector<vector<pii>> targets;
pii shark;
int N, v;

int main(void){
	cin >> N;
	for(size_t i=0; i<N; i++){
		for(size_t j=0; j<N; j++){
			cin >> v;
			if(!targetMap[v]){
				targets.push_back(vector<pii>(1, pii(i,j)));
				targetMap[v] = &(targets.back());
			} else {
				targetMap[v]->push_back(pii(i,j));
			}
		}
	}
	
	for(auto& it : targetMap){
	 cout << it.first << " ";
	}
	

	return 0;
}
