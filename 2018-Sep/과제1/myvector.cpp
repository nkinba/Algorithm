#include <iostream>

using namespace std;

template <class T>
 
class carray{
	size_t alen, slen;
	T* vc;
public: 
    static T* cpy(const T* b, const T* e, T* d) {
      T* dst = d;
      for(const T* it=b;it!=e;++it)
         *dst++=*it;
      return dst;
    }
   
 	carray(void) : alen(0), slen(0), vc(0){}

	carray(T* beg, T* end) : slen(end-beg),alen(1) {
		for(;alen<slen;alen*=2)
		vc = new T[alen];
		cpy(beg,end,vc);		
	}

   carray(const carray& ca)
      : slen(ca.slen),alen(1) {
      for(;alen<slen;alen*=2);
      vc = new T[alen];
      cpy(ca.vc, ca.vc+ca.slen,vc);
   }
   
	~carray(void) {
		if(vc!=0) delete vc;
	}
	
	size_t size() const {
		return slen;
	}
	size_t capacity() const{
		return alen;
	}
	
	void resize(size_t new_len) {
		if(alen==new_len) return;
		T* tmp = new T[new_len];
		if(slen<=new_len){
			cpy(vc,vc+slen,tmp);
		}
		else{
			cpy(vc,vc+new_len,tmp);
		}
		delete vc;
		vc= tmp; 
	}
	
	carray& operator=(const carray& ca){
		if(ca.vc==vc) return *this;
		if(vc!=0) delete vc;
		vc = new T[ca.alen];
		cpy(ca.vc,ca.vc+ca.slen,vc);
		slen=ca.slen; alen=ca.alen;
		return *this;
	}
	
	T* operator->(void){
		return vc;
	}
	T& operator[](size_t idx){
		return vc[idx];
	}
	T operator[] (size_t idx)const{
		return vc[idx];
	}
	
	friend ostream&
	operator<<(ostream& os, const carray& ca){
		for(size_t i=0; i<ca.slen; ++i){
			os << ca.vc[i] << " " ;
		}
		os << "size: " << ca.size() << " capacity: " << ca.capacity();
		return os;
	}
	class riter;
	//iterator
	class iter{
		T* ptr;
	public:
		iter(T* p=0):ptr(p) {}
	 
		bool operator!=(const iter& it) const { return ptr!=it.ptr;}
		bool operator==(const iter& it) const { return ptr==it.ptr;}
		iter& operator+=(ptrdiff_t pdf) { ptr+=pdf; return *this;}
		iter& operator-=(ptrdiff_t pdf) { ptr-=pdf; return *this;}
		iter operator+(ptrdiff_t pdf) { return iter(ptr+pdf);}
		iter operator-(ptrdiff_t pdf) { return iter(ptr-pdf);}
		iter& operator++(void) { ++ptr; return *this;}	
		iter operator++(int) {return iter(ptr++);}
		iter& operator--(void) { --ptr; return *this;}
		iter operator--(int)  {return iter(ptr--);}
		T operator*(void) {return *ptr;} 
		friend class riter;
	};
	
	class criter;
	
	class citer{
		const T* ptr;
	public:
		citer(const T* p=0) :ptr(p) {}
	 
		bool operator!=(const citer& cit) const { return ptr!=cit.ptr;}
		bool operator==(const citer& cit) const { return ptr==cit.ptr;}
		citer& operator+=(ptrdiff_t pdf) { ptr+=pdf; return *this;}
		citer& operator-=(ptrdiff_t pdf) { ptr-=pdf; return *this;}
		citer operator+(ptrdiff_t pdf) { return citer(ptr+pdf);}
		citer operator-(ptrdiff_t pdf) { return citer(ptr-pdf);}
		citer& operator++(void) { ++ptr; return *this;}	
		citer operator++(int) {return citer(ptr++);}
		citer& operator--(void) { --ptr; return *this;}
		citer operator--(int)  {return citer(ptr--);}
		const T operator*(void) const {return *ptr;} 
		
		friend class criter;
	};
	
	iter begin(){
		return iter(vc);
	}	
	iter end(){
		return iter(vc+slen);
	}
	
	citer cbegin(){
		return citer(vc);
	}	
	citer cend(){
		return citer(vc+slen);
	}
	
	// reverse iterator
	class riter{
		T* ptr;
	public:
		riter(T* p=0):ptr(p) {}
	 	riter(iter& it):ptr(it.ptr){ }
		bool operator!=(const riter& it) const { return ptr!=it.ptr;}
		bool operator==(const riter& it) const { return ptr==it.ptr;}
		riter& operator+=(ptrdiff_t pdf) { ptr-=pdf; return *this;}
		riter& operator-=(ptrdiff_t pdf) { ptr+=pdf; return *this;}
		riter operator+(ptrdiff_t pdf) { return riter(ptr-pdf);}
		riter operator-(ptrdiff_t pdf) { return riter(ptr+pdf);}
		riter& operator++(void) { --ptr; return *this;}	
		riter operator++(int) {return riter(ptr--);}
		riter& operator--(void) { ++ptr; return *this;}
		riter operator--(int)  {return riter(ptr++);}
		T operator*(void) {return *(ptr-1);} 
		
	};

	class criter{
		const T* ptr;
	public:
		criter(const T* p=0) :ptr(p) {}
	 	criter(citer& cit) : ptr(cit.ptr){}
		bool operator!=(const criter& cit) const { return ptr!=cit.ptr;}
		bool operator==(const criter& cit) const { return ptr==cit.ptr;}
		criter& operator+=(ptrdiff_t pdf) { ptr-=pdf; return *this;}
		criter& operator-=(ptrdiff_t pdf) { ptr+=pdf; return *this;}
		criter operator+(ptrdiff_t pdf) { return criter(ptr-pdf);}
		criter operator-(ptrdiff_t pdf) { return criter(ptr+pdf);}
		criter& operator++(void) { --ptr; return *this;}	
		criter operator++(int) {return criter(ptr--);}
		criter& operator--(void) { ++ptr; return *this;}
		criter operator--(int)  {return criter(ptr++);}
		const T operator*(void) const {return *(ptr-1);} 
		
	};
	
	riter rbegin() {
		return riter(vc+slen);
	}
	riter rend(){
		return riter(vc);
	}
	criter rcbegin() const{
		return criter(vc+slen);
	}
	criter rcend() const{
		return criter(vc);
	}
};

struct set{
	double a,b;
};

int main(void){
	double a[] = {1.1,2.2,3.3};
    carray<double> ca1(a, a+sizeof(a)/sizeof(*a));
    carray<double> ca2(ca1);
    cout << ca1 << endl;
    cout << ca2 << endl;

   carray<double> ca(a, a+sizeof(a)/sizeof(*a));
   
   for(carray<double>::riter rit=ca.rbegin();rit!=ca.rend();++rit)
      cout << *rit << ' ';
   cout << endl;
   
   set s[] = { {1.1, 0.1}, {2.1,0.2}, {3.2,0.3}};
//	cout << sizeof(s) << " " <<sizeof(*s);
   carray<set> ca_set(s, s+sizeof(s)/sizeof(*s)); 
   cout << ca_set->a << endl;
   cout << ca_set->b << endl;
   
	for(carray<set>::riter rit=ca_set.rbegin();rit!=ca_set.rend();++rit)
    	cout << (*rit).a  << " "<< (*rit).b <<endl;
   cout << endl;
	return 0;
    
}
