#include <iostream>
#include <stdlib.h>

using namespace std;

long long fac[200000];
long long P = 1000000007;

long long pow(long long a, long long p)
{
   long long res = 1;
   
   a %= P;
   while (p > 0) {   
        if (p % 2) {
            res *= a;       
            res %= P;   
        }
        a *= a;
        a %= P;
        p /= 2;
    }
    return res;
}

void factorial (void) {
   fac[0] = 1;
   for(long long i=1; i<200000; ++i) {
      fac[i] = fac[i-1]*i;
      fac[i] %= P;
   }
}

int main(void){
	factorial();
	int N=4,M=2;
	long long L=0;
	for(int i=0; i<1000; ++i, N+=N+M, M+=M){
		 L = ( ( fac[N+M+2] * pow(fac[N+1]*fac[M+1], P-2) %P) %P) -1;
		 cout << L <<endl;		
	}
	return 0;
}
