#include <iostream>
#include <algorithm>

using namespace std;
 
int maxProf[20][301];
int prof[301][20];
int selected[20][301];

int N,M;

void process(int company){

	for(int i=0; i<=N; i++){
		//b[3] = max(a[0]+b[3], a[1]+b[2]..
		int res = 0; 
		int sel = 0;
		for(int j=0; j<=i; j++){
			int compared = maxProf[company-1][j] + prof[i-j][company];
			if(res < compared){
				sel = j;
				res = compared;
			}			
		}
		selected[company][i] = sel;
		maxProf[company][i] = res;
	}
	
}

int main(void){
	cin >> N >> M;
	for(int i=0; i<=N; i++){
		if(i!=0) cin >> i;
		for(int j=0; j<M; j++){
			if(i==0) prof[i][j] = 0;
			else cin >> prof[i][j];
		}
	}
	
	for(int i=0; i<=N; i++){
		maxProf[0][i] = prof[i][0];
		selected[0][i] = -1;	
	}
	
	for(int i=1; i<M; i++)		
		process(i);
		
	cout << "               ";
	for(int i=0; i<=N; i++)
		cout << i<<"\t";
	cout<<endl;
	for(int i=0; i<M; i++){
		cout << i<<"th company :\t";
		for(int j=0; j<=N; j++)
			cout << maxProf[i][j]<<"\t";
		cout <<endl;			
	}
	cout <<endl;
	cout << "               ";
	for(int i=0; i<=N; i++)
		cout << i<<"\t";
	cout<<endl;
	for(int i=0; i<M; i++){
		cout << i<<"th selectd :\t";
		for(int j=0; j<=N; j++)
			cout << selected[i][j]<<"\t";
		cout <<endl;			
	}
}
