#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int N, max=0;
	cin >> N;
    vector<int> boxes(N,0);
	vector<int> count(N,1);
	for(int i=0; i<N; i++)
		cin >> boxes[i]; 
		
	for(int i=1; i<N; i++){
		int cnt=1;
		for(int j=0; j<i; j++){
			if(boxes[j]<boxes[i] && cnt<count[j]+1) 
				cnt = count[j]+1;
		}	
		count[i]=cnt;
		if(max<cnt) max=cnt;
	}
	cout << max;
	return 0;
}
