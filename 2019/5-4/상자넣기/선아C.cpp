// C
#include <stdio.h>
#include <stdlib.h>

//void print_arr(int arr[], int len)
//{
//   int i;
//   printf("\n");
//   for(i=0; i<len; ++i)
//      printf("%d ", arr[i]);
//   printf("\n");
//}

int get_max(int arr[], int len)
{
   int i;
   int max = arr[0];
   for(i=1; i<len; ++i) 
      if(max < arr[i]) 
         max = arr[i];
   return max;
}
         
int main(void)
{
   int boxNum;
   scanf("%d", &boxNum);
   int* boxSizes = (int*)malloc(sizeof(int)*boxNum);
   int* containerNum = (int*)malloc(sizeof(int)*boxNum);
   int i, j;
   for(i=0; i<boxNum; ++i)
      scanf("%d", &boxSizes[i]);
      
   int* bigger = (int*)malloc(sizeof(int)*boxNum);
   int biggerLen;
   for(i=boxNum-1; i>=0; --i) {
      biggerLen = 0;
      for(j=i+1; j<boxNum; ++j) {
         if(boxSizes[i] < boxSizes[j]) {
            bigger[biggerLen] = containerNum[j];
            ++biggerLen;
         }
      }
      if(biggerLen > 0)
         containerNum[i] = 1 + get_max(bigger,biggerLen);
      else
         containerNum[i] = 0;
   }
   
   printf("%d\n", 1 + get_max(containerNum,boxNum));
   return 0;
}
