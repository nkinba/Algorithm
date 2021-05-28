#include <bits/stdc++.h>

using namespace std;

int n, cases;
char inp;
string basis, target;

vector<int> makePi(const string& str){
	vector<int> pi(n, 0);
	int i,j = 0;
	for(i=1; i < n; i++){
		while(j > 0 && str[i] != str[j] )
			j = pi[j-1];
		if(str[i] == str[j])
			pi[i] = ++j;
	}
	
	return pi;
}

int kmp(const string& from, const string& target){
	vector<int> pi = makePi(target);
	vector<int> rst;
	
	int i, j=0;
	for(i=0; i < from.size(); i++){
		while(j > 0 && from[i] != target[j] )
			j = pi[j-1];
			
		if(from[i] == target[j]){
			if(++j == n)
				rst.push_back(i - (pi.size() - 1) + 1);
		}
	}
	
	return rst.size();
}

int getGCD(int a, int b){
  	if (a < b)
        swap(a, b);

    while (b != 0)
    {
             int temp = a % b;
             a = b;
             b = temp;
    }
    return a;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> inp;
		basis += inp;
	}
	for(int i = 0; i < n; i++){
		cin >> inp;
		target += inp;
	}
	
	cases = kmp(basis + basis.substr(0, basis.size()-1), target);

	int gcd =  getGCD(n, cases);
	
	cout << cases/gcd << "/" << n/gcd;
	
	return 0;
}
