#include <iostream>
#include <vector>

using namespace std;

string T,P;
vector<int> pi;
vector<int> answer;

int main(void){
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	
	getline(cin, T);
	getline(cin, P);
	pi.resize(P.size());
		
	for(int i=1, j=0; i<P.size(); i++){
		while(j > 0 && P[j] != P[i])
			j = pi[j-1];
		if(P[j] == P[i])
			pi[i] = ++j;
	}
	
//	for(int i=0; i<P.size(); i++)
//	cout << pi[i] ;
	
	for(int t=0, p=0; t<T.size(); t++){
		while(p > 0 && P[p] != T[t]) 
			p = pi[p-1];
		if(T[t] == P[p]){
			if(p == P.size()-1){
				answer.push_back(t - (P.size()-1) + 1);
				p = pi[p];			
			}
			else p++;
		}
	}	
	
	cout << answer.size() << '\n';
	for(int i : answer)
		cout << i << " ";
	
	return 0;
}
