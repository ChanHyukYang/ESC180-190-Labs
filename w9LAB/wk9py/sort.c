#include <stdio.h>
#include <stdlib.h>
int bubbleSort(int *array, int size){
   int i = 0;
   int k = 0;
   int l = 0;
   int hold = 0;
   int swap = 1;
   if(array == NULL){
      return -1;
}  
   while(swap){
      for(i=1;i<size;i=i+1){
         k=array[i-1];
         l=array[i];
         if(array[i-1]>array[i]){
            array[i-1] = l;
            array[i] = k;
            hold = hold + 1;
}
         swap = hold;
         hold = 0;
}
}
   return 0;
}
      
  
      
