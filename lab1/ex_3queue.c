typedef struct intlist {
   int *x;
   int end;
   int len;
   int start;
};
int init(intlist *l,int len) {
   if (l==NULL) { return -1; }
   (l->x) = (int *)malloc(100*len * sizeof(int));
   if ((l->x) == NULL) { return -1; }
   l->end = -1;
   l->start = -1;
   l->len=len;
   return 0;
}
int enqueue(intlist *l, int val){
   int n = (l)->end;
   int m = (l)->start;
   while(n=(l)->end,n>=(l)->start, n=n-1){
      ((l)->x)[n+1]=((l)->x)[n];
}  ((l)->x)[m] = val;
   return 0;
}
int dequeue(intlist *l, int val){
   int n = (l)->start;
   int m = (l)->end;
   while(n=(l)->start+1, n<=m,n=n+1){
      ((l)->x)[n-1] = ((l)->x)[n];
}  return 0;
} 
