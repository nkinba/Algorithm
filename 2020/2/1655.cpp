#include <bits/stdc++.h>

using namespace std;

priority_queue<int> LOWER; // 최대가 TOP  
priority_queue<int, vector<int>, greater<int>>  UPPER; // 최소가 TOP  

int N,e;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	
	cin >> e;
	cout << e <<'\n';
	LOWER.push(e);
	
	for(int i=1; i<N; i++){
		cin >> e;
		if(LOWER.size() > UPPER.size()){				 
			if(LOWER.top() <= e) UPPER.push(e);
			else {
				UPPER.push(LOWER.top());
				LOWER.pop();
				LOWER.push(e);
			}
			cout << min(LOWER.top(), UPPER.top())<<"\n";
		}
		else if(LOWER.size() < UPPER.size()){		
			if(UPPER.top() >= e) LOWER.push(e);
			else {
				LOWER.push(UPPER.top());
				UPPER.pop();
				UPPER.push(e);
			}
			cout << min(LOWER.top(), UPPER.top())<<"\n";
		}
		else{		   
			if(LOWER.top() >= e){ 
  				LOWER.push(e);
				cout << LOWER.top()<<'\n';
			}
			else {
				UPPER.push(e);
				cout << UPPER.top()<<'\n';
			}
		}
	}
	
	return 0;
}
