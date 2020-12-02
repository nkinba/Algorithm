#include <iostream>
#include <functional>

using namespace std;

int Answer;
long long P = 1000000007;
long long fac[2000002];

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
   long long m_num;
   fac[0] = 1;
   for(long long i=1; i<2000002; ++i) {
      fac[i] = fac[i-1]*i;
      fac[i] %= P;
   }
}

int main(int argc, char** argv)
{
   int T, test_case;
//   freopen("input.txt", "r", stdin); 
   cin >> T;
   factorial(); 
   for(test_case = 0; test_case  < T; test_case++)
   {
      Answer = 0;
      size_t N, M;
      
      cin >> N >> M;
   
      Answer += ( ( fac[N+M+2] * pow(fac[N+1]*fac[M+1], P-2) %P) %P) -1;
      cout << "Case #" << test_case+1 << endl;
      cout << Answer << endl;
   }
   return 0;
}
