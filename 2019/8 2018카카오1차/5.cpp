/* 뉴스 클러스터링 - 윤수 */ 
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int gyo=0, hab=0;	
int alen=0, blen=0;

int compare( const void* str1, const void* str2){
	char* a = *(char**)str1;
	char* b = *(char**)str2;
	
	if(a[0] < b[0]) return -1;
	else if( a[0] > b[0]) return 1;
	else return a[1]-b[1];
}

void cal(char** A, char** B){
	int ia=0, ib=0;
	while(A[ia]!='\0' && B[ib]!='\0'){
		cout << A[ia] << " vs " << B[ib] <<endl;
		int cmp = strcmp(A[ia], B[ib]);
		cout << "cmp : " <<cmp <<endl;
		
		if(cmp < 0) { ++ia; ++hab;  }
		else if(cmp > 0){ ++ib; ++hab;	}
		else{ ++ia; ++ib; ++gyo;  ++hab; }

	}
	cout << ia << " " << ib <<endl;
	if(A[ia]=='\0')	hab+=(blen-ib);
	else if(B[ia]=='\0') hab+=(alen-ia);
	
	cout << "gyo : " << gyo << " " << "hab :" << hab <<endl;
	return;
}

double Jak(char** A, char** B){
	if(alen == 0 && blen == 0 ) return 65536;
	
	qsort(A, alen, sizeof(char*), compare ); 
	qsort(B, blen, sizeof(char*), compare ); 
		
		cout << "after sort" <<endl;
		for(int i=0; i<alen; ++i)
		cout << A[i] <<endl;
	cout <<endl;
	for(int i=0; i<blen; ++i)
		cout << B[i] <<endl;
		
		cout << endl;
		
	cal(A,B);
	return 65536*(double(gyo)/ double(hab));
}

int process(char* str, char** A){
	int idx=1, jdx=0;
	while(str[idx]!='\0'){
		if(isalpha(str[idx-1]) && isalpha(str[idx])){
			A[jdx] = new char[3];
			A[jdx][0] = toupper(str[idx-1]);
			A[jdx][1] = toupper(str[idx]);
			A[jdx][2] = '\0';  // 실수한 부분  
			jdx++;
		}		
		idx++; 
	}
	return jdx;
}

int main(){
	
	char* str1 = new char[1000]; 
	char* str2 = new char[1000];
	char** A = new char*[1000];
	char** B = new char*[1000];
	cin.getline(str1,1000);
	cin.getline(str2,1000);	
	alen = process(str1, A);
	blen = process(str2, B);
	
	cout << alen << endl << blen <<endl;	
	cout << str1 <<endl; 
	cout << str2 <<endl;
	
	delete str1; delete str2;
		
	cout << "before sort" <<endl;
	for(int i=0; i<alen; ++i)
		cout << A[i] <<endl;
	cout <<endl;

	for(int i=0; i<blen; ++i)
		cout << B[i] <<endl;
	cout <<endl << endl;

	cout << (int)Jak(A, B);
	delete A; delete B;
	return 0;
}
