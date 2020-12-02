#include <iostream>

#include <algorithm>

using namespace std;

void print(int* a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] <<" ";
	cout <<endl;
	return ;	
}

void next(int* p, int n){
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
//1 1 1 0 0 0 0 0 0 0
//1 1 0 1 0 0 0 0 0 0
//1 1 0 0 1 0 0 0 0 0
//...
//1 1 0 0 0 0 0 0 0 1
//1 0 1 1 0 0 0 0 0 0
//...
//1 0 0 0 0 0 0 0 1 1
//0 1 1 1 0 0 0 0 0 0
//...
int main(){
//	int a[10] = {1,2,3,4,5,6,7,8,9,10};
//	print(a,10);
//	next_permutation(a, a+4);
//		print(a,10);
//
//	next_permutation(a+1, a+6);
//	print(a,10);
	int p[10] ={1,1,1,0,0,0,0,0,0,0};
	for(int i=0; i<120; i++){
		next(p,10);
		print(p,10);
	
	}	

	return 0;
}
