/*

8
상자 배열: 1 6 2 5 7 3 5 6
겹친 갯수: 1 2 2 3 4 3 4 5 
가장 많이 겹친 갯수: 5 

*/

#include <iostream>
#include <vector>

using namespace std;

class maxbox {
   int* box;
   int len_box;
   static void swap(int& a, int& b) {
      int temp;
      temp = a;
      a = b;
      b = temp;
   }
   static int find_max(int* a, int len) {
      for(int i=0; i<len-1; ++i)
         for(int j=i+1; j<len; ++j)
            if(a[i]<a[j])
               swap(a[i],a[j]);
      return a[0];
   }
   static void clear(int* a, int len) {
      for(int i=0; i<len; ++i)
         a[i] = 0;
   }
public:
   maxbox(int len): box(new int[len]), len_box(len) {}
   ~maxbox(void) {
      if(box!=nullptr)
         delete[] box;
   }
   void input_box(void) {
      for(int i=0; i<len_box; ++i)
         cin >> box[i];
   }
   int max_box(void) const {
//      int* overlap = new int[len_box];
//      int* temp = new int[len_box];
      int overlap[len_box];
      int temp[len_box];
      int temp_len=0;
      overlap[0] = 1; // 맨 처음 상자 1개.
      for(int i=1; i<len_box; ++i) {
         for(int j=0; j<i; ++j) {
            if(box[j]<box[i]) {
               temp[temp_len++] = overlap[j];
            }
         } // 지정한 값 보다 왼쪽으로 작은 놈의 겹친 수 중에 
         int max = 0;
         for(int i=0; i<temp_len; ++i) {
            if(temp[i] > max) {
               max = temp[i];
            } // 가장 큰 값을 찾는다. 
         }
         overlap[i] = max+1;
         // 그 가장 큰 값에 +1을 더한다. 
         clear(temp, temp_len);
         temp_len = 0;
      }
      return find_max(overlap, len_box);
   }
};

int main(void)
{
   int N=0;
   do {
      cin >> N;
   } while( !(1<=N || N<=1000) );
   
   maxbox b(N);
   
   b.input_box();
   cout << b.max_box() << endl;

//   if(temp!=nullptr) delete[] temp;
//   if(overlap!=nullptr) delete[] overlap;
   return 0;
}
