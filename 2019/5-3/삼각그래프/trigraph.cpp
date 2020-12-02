#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(void){
	vector <int*> map;
	ifstream ifs("1.txt");
	int N, dummy, cnt=0;
	
	while( ifs >> N ){
	if(N==0) break;
	cnt++;
	map.resize(N);

	for(int i=0; i<N; i++){
			map[i] = new int[3];
			for(int j=0; j<3; j++) 	ifs >> map[i][j];	
	}
	for(int i=1; i<N; i++){
		if(i==1){
			for(int j=0; j<3; j++)
				map[i][j]+=map[i-1][1];
		}
		else if(i==N-1)
			map[i][1]+= *min_element( map[i-1],map[i-1]+3);
		else	{
			map[i][0] += *min_element( map[i-1],map[i-1]+2);
			map[i][1] += *min_element( map[i-1],map[i-1]+3);
			map[i][2] += *min_element( map[i-1]+1,map[i-1]+3);
		}
	}	
	cout << cnt <<". " << map[N-1][1]<<endl;
	for(int i=0; i<N; i++) delete map[i];
	}
	return 0;
}
