/* 5588 별자리 찾기  
	1988KB	0ms	C++14 
*/

#include <iostream>
#include <algorithm>
#include <set>

#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
int m,n;
pii ste[200];
set<pii> sta;

int main(void){

	int X,Y;
	cin >> m;
	for(int i=0; i<m; i++)
		cin >> ste[i].x >> ste[i].y;
	sort(ste, ste+m);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> X >> Y;
		sta.insert(pii(X,Y));
	}

	set<pii>::iterator si;
	for(si = sta.begin(); si != sta.end(); si++){
//		cout << "START FROM " << si->x << " " << si->y<<endl;
		int i;
		for(i=1; i<m; i++){
			int xd = ste[i].x - ste[0].x;
			int yd = ste[i].y - ste[0].y;
//			cout << "NOW LOOKING AT " << si->x + xd << " " << si->y+ yd<<endl;

			if((sta.find(pii(si->x + xd , si->y+ yd))) == sta.end())
				break;
		}
		if(i==m){
//		 	cout<< "MOVEMENT : " << ste[0].x - si->x  << " , " << ste[0].y - si->y<<endl;	 
		 	cout << si->x - ste[0].x  << " " << si->y -  ste[0].y <<endl;	 
			break;
		}
	}

	return 0;
}
