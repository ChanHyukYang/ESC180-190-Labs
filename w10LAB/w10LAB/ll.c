#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
					which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value(llnode *pList,int val){
   if(pList == NULL){
      return -1;
}  if((pList) -> val == val){
         return 0;
}  else{
      return ll_find_by_value(((pList)->next),val);
}
}  
int ll_del_from_tail (llnode **ppList) {
	if (ppList == NULL) {
		return -1;
	}
	if ((((*ppList) -> next) -> next) == NULL) {
		llnode *lastnode = (*ppList) -> next;
		(*ppList) -> next = NULL;
		free(lastnode);
		return 0;
	}
	else {
		return ll_del_from_tail(&((*ppList)->next));
	}
	
}

int ll_del_from_head (llnode **ppList) {
	if (ppList == NULL) {
		return -1;
	}
	llnode *nextllnode;
	nextllnode = (*ppList) -> next;
	
	free(*ppList);
	*ppList = nextllnode;	
	return 0;	
}

int ll_del_by_value (llnode **ppList, int val) {
	
	if (ppList == NULL) {
		return -1;
	}
	
	if ((((*ppList) -> next) -> val) == val) {
		llnode *nextnode = (*ppList) -> next;
		(*ppList) -> next = ((*ppList) -> next) -> next;
		free (nextnode);
		return 0;
	}
	else {
		return ll_del_by_value((&(*ppList) -> next), val);
	}
}

int ll_insert_in_order (llnode **ppList, int val) {
	if (ppList == NULL) {
		return -1;
	}
	
	llnode *current;
	current = (*ppList);
	
	if (val < current -> val) {
		llnode *first = NULL;
		first = (llnode *) malloc(sizeof(llnode));
		first -> val = val;
		first -> next = current;
		*ppList = first;
		return 0;
	}
		
	while (val > current -> next -> val) {
		current = current -> next;
		if (current -> next == NULL) {
			break;
		}
	}
	
	llnode *newaddr;
	newaddr = current -> next;
	current -> next = (llnode *) malloc(sizeof (llnode));
	
	current -> next -> val = val;
	current -> next -> next = newaddr;
	
	return 0;	
}

int ll_concat (llnode **pSrcA, llnode **pSrcB) {
	if (pSrcA == NULL || pSrcB == NULL) {
		return -1;
	}
	
	llnode *current;
	current = (*pSrcA);
	
	while (current -> next != NULL) {
		current = current -> next;
	}
	
	current -> next = (*pSrcB);
			
	return 0;	
}

int ll_sort (llnode **ppList) {
	if (ppList == NULL) {
		return -1;
	}
		
	llnode *current;
	current = (*ppList);
	int len = 1;
	
	while (current -> next != NULL) {
		len++;
		current = current -> next;
	}
	
	int * arr = NULL;
	
	arr = (int *) malloc(len*sizeof(int));
	
	current = (*ppList);
	int i,j,n;
	for (i = 0; i < len; i++) {
		arr[i] = current -> val;
		current = current -> next;
	}
	
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (arr[j] < arr[i]) {
				n = arr[i];
				arr[i] = arr[j];
				arr[j] = n;
			}
		}
	}
	
	current = (*ppList);
	for (i =0; i < len; i++) {
		current -> val = arr[i];
		current = current -> next;
	}
	
	return 0;		
}
      
