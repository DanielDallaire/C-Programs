// Generic Sorting Function for Linked Lists
// Created by Daniel Dallaire

#include <string.h> 

// Defaults to type int
#ifndef TYPE
	#define TYPE int
#endif

// It is required to define a different identifier modifier for each import of this file after the first. 
#ifndef IdModifier
	#define IdModifier(identifier) identifier 
#endif

// Produces an error if NODE was not defined.
#ifndef NODE
	#error NODE type definition required for 'linkedlistsort.h'.
#endif

static NODE* IdModifier(getMid)(NODE* List){
	if(List == NULL || List->next == NULL) return List;
	
	NODE* Mid = List, *End = List->next;
	
	while(End->next != NULL){
		End = End->next;
		
		if(End->next != NULL){
			End = End->next;
			Mid = Mid->next;
		}
	}
	
	return Mid;
}

// Takes two lists and a comparison function and returns a new list sorted based on the comparison function.
static NODE* IdModifier(mergeLists)(NODE* A, NODE* B, int (*cmp)(TYPE, TYPE)){
	NODE* newList = NULL, *temp1 = NULL, *temp2;
	
	if(A == NULL) return B;
	if(B == NULL) return A;
	
	while(A != NULL && B != NULL){
		if((*cmp)(A->data, B->data) > 0){
			temp2 = B;
			B = B->next;
		}
		else{
			temp2 = A;
			A = A->next;
		}
		
		if(newList != NULL)
			temp1->next = temp2;
		else
			newList = temp2;
		
		temp1 = temp2;
	}
	
	if(A == NULL)
		temp1->next = B;
	else 
		temp1->next = A;
	
	return newList;
	
}

// Merge Sort
void IdModifier(SortLinkedList)(NODE** List, int size, int (*cmp)(TYPE, TYPE)){
	
	if(size <= 1) return;
	
	NODE* Mid = IdModifier(getMid)(*List), *temp;
	temp = Mid->next;
	Mid->next = NULL;
	Mid = temp;
	
	IdModifier(SortLinkedList)(List, size/2, cmp);
	IdModifier(SortLinkedList)(&Mid, size - size/2, cmp);
	
	*List = IdModifier(mergeLists)(*List, Mid, cmp);
	
	return;
}

#undef TYPE
#undef IdModifier
