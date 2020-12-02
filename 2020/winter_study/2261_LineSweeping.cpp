//2261 가장 가까운 두 점 
//	4352KB	136ms 	C++14 	1540B
// Line Sweeping 을 활용
// binary search로 구현된 STL set의 upper_bound, lower_bound 사용 

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

#define X first
#define Y second

using namespace std;

typedef pair<int,int> pi; 

int dist(pi a, pi b){ 
	return pow(b.Y-a.Y , 2) + pow(b.X - a.X , 2);
}

int main(void){
	int n;
	set<pi> targetSet; 
	vector<pi> points;
	
	cin >> n;
	
	for(size_t i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		points.push_back(make_pair(x,y));
	}
	
	sort(points.begin(), points.end());
	
//	for(size_t i=0; i<n; i++){
//		cout << starts[i].X << " " << starts[i].Y <<endl;
// 	}

	int MIN = dist(points[0], points[1]);
	int targetIndex= 0;
	targetSet.insert(pi(points[0].Y, points[0].X)); 
	targetSet.insert(pi(points[1].Y, points[1].X));
	
	for(size_t i=2; i<n; i++){
		while( targetIndex < i ){
			bool isInRange = (points[i].X - points[targetIndex].X <= sqrt(MIN));
			if(isInRange) break; // 검사할 점 발견
			else { // x값 차이가 현재 최소 길이를 넘으면 검사할 필요 x, target를 옮긴다. 
				targetSet.erase(pi(points[targetIndex].Y, points[targetIndex].X));
				targetIndex++; 
			}
		}
		
		//검사할 점과 점으로부터 +- sqrt(Min) 만큼 범위에 있는 점들 간의 거리를 check한다 ,
		// set에는 검사할 점보다 큰 x좌표의 점은 들어가 있지 않다.
		double limit = sqrt(MIN);
		for(auto it=targetSet.lower_bound(pi(points[i].Y - limit, -INT_MAX ));  
		         it!=targetSet.upper_bound(pi(points[i].Y + limit, INT_MAX));  
				 it++ )
		{
			MIN = min(MIN, dist(pi(it->Y, it->X), points[i]));	
		} 
		targetSet.insert(pi(points[i].Y, points[i].X));
	}
	
	cout << MIN;
	
	return 0;
}
