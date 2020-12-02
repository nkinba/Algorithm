#include <iostream>
#include <algorithm>

using namespace std;

int N,C;
int b,e,m,s,cnt;
int H[200000];

int bs(){
	b = 1;
	e = H[N-1] - H[0];
	m;
	while(b <= e){
		cnt = 1;
		m = (b+e)/2;
	    s = 0;
	    for(int i=1; i<N; i++){
	    	if(H[i] - H[s] >= m) {
				cnt++;
				s = i;
			}
		}
		if(cnt >= C) b = m+1;
		else e = m-1;   
	}	
	return e;
}

int main(void){
	
	scanf("%d%d", &N, &C);
	
	for(int i=0; i<N; i++) 
		scanf("%d", H+i);
	sort(H, H+N);
	
	printf("%d", bs());
	return 0;
}
