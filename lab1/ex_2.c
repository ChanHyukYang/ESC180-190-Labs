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
int add_to_end(intlist *l, int val){
   ((l)->x)[end+1]=val;
   (l)->end = (l)->end + 1;
   return 0;
}
int add_to_start(intlist *l, int val){
   int n = (l)->end;
   int m = (l)->start;
   while(n=(l)->end,n>=(l)->start, n=n-1){
      ((l)->x)[n+1]=((l)->x)[n];
}  ((l)->x)[m] = val;
   return 0;
}
int insert_after(intlist *l, int insert_val, int val){   
   int n=0;
   int m = 0;
   for(n=(l)->start, n<=(l)->end, n=n+1)
      if(((l)->x)[n] == insert_val){
         m=n;
}  for(n=(l)->end, n>m, n=n-1){
      ((l)->x)[n+1]=((l)->x)[n];
}  ((l)->x)[m+1] = val;
   return 0;
}
