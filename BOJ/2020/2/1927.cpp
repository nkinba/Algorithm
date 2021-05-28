#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>>  Q;
int N,e;

void proc(int e){
	if(e) Q.push(e);
	else if(Q.empty())
		cout << 0 <<'\n';
	else {
		 cout << Q.top() << '\n';
		 Q.pop();
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> e;
		proc(e);
	}
	return 0;
}
