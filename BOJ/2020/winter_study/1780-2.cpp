// 1780-1 종이의 개수 
//	
 
#include <iostream>
#include <vector>

using namespace std;

vector<int> Sht; 	// 1차원 배열로 표현된 전체 종이 
int N; 				// 변의 길이 
int ShtNumArr[3] = {0,0,0};

void print(){
	for(size_t i=0; i<N*N; i++){
		cout << Sht[i] << " ";
		if(i%N==N-1) cout << endl;
	}
}

void DivAndConq(int rb, int cb, int n){
	
	size_t r,c;
	int P = Sht[rb*N+cb];
	
	for(r=rb; r<rb+n; r++){
		for(c=cb; c<cb+n; c++){
//			cout << P << " vs " << Sht[r*N+c] <<endl;
			if(Sht[r*N+c] != P)
				break;
		}
		if(c!=cb+n) break;
	}
	
	if(r==rb+n && c==cb+n){
//		cout << endl << "Complete." << endl << "Len = " << n <<endl;
//		cout << "Start pos = (" << rb << " , " << cb << ")" <<endl;
//		cout << P+1 << "++" <<endl;
		ShtNumArr[P+1]++;	
	}
	
	
		
	else{
		int rp = (r-rb)/(n/3); 
		int cp = (c-cb)/(n/3);
		int start = 0;
		if( rp > 0 ) {
			ShtNumArr[P+1]+=(rp*3);
			if( cp > 0 ) ShtNumArr[P+1]+=cp;	
			start = rp*3+cp;
		}
//		cout << endl << "Incomplete." << endl << "Len = " << n <<endl;
//		if(rp > 0){
//			cout << "Get part, row = (" << rp << ") , col = (" << cp << ")" <<endl;
//			cout << P+1 << "+" << rp << "x3 +" << cp << endl;
//		}
		
		for(size_t i=start; i<9; i++){
			DivAndConq(rb+(i/3)*(n/3), cb+(i%3)*(n/3), n/3);
		}
	}
	
}

int main(void){
	
	cin >> N;
	Sht = vector<int>(N*N);
	for(size_t i=0; i<N*N; i++)
		cin >> Sht[i];
	
//	print();
	DivAndConq(0,0,N); 
	cout << ShtNumArr[0]<<endl;
	cout << ShtNumArr[1]<<endl;
	cout << ShtNumArr[2]<<endl;
	return 0; 
}
