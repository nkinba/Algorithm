// C++ 11
#include <iostream>
#include <map>

using namespace std;

typedef int containNum;
typedef int size;

int main(void)
{
   map<containNum, size> info;
   int boxNum, boxSize;
   cin >> boxNum;
   cin >> boxSize;
   info[0] = boxSize;
   for(int i=1; i<boxNum; ++i) {
      cin >> boxSize;
      map<containNum,size>::reverse_iterator rit;
      for(rit=info.rbegin(); rit!=info.rend() 
         && !(rit->second < boxSize); ++rit)
         ;
      if( rit != info.rend() ) {
         auto it = info.find(rit->first+1);
         if( it != info.end() ) {
            if(it->second > boxSize)
               it->second = boxSize;
         }
         else
            info[rit->first+1] = boxSize;
      }
      else {
         if(info.begin()->second > boxSize)
            info.begin()->second = boxSize;
      }
//      cout << endl;
//      for(map<containNum,size>::iterator it=info.begin();
//         it!=info.end(); ++it)
//         cout << it->first << " " << it->second << endl;
   }
   
   cout << info.rbegin()->first + 1 << "\n";
   return 0;
}
