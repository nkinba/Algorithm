#include <bits/stdc++.h>

using namespace std;

int main(void){
	int c = 1;
	int i = 666;
	int n; cin >> n;

	while(c < n){
		i++;
		string str = to_string(i);
		int idx= str.find("666");
		if(0 <= idx && idx <= str.length()-1)
			c++;	
	}
	 
	cout << i;
	return 0;
}
