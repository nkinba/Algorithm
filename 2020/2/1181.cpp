#include <bits/stdc++.h>

using namespace std;

string words[20000];

bool func(const string& a, const string& b){	
	return (a.length() == b.length())
	 ? (a < b) 
	 : (a.length() < b.length()); 
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> words[i];
	sort(words, words+n, func);
	
	string printedStr = "";
	for(int i=0; i<n; i++) {
		if( printedStr != words[i] ){
			cout << words[i] << "\n";
			printedStr = words[i];
		}
	}
		
	// sort -> unique -> erase (중복제거)	

	return 0;
}
