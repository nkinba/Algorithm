/* 2871 아름다운 단어 Test Case Generator */

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int N;
int main(){
	cin >> N;
	if(!(2<=N && N<=100000)){
		cout << " (2 ≤ N ≤ 100 000)" ; exit(-1);
	}
	
	ofstream ofs("2871tc.txt");
	
	srand((unsigned int)time(NULL));

	
	ofs << N <<endl;
	size_t i;
	for(i=0; i<N; i++){
		ofs <<(char)(rand()%26 + 97);
	}
	
	ofs.close();
	
	
	return 0;
} 
