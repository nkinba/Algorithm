#include <bits/stdc++.h>

using namespace std;

char expr[51];
int ops[51];
int oprnd = 0;
bool isAdd = true;
int sum = 0;
 
int main(){
	cin >> expr;
	for(size_t i=0; expr[i]!='\0'; i++){
		if(48 > expr[i] || expr[i] > 57){
			sum += (isAdd ? oprnd : -oprnd);
			oprnd = 0;	
			if(expr[i]=='-' && isAdd == true) isAdd = false;
		}
		else {
			if (oprnd != 0) oprnd *= 10;
			oprnd += (expr[i]-48);
		} 
	}
	
	sum += (isAdd ? oprnd : -oprnd);
	cout << sum << endl;

	return 0;
}
