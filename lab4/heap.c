#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
} HeapType;

int initHeap (HeapType *pHeap,int size);
int inorder  (HeapType *pHeap, int **output, int *o_size);
int preorder (HeapType *pHeap, int **output, int *o_size);
int postorder(HeapType *pHeap, int **output, int *o_size);
int inorderhelper(HeapType *pHeap, int **output, int pos, int *o_size);
int preorderhelper(HeapType *pHeap, int **output, int pos, int *o_size);
int postorderhelper(HeapType *pHeap, int **output, int pos, int *o_size);
int findHeap(HeapType *pHeap, int key);
int addHeap(HeapType *pHeap, int key);
int delHeap(HeapType *pHeap, int *key);
 
int initHeap (HeapType *pHeap,int size){
   if(pHeap == NULL){
      return -1;
}  (pHeap)->store=(int *)malloc((size)*sizeof(int));
   (pHeap)->size = size;
   (pHeap)->end = 0;
   return 0;
}

int inorder(HeapType *pHeap, int **output, int *o_size){
   int r = 0;
   *o_size = 0;
   if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  (*output) = (int *)malloc(((pHeap)->end)*sizeof(int));
   inorderhelper(pHeap, output,r, o_size); 
   return 0;
}

int inorderhelper(HeapType *pHeap, int **output, int pos, int *o_size){
   if(pos > (pHeap)->end){
      return -1;
}  else if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  inorderhelper(pHeap, output, ((pos*2)+1), o_size);
   (*output)[*o_size]=(pHeap)->store[pos];
   (*o_size) = (*o_size)+1;
   inorderhelper(pHeap, output, ((pos*2)+2), o_size);
   return 0;
}
int preorder(HeapType *pHeap, int **output, int *o_size){
   int r = 0;
   *o_size = 0;
   if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  (*output) = (int *)malloc(((pHeap)->end)*sizeof(int));
   preorderhelper(pHeap, output,r, o_size); 
   return 0;
}

int preorderhelper(HeapType *pHeap, int **output, int pos, int *o_size){
   if(pos > (pHeap)->end){
      return -1;
}  else if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  (*output)[*o_size]=(pHeap)->store[pos];
   (*o_size) = (*o_size)+1;
   preorderhelper(pHeap, output, ((pos*2)+1), o_size);
   preorderhelper(pHeap, output, ((pos*2)+2), o_size);
   return 0;
}
int postorder(HeapType *pHeap, int **output, int *o_size){
   int r = 0;
   *o_size = 0;
   if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  (*output) = (int *)malloc(((pHeap)->end)*sizeof(int));
   postorderhelper(pHeap, output,r, o_size); 
   return 0;
}

int postorderhelper(HeapType *pHeap, int **output, int pos, int *o_size){
   if(pos > (pHeap)->end){
      return -1;
}  else if(pHeap == NULL){
      return -1;
}  else if(output==NULL){
      return -1;
}  else if(o_size==NULL){
      return -1;
}  postorderhelper(pHeap, output, ((pos*2)+1), o_size);
   postorderhelper(pHeap, output, ((pos*2)+2), o_size);
   (*output)[*o_size]=(pHeap)->store[pos];
   (*o_size) = (*o_size)+1;

   return 0;
}

int findHeap(HeapType *pHeap, int key){
   int i = 0;
   if(pHeap == NULL){
      return -1;
   }
   for(i=0;i<((pHeap)->end);i++){
      if((pHeap)->store[i] == key){
         return 1;
      }
   }
   return 0;
}

int addHeap(HeapType *pHeap, int key){
   int n = (pHeap)->end;
   int val = 0;
   if(pHeap == NULL){
      return -1;
   }
   (pHeap)->store[n] = key;
   (pHeap)->end = (pHeap)->end + 1;
   while(1){
      if(n<=0){
         return 0;
      }
      if(n%2 == 0){
         if(((pHeap)->store[n])>(pHeap->store[((n/2)-1)])){
            val = (pHeap)->store[n];
            (pHeap)->store[n] = (pHeap)->store[((n/2)-1)]; 
            (pHeap)->store[((n/2)-1)] = val;
            n = (n/2)-1;
         }
         else{
            return 0;
         }         
      }  
      else if(n%2 == 1){
         if(((pHeap)->store[n])>(pHeap->store[((n-1)/2)])){
            val = (pHeap)->store[n];
            (pHeap)->store[n] = (pHeap)->store[((n-1)/2)]; 
            (pHeap)->store[((n-1)/2)] = val;    
            n = (n-1)/2;
         }  
         else{
            return 0;
         }     
      }  
   }
}


int delHeap(HeapType *pHeap, int *key){
   int n = 0;
   int *new;
   int tracker = 0;
   if(pHeap == NULL){
   return -1;
   }
   *key = (pHeap->store[0]);
   (pHeap)->store[0]=((pHeap)->store[(pHeap)->end]);
   while (1){
      if (n >=(pHeap)->end){
         return 0;
      } 
      if(((pHeap)->store[(2*n)+1])>((pHeap)->store[(2*n)+2])){
         if ((pHeap)->store[n] < (pHeap)->store[(2*n)+1]){
            tracker = (pHeap)->store[(2*n)+1];
            (pHeap)->store[(2*n)+1] = (pHeap)->store[n];
            (pHeap)->store[n] = tracker;
            n = (2*n) + 1;
         }
         else{
            return 0;
         }
      }
      else if(((pHeap)->store[(2*n)+1])<((pHeap)->store[(2*n)+2])){
         if ((pHeap)->store[n] < (pHeap)->store[(2*n)+2]){
            tracker = (pHeap)->store[(2*n)+2];
            (pHeap)->store[(2*n)+2] = (pHeap)->store[n];
            (pHeap)->store[n] = tracker;
            n = (2*n) + 2;
         }
         else{
            return 0;
         }
      }
   }
}
