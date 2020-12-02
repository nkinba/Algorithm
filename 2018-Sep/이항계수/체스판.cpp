#include <iostream>
#include <stdexcept>
#include <set>

using namespace std;

typedef unsigned val_t;
typedef unsigned long long big_t;

const val_t MAX_N = 100000;
const val_t MAX_M = 100000;
const val_t MAX_V = MAX_N + MAX_M;

class pos{
	val_t r,c;
public:
	pos(val_t rr, val_t cc):r(rr), c(cc){}
	val_t row()const {return r;}
	val_t col()const {return c;}
	bool operator<(const pos& ps) const{
		return r<ps.r || r==ps.r && c<ps.c;
	}
	bool operator==(const pos& ps) const{
		return r==ps.r && c==ps.c;
	}
	bool operator!=(const pos& ps) const{
		return r!=ps.r  && c!=ps.c;
	}
	friend ostream&
	operator<<(ostream& os, const pos& ps) {
		return os << "( "<< ps.r << ", " << ps.c <<" )";
	}	
};
/*
val_t path1(const pos& src, const pos& dst)
{
	val_t N = dst.row()-src.row()+1;
	val_t M = dst.col()-src.col()+1;
	val_t v[N][M];
	
	for(val_t c=0; c<M; ++c)
		v[0][c] = 1;
	for(val_t r=0; r<N; ++r)
		v[r][0] = 1;

	for(val_t r=1; r<N; ++r)
		for(val_t c=1; c<M; ++c)
			v[r][c] = v[r-1][c] + v[r][c-1];
	return v[dst.row()-src.row()][dst.col()-src.col()];
} 
*/


val_t fact[MAX_V + 1];
const val_t P = 1000000007;

inline val_t mul(val_t v, val_t w)
{
	return val_t((big_t)v * (big_t)w % (big_t )P ) ;
}

void make_fact(void)
{
	fact[0]=1;
	for(val_t i=1;i<=MAX_V;++i)
		fact[i] = mul(fact[i-1] , i);
}

val_t power(val_t a, val_t b)
{
	if(b==0) return 1;
	val_t half = power(a,b/2);
	val_t rv = mul(half,half);
	if(b%2!=0) rv =mul(rv,a);
		return rv;
}

val_t comb(val_t n, val_t k) // combination
{
	val_t nom= fact[n]; //nominator
	val_t den= mul(fact[k], fact[n-k]); // de''
	val_t inv = power(den, (P-2));  // inverse
	return mul(nom, inv);	
}

val_t rand(val_t min_v, val_t max_v)
{
	return rand()%(max_v - min_v + 1)+min_v;
}

val_t path2(const pos& src, const pos& dst)
{
	val_t Row = dst.row()-src.row();
	val_t Col = dst.col()-src.col();
	return comb(Row+Col,Col);
}

int main(void){
	make_fact();
	set<pos> obs;	
	val_t n; val_t m;

	
	obs.insert(pos(2,2));
	
	cout << comb(n+m-2, m-1) - mul(comb(n+m-2-2-2 , m-1-2), comb(4,2)) <<endl;

	val_t srcToObs = path2(pos(0,0), pos(2,2));
	val_t obsToDst = path2(pos(2,2), pos(n-1,m-1)); 
	val_t srcToDst = path2(pos(0,0) , pos(n-1,m-1)); 
	cout << srcToDst - mul(srcToObs, obsToDst) <<endl;
	cout << comb(10,5) ;
	
	
	
	return 0;
}
