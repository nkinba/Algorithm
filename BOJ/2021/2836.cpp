#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll ans = 0;
int N, M, a, b;
vector<pii> revs;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for(int i=0; i<N; i++) {
		cin >> a >> b;
		if(a > b) 
			revs.emplace_back(pii(b,a));
	}
	sort(revs.begin(), revs.end());
	
	int left = revs[0].first;
	int right = revs[0].second;
	
	for(int i=1; i<revs.size(); i++){
		if(revs[i].first > right){
			ans += (right - left);
			right = revs[i].second;
			left = revs[i].first;
		}
		else if(right < revs[i].second)
			right = revs[i].second;
	}
	ans += ( right - left);
	ans *= 2;
	ans += M;
	cout << ans;
	
	return 0;
}
