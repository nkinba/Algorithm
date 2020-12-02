#include <iostream>

using namespace std;

class carray {
   size_t alen;
   size_t slen;
   double* ep;
 public: 
   static double* cpy(const double* b, const double* e, double* d) {
      double* dst = d;
      for(const double* it=b;it!=e;++it)
         *dst++=*it;
      return d;
   }
   static double* set(double* b, double* e, double v0) {
      for(double* it=b;it!=e;++it)
         *it=v0;
      return b;
   }
   static size_t cal_alen(size_t len) {
      size_t new_alen;
      for(new_alen=1;new_alen<len;new_alen<<=1)
         ;
      return new_alen;
   }

   carray(void)
      :slen(0), alen(0), ep(0) {}
   carray(size_t len, double v0=double())
      : slen(len) {
      alen = cal_alen(slen);
      ep = new double[alen];
      set(ep,ep+slen,v0);
   }
   carray(const double* b, const double* e)
      : slen(e-b) {
      alen = cal_alen(slen);
      ep = new double[alen];
      cpy(b,e,ep);
   }
   carray(const carray& ca)
      : slen(ca.slen) {
      alen = cal_alen(slen);
      ep = new double[alen];
      cpy(ca.ep, ca.ep+ca.slen,ep);
   }
   ~carray(void) {
      if(ep!=0)
         delete ep;
   }
   
   size_t size(void) const {
      return slen;
   }
   void resize(size_t new_len) {
      if(new_len == slen)
         return;
      if(new_len<slen) {
         slen = new_len;
         return;
      }
      if(new_len<=alen) {
         set(ep+slen,ep+new_len,double());
         slen = new_len;
         return;
      }
      alen = cal_alen(new_len);
      double* new_ep = new double[alen];
      cpy(ep, ep+slen, new_ep);
      set(new_ep+slen, new_ep+new_len, double());
      delete[] ep;
      slen = new_len;
      ep = new_ep;
      return;
   }
   carray& operator=(const carray& ca) {
      if(this==&ca)
         return *this;
      if(ca.slen==0) {
         slen = ca.slen;
         return *this;
      }
      if(slen!=0 && ca.slen!=0 && ca.alen<=alen) {
         cpy(ca.ep, ca.ep+ca.slen, ep);
         slen = ca.alen;
         return *this;
      }
      alen = cal_alen(ca.slen);
      double* new_ep = new double[alen];
      cpy(ca.ep, ca.ep+ca.slen,new_ep);
      if(ep!=0) delete[] ep;
      slen = ca.slen;
      ep = new_ep;
      return *this;
   }
   
   const double& operator[](size_t i) const {
      return ep[i];
   }
   double& operator[](size_t i) {
      return ep[i];
   }
   
   class riter;
   
   class iter {
      double* p;
   public:
      iter(double* pp): p(pp) {}
      bool operator!=(const iter& it) const { return p!=it.p; }
      bool operator==(const iter& it) const { return p==it.p; }
      iter& operator+=(ptrdiff_t pdf) { return p+=pdf, *this; }
      iter& operator-=(ptrdiff_t pdf) { return p-=pdf, *this; }
      iter operator+(ptrdiff_t pdf) const { return iter(p+pdf); }
      iter operator-(ptrdiff_t pdf) const { return iter(p-pdf); }
      iter& operator++(void) { return ++p, *this; }
      iter operator++(int) { return iter(p++); }
      iter& operator--(void) { return --p, *this; }
      iter operator--(int) { return iter(p--); }
      double& operator*(void) const { return *p; }
      friend class riter;
   };
   
   iter begin(void) { return iter(ep); }
   iter end(void) { return iter(ep+slen); }
   
   class criter;
   
   class citer {
      const double* p;
   public:
      citer(const double* pp): p(pp) {}
      bool operator!=(const citer& it) const { return p!=it.p; }
      bool operator==(const citer& it) const { return p==it.p; }
      citer& operator+=(ptrdiff_t pdf) { return p+=pdf, *this; }
      citer& operator-=(ptrdiff_t pdf) { return p-=pdf, *this; }
      citer operator+(ptrdiff_t pdf) const { return citer(p+pdf); }
      citer operator-(ptrdiff_t pdf) const { return citer(p-pdf); }
      citer& operator++(void) { return ++p, *this; }
      citer operator++(int) { return citer(p++); }
      citer& operator--(void) { return --p, *this; }
      citer operator--(int) { return citer(p--); }
      const double& operator*(void) const { return *p; }
      friend class criter;
   };
   
   citer begin(void) const {return citer(ep); }
   citer end(void) const {return citer(ep+slen); }
   
   class riter {
      double* p;
   public:
      riter(double* pp): p(pp) {}
      riter(const iter& it): p(it.p) {}
      bool operator!=(const riter& it) const {return p!=it.p; }
      bool operator==(const riter& it) const {return p==it.p; }
      riter& operator+=(ptrdiff_t pdf) { return p-=pdf, *this; }
      riter& operator-=(ptrdiff_t pdf) { return p+=pdf, *this; }
      riter operator+(ptrdiff_t pdf) { return riter(p-pdf); }
      riter operator-(ptrdiff_t pdf) { return riter(p+pdf); }
      riter& operator++(void) { return --p, *this; }
      riter operator++(int) { return riter(p--); }
      riter& operator--(void) { return ++p, *this; }
      riter operator--(int) { return riter(p++); }
      double& operator*(void) const { return *(p-1); }
   };
   
   riter rbegin(void) { return riter(ep+slen); }
   riter rend(void) { return riter(ep); }

   class criter {
      const double* p;
   public:
      criter(const double* pp): p(pp) {}
      criter(const citer& it): p(it.p) {}
      bool operator!=(const criter& it) const {return p!=it.p; }
      bool operator==(const criter& it) const {return p==it.p; }
      criter& operator+=(ptrdiff_t pdf) { return p-=pdf, *this; }
      criter& operator-=(ptrdiff_t pdf) { return p+=pdf, *this; }
      criter operator+(ptrdiff_t pdf) { return criter(p-pdf); }
      criter operator-(ptrdiff_t pdf) { return criter(p+pdf); }
      criter& operator++(void) { return --p, *this; }
      criter operator++(int) { return criter(p--); }
      criter& operator--(void) { return ++p, *this; }
      criter operator--(int) { return criter(p++); }      
      const double& operator*(void) const { return *(p-1); }
   };
   
   criter crbegin(void) { return criter(ep+slen); }
   criter crend(void) { return criter(ep); }
};

ostream& operator<<(ostream& os, const carray& ca)
{
   for(size_t i=0;i<ca.size();++i)
      os << ca[i] << ' ';
   return os;
}

int main(void)
{
   double a[] = {1.1, 2.2, 3.3};
   carray ca(a, a+sizeof(a)/sizeof(*a));
   
   for(carray::riter rit=ca.rbegin();rit!=ca.rend();++rit)
      cout << *rit << ' ';
   cout << endl;
   
   return 0;
}

