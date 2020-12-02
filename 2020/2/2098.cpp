#include <bits/stdc++.h>
#define MAX 16000001
using namespace std; 

int N;
int cost[16][16];
int visited = 0;
int minCost[16][65536] = {{0,},};
int cityCnt;

int TSP(int city){

//    cout <<"NOW INTO CITY :" << city<< ", VISITED : " << bitset<4>(visited)<<endl;
	if( (visited == cityCnt-2 )){
		int last = (cost[city][0] ? cost[city][0] : MAX);
//		cout << "LAST " << last << endl;
		return last; 
	}

	int& rst = minCost[city][visited];
	if(rst){
//		cout << "DP EXIST "<< rst <<endl;
		return rst;
	} 
	
	rst = MAX;
	for(int i = 1; i < N; i++){
		if(  !(visited & (1<<i)) && (cost[city][i] > 0) ){
			if(minCost[city][visited | (1 << i)] < MAX) {
				visited |= (1 << i);
				int next = TSP(i);
				rst = min(rst, cost[city][i] + next);
				visited ^= (1 << i); 
			}
		}
	}
	
//	cout << "DP NOT EXIST "<< rst <<endl;

	return rst;

}

int main(void){
	cin >> N;
	cityCnt = pow(2,N);
	for(int f = 0; f < N; f++){
		for(int d = 0; d < N; d++)
			cin >> cost[f][d];
	}
	
	TSP(0);
	cout << minCost[0][0];
//	cout << minCost;
//	for(int i=1; i< minCost.size(); i++)
//		cout << minCost[i]<<endl;
		
//	cout << answer;
	return 0;
}
