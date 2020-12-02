#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int set_max(const vector< vector<int> >& field, int n)
{
   //cout << "set_max In." << endl;
   int max=0;
   for(int i=0;i<n;++i) {
      //cout << "field[" << i << "][" << n << "]: " << field[i][n] << endl;
      if(field[i][n]>max)
         max=field[i][n];
   }
   //cout << endl;
   return max;
}

int find_answer(const vector< vector<int> >& field)
{
   int max=0;
   for(int i=0;i<field.size();++i)
      if(field[i][i] > max)
         max = field[i][i];
      
   return max;
}

void dynamic(vector< vector<int> >& field, const vector<int>& boxes)
{
   for(int i=0;i<field.size()-1;++i) {
      field[i][i]=set_max(field,i);
      for(int j=i+1;j<field[i].size();++j) {
         if(boxes[i]<boxes[j])
            field[i][j]=field[i][i]+1;

      }
   }
   field[field.size()-1][field.size()-1]=set_max(field,field.size()-1);
}

int main(void)
{
   //ifstream ifs("sample.txt");
   int N;
   cin >> N;
   
   vector<int> boxes(N);
   vector< vector<int> > field(N,vector<int>(N,0));
   
   for(int i=0;i<N;++i)
      cin >> boxes[i];
      
//   for(int i=0;i<N;++i)
//      cout << boxes[i] << ' ';
//   cout << endl;
   
   dynamic(field,boxes);
   
//   for(int i=0;i<N;++i) {
//      for(int j=0;j<N;++j)
//         cout << field[i][j] << ' ';
//      cout << endl;
//   }

   cout << find_answer(field)+1 << endl;

   //ifs.close();   
   return 0;
}
