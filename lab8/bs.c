#include <stdlib.h>
#include <stdio.h>
int bs(int *x,int size, int(*compare)(int x,int y));
int lt(int x,int y);
int gt(int x,int y);

int lt(int x,int y){
   if(x<=y){
      return 0;
   }
   else{
      return 1;
   }
}

int gt(int x,int y){
   if(x>=y){
      return 0;
   }
   else{
      return 1;
   }
}

int bs(int *x,int size,int (*compare)(int x,int y)){
   int i=0;
   int j=0;
   int hold=0;
   for(i=0;i<size;i++){
      for(j=0;j<size-1;j++){
         if(compare(x[j],x[j+1])==0){
            hold = x[j];
            x[j]=x[j+1];
            x[j+1]=hold;
         }
      }
   }
   return 0;
}
int main(void) {
   int i=0;
   int vals[10];
   int (*flt)(int,int)=gt;
   for (i=0;i<10;i=i+1){
      vals[i]=100-i;
   }
   for (i=0;i<10;i++){
      printf("in[%d]=%d\n",i,vals[i]);
   }
   bs(vals,10,flt);
   for (i=0;i<10;i++){
      printf("out[%d]=%d\n",i,vals[i]);
   }
   return 0;
} 
