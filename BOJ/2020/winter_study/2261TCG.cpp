//2261 TCG

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;
int n;
char str[30] ="2261tc_";
int main(void){
		
//	cout << ceil(1.79) <<endl;
//	cout << ceil(-1.79) <<endl;
//	cout << floor(1.79) <<endl;
//	cout << floor(-1.79) <<endl;
	cin >> n;
	
	if( !(2<=n  && n<=100000)){
		cout << "2<= n <=100000";
		return -1;
	}

	time_t curtime;
	struct tm tm;
	curtime = time(NULL);
	tm = *localtime(&curtime);
	sprintf(str, "2261TC_%d\%d\%d_%d\%d\%d.txt", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
       tm.tm_hour, tm.tm_min, tm.tm_sec);
	cout << string(str).c_str()<<endl;
	
	ofstream ofs;
	ofs.open(string(str).c_str()); 
	if(!ofs.is_open()){
		cout << "file open error";
		return -1;
	}
	ofs << n <<endl;
	
	srand((unsigned int)time(NULL));
	for(int i=0; i<n; i++){
		ofs << rand()%1501 - 500 << " " << rand()%1501 - 500<<endl;
	}
	
	ofs.close();
	return 0;
	
}
