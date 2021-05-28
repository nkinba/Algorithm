/* 1937 욕심쟁이 판다 Test Case Generator */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int n;
int main(){
	cin >> n;
	if(!(1<=n && n<=500)){
		cout << "1<=n<=500" ; exit(-1);
	}
	
	ofstream ofs("1937tc.txt");
	
	srand((unsigned int)time(NULL));
	
	int val[n*n]; 
	
	ofs << n <<endl;
	int tmp=1; 
	int d =n-1;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
/* 난수 */ 
//			ofs << rand()%1000001 << " ";

/* 지그재그 */		
			if(i%2==0)
				ofs << (tmp++) << " ";
			else{
				ofs << (tmp++)+d << " ";  
				d-=2;
			}
		}
		ofs <<endl;
		d = n-1;
	}
	
	ofs.close();
	
	
	return 0;
} 
