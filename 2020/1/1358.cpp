/*1358 гое╟
 1984KB	0ms	C++14 
*/

#include <iostream>
#include <cmath>

using namespace std;
typedef pair<int,int> pii;

int W,H,X,Y,P;
 
int main(void){
	cin >> W >> H >> X >> Y >> P;

	int x,y,n=0;
	for(int i=0; i<P; i++){
		cin >> x >> y;
		if( X <= x && x <= X+W ){
			if( Y <= y && y <= Y+H)	 n++;
		}
		else if( X - H/2 <= x && x < X){
			if( pow(x - X, 2) + pow(y- Y-H/2, 2) <= (H/2)*(H/2)) n++; 	// (x- X)^2 + (y- Y-H/2)^2 <= (H/2)^2
		}
		else if( X+W < x && x <= X+W + H/2){
			if( pow(x - X-W, 2) + pow(y- Y-H/2, 2) <= (H/2)*(H/2)) 	n++; 	// (x- X-W)^2 + (y- Y-H/2)^2 <= (H/2)^2
		} 
	}		

	cout << n;

	return 0;
}
