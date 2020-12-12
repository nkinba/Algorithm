// 유니온 파인드, 시간을 줄일 수 있는 방법을 찾아보자
//https://www.acmicpc.net/problem/4195
 
#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef pair<string, int> pis;

int T, F;
string c1, c2;
map<string, pis> CHARS;

pis findRoot(string node){
	if(CHARS[node].first == node) return CHARS[node];
	return CHARS[node] = findRoot(CHARS[node].first); 
}

int uni(){
	if(CHARS[c1].first == "") CHARS[c1] = pis(c1, 1);
	if(CHARS[c2].first == "") CHARS[c2] = pis(c2, 1);
	
	pis r1 = findRoot(c1);
	pis r2 = findRoot(c2);
//	cout << c1 << " 's root : " << r1.first<<endl;
//	cout << c2 << " 's root : " << r2.first<<endl;
	if(r1.first < r2.first){
		CHARS[r1.first] = pis(r1.first, r1.second + r2.second);
		CHARS[r2.first] = pis(r1.first, r2.second);
		return r1.second + r2.second;
	} 
	else if(r1.first > r2.first){
		CHARS[r2.first] = pis(r2.first, r2.second + r1.second);
		CHARS[r1.first] = pis(r2.first, r1.second);
		return r1.second + r2.second;
	}
	
	else return r1.second;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for(int t=0; t<T; t++){
		CHARS.clear();
		cin >> F;
		for(int i=1; i<=F; i++){
			cin >> c1 >> c2;
			cout << uni() << '\n';
		}
	
	}
	return 0;
} 
