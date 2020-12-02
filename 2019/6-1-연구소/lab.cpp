#include <iostream>
//52ms
using namespace std;

int Max_safe=0;

void next(int* p, int n){   // nC3 조합에서 다음 수열 구하기  
	int cnt=1;		 
	for(int i=n-1; i>=0; i--){
		if(p[i]==1){
			if(i==n-1){
				if(p[i-1]==1) {
					for(int j=n-1; j>=0; j--){
						if(p[j]==1){
						 	p[j]=0;
							 cnt++;
						}
						else {
							if(cnt==4) return;
							int k;
							for(k=j; k>=0; k--)
								if(p[k]==1) break;
							p[k]=0; 
							for(int l=1; l<=cnt; l++)		
								p[k+l]=1;
							break;
						}
					}
				}
				else{
					p[i]=0;
					int j;
					for(j=i-1; p[j]!=1 && j>=0; j--);
					p[j++]=0; 				
					p[j++]=1; p[j]=1;
			
				}		
			}
			else{
				p[i]=0;
				p[i+1]=1;
				break;
			}	
		break;
		}
	}
	return;
}

int comb(int n, int k){ // nCk 조합 구하기  { n/1*(n-1)/2*(n-3)/3 ...*(n-k)/k} 
	int c=1;
	for(int i=0; i<k; i++){
		c*=(n-i); 	
		c/=(i+1);
	}
	return c;
}

void dfs(int** lab, int& safe, int i, int j, int max_x, int max_y){
	// 바이러스가 퍼져나가는 함수 , 이전의 safe 값보다 작아지면 return  
	lab[i][j]=3; safe--; 

				if( i-1>=0 && lab[i-1][j]==0){
					if(safe < Max_safe) return;
					dfs(lab ,safe, i-1 , j, max_x, max_y);
				}
				if( j-1>=0 && lab[i][j-1]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i , j-1, max_x, max_y);
				}
				if( j+1 <= max_y-1 && lab[i][j+1]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i , j+1, max_x, max_y);
				}
				if( i+1 <= max_x-1 && lab[i+1][j]==0){
					if(safe < Max_safe) return;
					dfs(lab, safe, i+1 ,j, max_x, max_y);
				}
	return;
}


int gogoVirus(int** lab, int x, int y, int zeronum){
  // 바이러스 스타트  
	int safe = zeronum;
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			if(lab[i][j]==2){
				if( i-1>=0 && lab[i-1][j]==0)	dfs(lab ,safe, i-1 , j, x, y);
				
				if( j-1>=0 && lab[i][j-1]==0)	dfs(lab, safe, i , j-1, x, y);
				
				if( j+1 <= y-1 && lab[i][j+1]==0)	dfs(lab, safe, i , j+1, x, y);

				if( i+1 <= x-1 && lab[i+1][j]==0)	dfs(lab, safe, i+1 ,j, x, y);	
			}						
		}
	}
	// 퍼진 바이러스 소멸  
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++)
			if(lab[i][j]==3) lab[i][j]=0;		
	}
	return safe;
}


int main(void){
	int x,y, numzero=0; 	// x,y는 행,렬 numzero는 행렬에서 0의 개수  
	int** lab; 				// 연구소 행렬 
	int* zero; int* pick;   
	// zero는 numzero길이만큼의 0 배열
	// pick은 연구소행렬을 1차원 배열로 보았을 때  0인 부분의 인덱스값을 저장
	// 둘은 길이가 같고 zero 배열에서 0->1이 되었을 때 pick에서 
	// zero배열과 같은 인덱스에 위치한 값(연구소행렬의 인덱스값)을 사용하도록 하였음 
	cin >> x >> y;
	zero = new int[x*y];
	pick = new int[x*y];
	lab = new int*[x];
	for(int i=0;i<x;i++){
		lab[i]= new int[y]; 
		for(int j=0; j<y; j++){
			cin >> lab[i][j]; 
			if(lab[i][j]==0){
				pick[numzero]=i*y+j;
				zero[numzero++]=0;	
			} 
		}
	}
	zero[0]++; zero[1]++; zero[2]++; // 1 1 1 0 0 0 0... 0 0 0

	int num = comb(numzero,3);  // num : numzero C 3 ( 행렬의 0들중에서 3개의 벽(1)을 세울 수 있는 경우의 수) 
	for(int i=0; i < num; i++){
	
		//벽을 세웁니다	
		for(int i=0;i<numzero;i++){
			int pos;
			if(zero[i]==1) {
				pos = pick[i];
				lab[(pos/y)][(pos%y)]=1;
			}
		}

		int s = gogoVirus(lab, x,y, numzero-3);
		if(s > Max_safe) Max_safe = s;
	
		//벽을 뿌십니다 		
		for(int i=0;i<numzero;i++){
			int pos;
			if(zero[i]==1) pos = pick[i];
			lab[(pos/y)][(pos%y)]=0;
		}		 
		next(zero, numzero); // 벽 세우는 다음 방 법  
	}
	cout << Max_safe;

	return 0;
}

