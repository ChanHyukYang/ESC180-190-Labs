#include <stdio.h>
#include <stdlib.h>

struct llnode {
   char value;
   struct llnode *next;
};
typedef struct llnode llnode;

int llnode_add_to_head(llnode **x, char value){
   if(x==NULL){
      return -1;
}  llnode *p;
   p=(llnode *)malloc(sizeof(llnode));
   (p)->value = value;
   (p)->next = *x;
   *x = p;
   return 0;
}
   
int llnode_add_to_tail(llnode **x,char value) {
   if (x==NULL) { return -1; }
   if (*x==NULL) {
      *x = (llnode *) malloc(sizeof(llnode));
      (*x)->value = value;
      (*x)->next = NULL;
      return 0;
   } else {
      return llnode_add_to_tail(&((*x)->next),value);
   }
}

int push(llnode **x, char value){
   if(x==NULL){
      return -1;
}  llnode_add_to_head(x,value);
   return 0;
}
int pop(llnode **x, char *return_value){
   if(x==NULL){
   return -1;
}  if(*x==NULL){
   return -1;
}  llnode *t;
   t=*x;
   *return_value = (*x)->value;
   *x = (t)->next;
   free(t);
   return 0;
}
  
int llnode_print_from_head(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      printf("%c\n",x->value);
      return llnode_print_from_head(x->next);
   }
}

int llnode_print_from_tail(llnode *x) {
   if (x==NULL) { return 0; }
   else {
      if (x->next == NULL) {
         printf("%c\n",x->value);
	 return 0;
      } else {
         llnode_print_from_tail(x->next);
         printf("%c\n",x->value);
	 return 0;
      }
   }
}

int main(void) {
   int n=0;
   char value='a';
   int rvalue=0;
   llnode *input_list=NULL;

   while (scanf("%c",&value) != EOF) {
      n=n+1;
      push(&input_list,value);
   }
   char v;
   int g = pop(&input_list, &v);
   printf("return: %c\n",v);
   g = pop(&input_list, &v);
   printf("return: %c\n",v);
   printf("INFO: you entered %d items\n",n);
   rvalue=llnode_print_from_tail(input_list);
   if ( !(rvalue==0) ) { printf("ERR: llnode_print returned an error\n"); }

   return 0;
}
