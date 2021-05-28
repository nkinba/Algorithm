#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int ans = 0;
int N, a, b, lt, gt;
vector<pii> l;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	l.resize(N);
	
	for(int i=0; i<N; i++){
		cin >> a >> b;
		lt = min(a,b);
		gt = max(a,b);
		l[i] = pii(lt, gt);
	}
	
	sort(l.begin(), l.end());
	
//	for(pii lp : l) cout << lp.first << " to "<< lp.second <<endl;
	
	int left = l[0].first;
	int right = l[0].second;
	
	for(int i=1; i<N; i++){
		if(l[i].first > right){
			ans += (right - left);
			right = l[i].second;
			left = l[i].first;
		}
		else if(right < l[i].second)
			right = l[i].second;
	}
	ans += ( right - left);
	cout << ans;
	return 0;
}
