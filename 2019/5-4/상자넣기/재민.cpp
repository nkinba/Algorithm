#include <iostream>
#include <map>

using namespace std;

struct box {
   int size;
   int num;
};

int main(void)
{
   int N, max_num=0;
   
   cin >> N;
   map<int, box> boxs;
   
   for(int i=0; i<N; ++i) {
      box temp;
      cin >> temp.size;
      temp.num = 0;
      boxs[i] = temp;
   }
      
   for(int i=0; i<N; ++i)
      for(int j=i+1; j<N; ++j)
         if(boxs[i].size < boxs[j].size && boxs[i].num+1 > boxs[j].num)
            boxs[j].num = boxs[i].num+1;
   
   for(int i=0; i<N; ++i)
      if(max_num<boxs[i].num)
         max_num = boxs[i].num;
         
   cout << max_num+1 << endl;
}
