#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void){
	int N,i,j,max=0;
	vector <int*> tri;
//	ifstream ifs("1.txt");
//	ofstream ofs("1.out");
	cin >> N;
	
	for(i=0; i<N; ++i){
		tri.push_back(new int[i+1]);
		for(j=0; j<=i; ++j){
			cin>>tri[i][j];
			if(i>0){
				if(j==0) tri[i][j] += tri[i-1][j];
				else if(j==i) tri[i][j] += tri[i-1][j-1];
				else 	
				tri[i][j] += (tri[i-1][j-1] >= tri[i-1][j] ) ? tri[i-1][j-1] : tri[i-1][j];
				//(tri[i-1][j-1] >= tri[i-1][j] ) ? (tri[i][j] += tri[i-1][j-1]) : (tri[i][j]+=tri[i-1][j]);  
			}
			if(max < tri[i][j]) max =tri[i][j];
		}		
	}
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<=i; ++j)
			cout << tri[i][j] << " ";
		cout <<endl;
 	}
		for(i=0; i<N; ++i) delete tri[i];

 	cout << max ;
	return 0;
	
}
