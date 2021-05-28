/* 3109 »§Áý Test Case Generator */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int R,C; 
int main(){
	cin >> R >> C;
	if(!(1<=R && R <= 10000) &&  !(5<=C && C <= 500)){
		cout << " (1 ¡Â R ¡Â 10,000, 5 ¡Â C ¡Â 500)" ; exit(-1);
	}
	
	ofstream ofs("3109tc.txt");
	
	srand((unsigned int)time(NULL));

	
	ofs << R <<" "<< C << endl;

	for(int i=0; i<R; i++){
		ofs<<".";
		for(int j=1; j<C-1; j++){
			if(rand()%3) ofs<<"." ;
			else ofs << "x";
		}
		ofs<<".";
		ofs <<endl;
	}
	
	ofs.close();
	
	
	return 0;
} 
