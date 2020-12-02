#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

using namespace std;

typedef unsigned val_t;

const val_t N= 100;
const val_t M= 100;

class primality {
	val_t* md; 	// max divisor
	size_t alen;
	size_t num_p;
public : 
	primality(val_t max_v)
		: num_p(0), alen(max_v+1),md(new val_t[max_v+1]) {
			fill(md,md+alen,1);
			md[0] = 0;
			md[1] = 0;
			num_p = 0; 
			for(val_t v=2; v<=max_v; ++v)
				if(md[v]==1){ // if v is a prime number,
					for(val_t w=v*v; w<=max_v; ++w)
						if(md[w]==1)
							md[w] = w/v;	
					++num_p;
				}
		}
		
	~primality(void) { delete[] md; }
	
	bool is_prime(int n) const {
		return md[n]==1;
	}
	size_t num_primes(void) const{
		return num_p;
	}
	void print_primes(void) const {
		for(val_t v=0; v<=N+M; ++v)
	 		if(is_prime(v))
				cout << v << ' ';
		cout << endl;		
	}
	
	val_t max_divisor(val_t v) const {
		if(v>=alen)
			throw out_of_range("invalid val_t value");
		return md[v];
	}
	vector<val_t> prime_factors(val_t v)const {
		vector<val_t> temp;
		if(v==0 || v==1) return temp;
		val_t w=v;	
		do{
			val_t max_d = max_divisor(v);
			val_t prime_factor = v / max_d;
			temp.push_back(prime_factor);
			if(max_d==1) break;
		}while(true);	
		return temp;
	}
	
	vector<val_t> prime_factors_of_factorial(val_t v)const{
		if(v==0 || v==1) return vector<val_t>(1,1);
		vector<val_t> temp;
		for(;v>1;--v){
			do{
				val_t max_d = max_divisor(v);
				val_t prime_factor = v / max_d;
				temp.push_back(prime_factor);
				if(max_d==1) break;
				//w=max_d;
			}while(true);	
		}
		return temp;
	}
	
	void subtract(vector<val_t>& dst, vector<val_t>& src){
		size_t j=0;
		for(size_t i=0,k=0; i<dst.size();++i){
			if(k>=src.size() || dst[i]!=src[k])
				dst[j++] = dst[i];
			if(k<src.size() && dst[i] >=src[k])
				++k;		 
		}
	dst.resize(j);
	}
};	

int main(void){
	vector<val_t> dst= {2,2,2,3,3,5,5,5};
	vector<val_t> src= {2,2,3,3,5};
	subtract(dst,src);
	copy(dst.begin(),dst.end(),ostream_iterator<val_t>(cout, " "));
	cout << endl;
/*
	primality p(N+M); //prime test for values in [0, N+M]
	cout << p.num_primes() <<endl;
	vector<val_t> temp;
	for(val_t v=0;v<=N+M;++v){
		cout << v << ": ";
		temp = p.prime_factors(v);
		copy(temp.begin(),temp.end(), ostream_iterator<val_t>(cout, " "));
		cout << endl;		
	}
//	p.print_primes();
*/
	return 0;
}
