#include <iostream>
#include <cmath>
#include <limits>

typedef std::numeric_limits<double> dbl;

using namespace std;

double X,Y,D,T;

int main(void){
	cin >> X >> Y >> D >> T;
	cout.precision(dbl::max_digits10);
	double l =  sqrt(X*X + Y*Y);
	
	if( D <= T ) cout << l;
	else{
		if(D >= l) {
			cout << "FIRST CASE "<<endl;
			double inCourse = l;
			double outCourse = (D - l) + T;
			cout << "IN : " << inCourse << " OUT :  " <<outCourse<<endl;
			cout << min(inCourse, outCourse);
		}
		else {			cout << "SECOND CASE "<<endl;

			double inCourse = T*(l/D) + (l - l/D);
			cout << "D : " << D << " , l : " << l << " ,  l/D : " << (int)l/(int)D <<endl;
			double outCourse =   (D - (l - D*(l/D))) + T*(l/D + 1);
						cout << "IN : " << inCourse << " OUT :  " <<outCourse<<endl;

			cout << min(inCourse, outCourse);	
		}
	} 
	
	return 0;
	
	
}
