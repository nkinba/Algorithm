#include <bits/stdc++.h>

#define x get<0>
#define y get<1>
#define w get<2>

using namespace std;

typedef tuple<int,int,int> point;

int N;
vector<point> points;
vector<vector<int>> diagWeights;
 
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	points.resize(N);
	diagWeights.resize(N);
	
	for(auto& p : points) {
		cin >> x(p) >> y(p) >> w(p);		
	}

	sort(points.begin(), points.end());
	
	for(size_t i=0; i<N; i++) {
		diagWeights[i].resize(2);
		diagWeights[i][0] = diagWeights[i][1] = w(points[i]);
		// 0: 13,  1: 24
	}
	
	for(size_t i=1; i<N; i++) {
		point& cp = points[i];
		for(size_t j=0; j<i; j++) {
			if(y(cp) < y(points[j])) {
				diagWeights[i][0] = max(diagWeights[i][0], diagWeights[j][0] + w(cp));
			} else {
				diagWeights[i][1] = max(diagWeights[i][1], diagWeights[j][1] + w(cp));
			}
		}
	}

	int answer = 0;
	for(auto& weight : diagWeights){
		answer = max(answer, max(weight[0], weight[1]));
	}
	cout << answer;

	return 0;
}
