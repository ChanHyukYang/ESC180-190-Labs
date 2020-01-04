#include <stdlib.h>
#include <stdio.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
   int (*compare)(int x,int y);
} intHeap_T;

int lt(int x,int y);
int gt(int x,int y);
int store(intHeap_T* heap, int value);
int retrieve(intHeap_T* heap,int *rvalue);
int hs(int *x,int size,int (*compare)(int x,int y));
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

int store(intHeap_T* heap,int value) {
   int root = 0;
   int last = heap->end;
   int temp = 0;
   if(heap==NULL){
      return -1;
   }
   heap->store[heap->end] = value;
   heap->end = heap->end +1;
   while(1){
      if (last%2==0){
         root = (last-2)/2;
      }
      else if(last%2==1){
         root = (last-1)/2;
      }
      if(root<0){
         break;
      }
      if(heap->compare(heap->store[root],heap->store[last]) == 0){
         temp = heap->store[root];
         heap->store[root]=heap->store[last];
         heap->store[last] = temp;
         last = root;
      }
      else{
         break;
      }
   }
   return 0;
} 
int retrieve(intHeap_T* heap,int *rvalue) {
   int root = 0;
   int child = 0;
   int left = 0;
   int right = 0;
   int temp = 0;
   if(heap==NULL){
      return -1;
   }
   *rvalue = heap->store[0];
   heap->store[0] = heap->store[heap->end-1];
   heap->end=heap->end-1;
   while(1){
      child = root;
      left=2*root +1;
      right=2*root +2;
      if(left<heap->end){
         if(heap->compare(heap->store[root],heap->store[left])==0){
            child = left;
         }
      }
      if(right<heap->end){
         if(heap->compare(heap->store[child],heap->store[right])==0){
            child = right;
         }
      }
      if(child != root){
         temp = heap->store[root];
         heap->store[root] = heap->store[child];
         heap->store[child] = temp;
         root = child;
      }
      else{
         break;
      }
   }
   return 0;
}

int hs(int *x,int size,int (*compare)(int x,int y)){
   int i=0;
   int j=0;
   intHeap_T heap;
   heap.store = (int *)malloc(1000*sizeof(int));
   heap.size=1000;
   heap.end = 0;
   heap.compare = compare;
   for(i=0;i<size;i=i+1){
      store(&heap,x[i]);
   }
   for(i=0;i<size;i=i+1){
      retrieve(&heap,&j);
      x[i] = j;
   }
   return 0;
}
int main(void){
   int i=0;
   int vals[10];
   for (i=0;i<10;i=i+1){
      vals[i]=100-i;
   }
   for (i=0;i<10;i++){
      printf("in[%d]=%d\n",i,vals[i]);
   }
   hs(vals,10,lt);
   for (i=0;i<10;i++){
      printf("out[%d]=%d\n",i,vals[i]);
   }
   return 0;
}  
