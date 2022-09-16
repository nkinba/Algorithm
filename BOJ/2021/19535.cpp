#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, f, t;
int maxNodeNum = 300000;
ll Ds = 0, Gs = 0;
vector<vector<int>> links;
vector<int> GCandidatesDegree;

ll factorial[300001], factorialInv[300001];
ll mod = 1e9+7;

ll mpow(ll x,ll m) {
    if(!m) return 1;
	
    ll tmp = mpow(x,m/2);
    tmp = tmp * tmp % mod;
    
	if(m % 2) return tmp*x%mod;
    return tmp;
}
 
ll comb(ll x,ll r) {
    return factorial[x] * factorialInv[r]
	 % mod * factorialInv[x-r] % mod;
}

void countD(int parent, int siblings, int cur) {
	int deg = links[cur].size();
	if(deg == 1 && cur != 1) {
		return;
	}
	
	Ds += siblings * (links[cur].size() - 1);
	
	for(int next : links[cur]) {
		if(next != parent) {
			countD(cur, links[cur].size() - 1, next);
		}
	}	
	
	return;
}

void countG() {
	for(auto& link : links) {
		if(link.size() >= 3) {
			GCandidatesDegree.push_back(link.size());
		}
	}
	
	for(int degree : GCandidatesDegree) {
		Gs += comb(degree, 3);
	}
	
	return;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	factorial[0] = 1;
    for(int i=1; i<=maxNodeNum; i++) {
		factorial[i] = factorial[i-1] * i % mod;
   	}
   	
    factorialInv[maxNodeNum] = mpow(factorial[maxNodeNum],mod-2);
    for(int i=maxNodeNum-1; i>=0; i--) {
		factorialInv[i] = factorialInv[i+1] * (i+1) % mod;
	}
	
	cin >> N;
	links.resize(N+1);

	for(size_t i=0; i<N-1; i++) {
		cin >> f >> t;
		links[f].push_back(t);
		links[t].push_back(f);
	}

	countD(0, 0, 1);
	countG();
	
//	cout << Ds << " vs " << Gs <<endl;
	
	if(Ds == 3 * Gs) {
		cout << "DUDUDUNGA";
	} else {
		cout << ((Ds > 3 * Gs) ? "D" : "G");
	}
 	
	return 0;
}
