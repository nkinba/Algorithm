#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ofstream ofs("11657HardCase.txt");
    int n = 500, m = 6000;
    ofs << n << " " << m << "\n";
    for (int i = 0; i < m; ++i) 
 	   ofs <<1+i%2  <<" "<<  1+(i+1)%2 << " "<< -10000<< '\n';
}
