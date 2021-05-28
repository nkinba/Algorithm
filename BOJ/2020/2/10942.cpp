//헤더를 bits/stdc++.h 를 사용하지 않고 
//빠른 입출력 위한 코드를 사용했더니 통과되었음. 
// (100만번 입출력) 
// Manacher's Algorithm

#include <iostream>

using namespace std;

int palinLen[4000]={0,};
int nums[4000];
int N,M,s,e;

void setPalinLen(){
	int r=0, p=0;
	int _N = 2*N-1;
	for(int i=1; i<= _N ; i++){
		if(i<=r) palinLen[i] = min(palinLen[2*p-i], r-i);
		else palinLen[i] = 0;
		while(i-palinLen[i]-1 > 0 && i+palinLen[i]+1 <= _N 
		 	&& nums[i-palinLen[i]-1] == nums[i+palinLen[i]+1])
		palinLen[i]++;
		if( r<i+palinLen[i]){
		 r= i+palinLen[i];
		 p=i;	
		}
	}
}

int isPalin(int s, int e){
	if(s==e) return 1;
	int mid = ((2*e-1)+ (2*s-1))/2;
	return (palinLen[mid] >= ((2*e-1) - (2*s-1))/2)  
			? (1) : (0);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	 
	cin >> N;
	for(size_t i=1; i<2*N; i+=2)
		cin >> nums[i];
	for(size_t i=2; i<2*N-1; i+=2)
		nums[i] = N+1;
	for(size_t i=1; i<2*N; i++)
	 cout << nums[i] << " ";
	 cout <<endl;
	 
	setPalinLen();
	for(int i=1; i<2*N; i++) cout << palinLen[i] << " ";
	cout <<endl;
	
	cin >> M;
	for(size_t i=0; i<M; i++){
		cin >> s >> e;
		cout << isPalin(s,e) <<'\n';
	}
	
	return 0;
}
