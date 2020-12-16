/*
//https://www.acmicpc.net/problem/9252 (LCS2)
// 2차원 배열에 드 문자열의 해당 위치(i,j)에서의 LCS를 저장하는
// 메모리를 매우 많이 드는 방식...
//----------------------------------------------------------------- 
#include <iostream>
#include <string>

#define FOR(i,b,e) for(int i=b; i<=e; i++)

using namespace std;

typedef pair<int, string> pis;

string str1, str2;
pis MAP[1001][1001];

void f(){
	FOR(i, 1, str1.size()){
		FOR(j, 1, str2.size()){
			if(str1[i-1] == str2[j-1])
				MAP[i][j] = pis( MAP[i-1][j-1].first + 1, MAP[i-1][j-1].second + str1[i-1]);
			else 
				MAP[i][j] = ( ( MAP[i-1][j].first >= MAP[i][j-1].first)
							? ( MAP[i-1][j])	
							: ( MAP[i][j-1] )
							);
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	FOR(i, 0, 1000) fill(MAP[i], MAP[i]+1001, pis(0, "\n") );
	
	cin >> str1 >> str2;
	f();
	cout 
	<< MAP[str1.size()][str2.size()].first 
	<< MAP[str1.size()][str2.size()].second;

	return 0;
}
//----------------------------------------------------------------- 

// 훨씬 빠르고 메모리를 적게 차지하는 방식( 타 코드복사 ) 1992KB 4ms

#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using word = unsigned long long;
using pi = pair<int, int>;
const int MAXN = 100005;

struct bset{
	vector<word> wd;
	bset(){}
	bset(int n){
		wd.resize(n / 64 + 2);
	}
	void set(int x){
		wd[x >> 6] |= (word(1) << (x & 63));
	}
	void reset(int x){
	    wd[x >> 6] = 0;
	}
	bool get(int x){
		return (wd[x >> 6] >> (x & 63)) & 1;
	}
	bset operator-(const bset &b){
		assert(sz(b.wd) == sz(wd));
		bset ret; ret.wd.resize(sz(wd));
		bool carry_bit = 0;
		for(int i=0; i<sz(wd); i++){
			ret.wd[i] = wd[i] - (b.wd[i] + carry_bit);
			carry_bit = (ret.wd[i] > wd[i] || (ret.wd[i] == wd[i] && carry_bit));
		}
		return ret;
	}
	bset operator^(const bset &b){
		assert(sz(b.wd) == sz(wd));
		bset ret; ret.wd.resize(sz(wd));
		for(int i=0; i<sz(wd); i++){
			ret.wd[i] = wd[i] ^ b.wd[i];
		}
		return ret;
	}
	bset operator|(const bset &b){
		bset ret; ret.wd.resize(sz(b.wd));
		for(int i=0; i<sz(b.wd); i++){
			ret.wd[i] = wd[i] | b.wd[i];
		}
		return ret;
	}
	bset operator&(const bset &b){
		assert(sz(b.wd) == sz(wd));
		bset ret; ret.wd.resize(sz(wd));
		for(int i=0; i<sz(wd); i++){
			ret.wd[i] = wd[i] & b.wd[i];
		}
		return ret;
	}
	void shift(){
		for(int i=sz(wd)-1; i>=0; i--){
			wd[i] <<= 1;
			if(i && (wd[i - 1] >> 63)) wd[i] ^= 1;
		}
	}
};

string s, t, ans;
bset alph[26];
bool use[26];

vector<int> get_lcs(string s, string t){
	int n = sz(s);
	int m = sz(t);
	for(int i=0; i<m; i++){
	    use[t[i] - 'A'] = 1;
		alph[t[i] - 'A'].set(i);
	}
	bset B(sz(t));
	for(int i=0; i<n; i++){
		bset y = B; y.shift(); y.set(0);
		bset x = (use[s[i] - 'A'] ? (alph[s[i] - 'A'] | B) : B);
		B = x ^ (x & (x - y));
	}
	vector<int> cur(m + 1);
	int cnt = 0;
	for(int i=0; i<m; i++){
		if(B.get(i )) cnt++;
		cur[i + 1] = cnt;
	}
	for(int i=0; i<m; i++){
		alph[t[i] - 'A'].reset(i);
		use[t[i] - 'A'] = 0;
	}
	return cur;
}

void solve(int l1, int r1, int l2, int r2){
	if(r1 - l1 == 1){
		if(find(t.begin() + l2, t.begin() + r2, s[l1]) != t.begin() + r2) ans.push_back(s[l1]);
		return;
	}
	int m = (l1 + r1) / 2;
	string x = s.substr(l1, m - l1);
	string y = s.substr(m, r1 - m);
	string z = t.substr(l2, r2 - l2);
	auto tab1 = get_lcs(x, z);
	reverse(all(y));
	reverse(all(z));
	auto tab2 = get_lcs(y, z);
	reverse(all(tab2));
	pi ans(-1e9, 1e9);
	for(int i=0; i<=sz(z); i++){
		ans = max(ans, pi(tab1[i] + tab2[i], i + l2));
	}
	solve(l1, m, l2, ans.second);
	solve(m, r1, ans.second, r2);
}

int main(){
	cin >> s >> t;
	for(int i=0; i<26; i++) alph[i] = bset(sz(t));
	solve(0, sz(s), 0, sz(t));
	cout << sz(ans) << endl;
	cout << ans << endl;
}
*/
//-------------------------------------------------------
// 0ms
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char sa[1001], sb[1001], lcs[1001];
int alen, blen, d[2][1001];
bool kk[1000][1000];

int main() {
  int i, j;
  scanf("%s %s", sa, sb);
  alen = strlen(sa);
  blen = strlen(sb);
  
  for(i=0; i<alen; ++i) {
    for(j=0; j<blen; ++j) {
      int r = d[i&1][j+1];
      if(r < d[~i&1][j]) {
        kk[i][j] = true;
        r=d[~i&1][j];
      }
      if(sa[i] == sb[j]) r = max(r, d[i&1][j]+1);
      d[~i&1][j+1] = r;
    }
  }
//  
//  for(i=0; i<2; i++){
//  	for(j=0; j<blen; j++)
//  		cout << d[i][j] ;
//  		cout <<endl;
//  } 
// 
//  for(i=0; i<alen; i++){
//  	for(j=0; j<blen; j++)
//  		cout << kk[i][j] <<" ";
//  		cout <<endl;
//  } 
  
  
  int ans = d[alen&1][blen];
  printf("%d\n", ans);
  
  i=alen-1, j=blen-1;
  while(ans) {
    if(sa[i] == sb[j]) lcs[--ans] = sa[i], --i, --j;
    else if(kk[i][j]) --j;
    else --i;
  }
  puts(lcs);
  return 0;
}
