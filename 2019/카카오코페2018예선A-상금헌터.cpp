//2017
//1 500 1
//2 300 2
//3 200 3
//4  50 4
//5  30 5
//6  10 6
//      21Έν 
//
//2018
//1 512 1
//2 256 2
//3 128 4
//4  64 8
//5  32 16
//       31Έν 

#include <iostream>

using namespace std;

int check17(int rank){
	if(!rank) return 0;
	int i,s=0;
	for(i=1; i<=6; ++i){
		s+=i;
		if(rank<=s)
			break;
	}	
	if(i==7) return 0;
	return i;
}

int check18(int rank){
	if(!rank) return 0;
	int i;
	for(i=1; i<=5; ++i){
		if(rank<= (1 << i)-1)
			break;
	}
	if(i==6) return 0;
	return i;
}

int main(){
	int T,a,b;
	cin >> T;
	
	int p17[7] = {0,500,300,200,50,30,10};
	int p18[6] = {0,512,256,128,64,32};
	int prize[T];
	
	for(size_t i=0; i<T; ++i){
		cin >> a >> b;
		prize[i] = p17[check17(a)] + p18[check18(b)];
	}	
	for(int p : prize)
		cout << p*10000 <<endl;
	
	return 0;
}


