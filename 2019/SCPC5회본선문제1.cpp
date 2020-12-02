#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

		// int bit32[3125]; //100,000bits = 3125 x 32bitmask

int main(void)
{
    int T, 
	N, 
	M, Ans;
    int x, y;
    cin >> T;

    // for(int bitmask : bit32)
    // bitmask&=0;

    for (int testCase = 0; testCase < T; ++testCase)
 {
	cin >> N >> M;		// 회원 수 와 조사 결과
	// 1~32 1
	// 33~64 2 
	// int bitMask[(N-1)/32 + 1];
	// for(int i=0; i<((N-1)/32+1); ++i){
	// bitMask[i] &= 0;
	// cout << bitset<32> (bitMask[i]) <<endl;
	// }
	vector < int >mem[N];
	vector < int >::iterator it;
	for (int i = 0; i < N; ++i)
	    mem[i] = vector < int >();

	for (int i = 0; i < M; ++i) {
	    cin >> x >> y;
	    mem[x - 1].push_back(y);}

	// for(int i=0; i<N; ++i){
	// cout << i+1 << " have : "<<endl;
	// for(int j=0; j<mem[i].size(); ++j){
	// cout << mem[i][j] << " ";
	// }
	// cout <<endl;
	// }
	// 


	int cpl = 0;
	for (int i = 0; i < N; ++i) {
	    for (int j = 0; j < mem[i].size(); ++j) {
		int t = mem[i][j];
		// cout << i << " " << j << " " << t <<endl;
		it = find(mem[t - 1].begin(), mem[t - 1].end(), i + 1);
		if (it != mem[t - 1].end()) {
		    cpl++;
		    break;
		}
	    }
	}

	Ans = N - cpl;

	cout << "Case#" << testCase + 1 << endl;
	cout << Ans << endl;
    }

    return 0;
}
