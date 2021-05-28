// 하노이 탑 이동 순서와 이동 횟수 

#include <iostream>

using namespace std;

void hanoi(int n, int f, int t, int o){

	if(n==1){
		cout << f << " " << t << "\n";
		return;
	}
	
	hanoi(n-1, f, o, t);
	
	cout << f << " " << t << "\n";
		
	hanoi(n-1, o, t, f);
}

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);				

	int inp, c;
	cin >> inp;
		
	c = (1 << inp) - 1;
	cout << c <<"\n";
	hanoi(inp,1,3,2);

	return 0;
}
