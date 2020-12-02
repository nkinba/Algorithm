#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef int val;
typedef int idx;
typedef pair<val,idx> data;
typedef vector<data> v_data;

int main(void)
{
   int N;
   cin >> N;

   v_data sizes;
   data temp;
   for(int i=0;i<N;++i){
      cin >> temp.first;
      temp.second = i+1;
      sizes.push_back(temp);
   }

   cout << "< Input >" << endl;
   for(int i=0;i<sizes.size();++i)
      cout << sizes[i].first << "(" << sizes[i].second << ")" << ' ';
   cout << endl;

   sort(sizes.rbegin(),sizes.rend());
   
   cout << "< sort >" << endl;
   for(int i=0;i<sizes.size();++i)
      cout << sizes[i].first << "(" << sizes[i].second << ")" << ' ';
   cout << endl;
   
   int Max = 0;
   v_data count;
   for(int i=0;i<sizes.size()  ;++i){
      count.clear();
      for(int j=i;j<sizes.size() ;++j){
         if(j==i) 
            count.push_back(sizes[j]);
         else if( (sizes[j].first != count[count.size()-1].first) 
                  && (sizes[j].second < count[count.size()-1].second) )
            count.push_back(sizes[j]);
      }
      if(i==0){
         Max = count.size();
         cout << "max : " << Max << endl;
      }
      else{
         int count_size = count.size();
         Max = max(Max, count_size);
         cout << "max : " << Max << endl;
      }
   }

   cout  << Max << endl;
   
return 0;
}
