#include <bits/stdc++.h>

using namespace std;

int N,maxx = 1000000001, minn;
int nums[11]; 
int ops[4];

void comp(int cur){
	if(maxx == 1000000001){ 
		maxx = minn = cur;
		return;
	}

	if(cur < minn) minn = cur;
	if(maxx < cur) maxx = cur;
	
	return;
}

int calc(int cur, int opIdx, int next){
	int ret;
	if(opIdx == 0) ret = cur + next;
	else if(opIdx == 1) ret = cur - next;
	else if(opIdx == 2) ret = cur * next;
	else if(opIdx == 3) ret = cur / next;
	return ret;
}

void f(int idx, int cur){
	
	if(idx==N-1) {
		comp(cur);
		return;
	}
	
	for(size_t i=0; i<4; i++){
		if(ops[i]>0){
			ops[i]--;
			f(idx+1 , calc(cur, i, nums[idx+1]));
			ops[i]++;
		} 
	}
	
}

int main(){
	cin >> N;
	for(size_t i=0; i<N; i++) cin >> nums[i];
	cin >> ops[0] >> ops[1] >>ops[2] >>ops[3];
	
	f(0,nums[0]);
	cout << maxx << "\n" << minn;
	return 0;
}
