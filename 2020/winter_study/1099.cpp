/* 1099 알 수 없는 문장 
	1988KB	0ms	C++14 	1822B
	
	 왜 정답률이 낮은 지 모르겠다 메모리를 1000KB 미만으로 들인 제출자가 많던데 
    단어를 정렬한 string 벡터를 따로 두었기 때문인 듯하다. 
	 입출력 C 스타일로 하지 않고 string 과 cin,cout 을 썼는데도 시간은 0ms가 나옴. 
	
*/
 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef string s;

s S;	 					// 문장 
vector<s> Words(50);  		// 원래 단어의 벡터 
vector<s> Sorteds(50); 		// 알파벳 오름차순 정렬된 단어의 벡터 
vector<int> Costs(50, -1); 	// 단어 별 비용 
int N;						// 단어 개수  

int getDiff(s A, int beg){ 	// 문장의 beg위치부터와 단어 A 간에 알파벳 차이 수
	int diff=0;
	for(int i=0; i<A.size(); i++){
		if(S[beg+i]!=A[i]) diff++;
	} 
	return diff;
}

int CheckWords(int pos){
	if(Costs[pos]!=-1) return Costs[pos];
	
	int Min = S.size()+1;
	
	for(size_t i=0; i<N; i++){  // 단어 배열을 돈다. 
		int nextpos = pos + Sorteds[i].size();
		if(nextpos < S.size()) {	
			 s Piece = S.substr(pos, Sorteds[i].size());  						// 단어의 크기 만큼 현 위치 부터 문장을 자릅니다 
			sort(Piece.begin(), Piece.end());
			if(!Piece.compare(Sorteds[i])){   									// 자른 문장 조각과 단어를 정렬한 게 서로 같은 지 비교 
					int cost = getDiff(Words[i], pos);  
					Min = min(Min , cost + CheckWords(pos+Sorteds[i].size() )); // 현재의 비용 + 문장을 이어서 계속했을 때의 반환값 
			} 
		}
		else if(nextpos == S.size()){
			s Piece = S.substr(pos, Sorteds[i].size()); 	 // 단어의 크기 만큼 현 위치 부터 문장을 자릅니다 
			sort(Piece.begin(), Piece.end());
			if(!Piece.compare(Sorteds[i])){ 			 	 // 자른 문장 조각과 단어를 정렬한 게 서로 같은 지 비교
					int cost = getDiff(Words[i], pos);  
					Min = min(Min , cost); 				   	 // 현재의 비용만 처리  
			} 
		}
	}

	Costs[pos] = Min;
	return Costs[pos];
}

int main(){
	cin >> S >> N;
	s inp;
	for(size_t i=0; i<N; i++){
		cin >> inp;
		Words[i] = inp;
		sort(inp.begin(), inp.end());
		Sorteds[i]=inp;
	}
	
	int answer = CheckWords(0);	
	if(answer > S.size()) cout << -1;
	else cout << answer;
	return 0;
} 
