typedef struct intlist {
   int *x;
   int end;
   int len;
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
int push(intlist *l, int val){
   ((l)->x)[end+1]=val;
   (l)->end = (l)->end + 1;
   return 0;
}
int pop(intlist *l, int val){
   ((l)->x)[end]=NULL;
   (l)->end=(l)->end-1;
   return 0;
}
/*assume end is known to user*/
