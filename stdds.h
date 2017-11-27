// Standard Data Structures
// Created by Daniel Dallaire

#include <stdlib.h>
#include <string.h>

// Type defaults to int.
#ifndef TYPE
	#define TYPE int
#endif

// It is required to define a different identifier modifier for each import of this file after the first. 
#ifndef IdModifier
	#define IdModifier(identifier) identifier 
#endif

// Defines these functions only once.
#ifndef INIT
	#define INIT \
										\
	int getSize(void* DS){				\
		int temp;						\
										\
		memcpy(&temp, DS, sizeof(int)); \
										\
		return temp;					\
	}									\
										\
	_Bool isEmpty(void* DS){			\
		return getSize(DS) == 0;		\
	}									\
										\
	_Bool isFull(void* DS){				\
		return 0;						\
	}
#endif

INIT

#undef INIT
#define INIT 

// Node Type
typedef struct IdModifier(nodeStructure){
	TYPE data;
	struct IdModifier(nodeStructure)* next;
}IdModifier(Node);

// Queue Type
typedef struct IdModifier(queueStructure){
	int size;
	IdModifier(Node)* front;
	IdModifier(Node)* rear;
}IdModifier(Queue);

// Stack type
typedef struct IdModifier(stackStructure){
	int size;
	IdModifier(Node)* top;
}IdModifier(Stack);

// --- Queue operations ---

// Initializes the Queue
void IdModifier(initQueue)(IdModifier(Queue)* Q){
	Q->size = 0;
	Q->rear = NULL;
	Q->front = NULL;
}

// Enqueues new data.
void IdModifier(enque)(IdModifier(Queue)* Q, TYPE newDat){
	IdModifier(Node)* newNode = (IdModifier(Node)*) malloc(sizeof(IdModifier(Node)));
	
	memcpy(&newNode->data, &newDat, sizeof(TYPE));
	
	newNode->next = NULL;
	
	if(Q->front == NULL)
		Q->front = Q->rear = newNode;
	else{
		Q->rear->next = newNode;
		Q->rear = newNode;
	}
	
	Q->size = Q->size + 1;
	
	return;
}

// Dequeues the front
void IdModifier(deque)(IdModifier(Queue)* Q){
	if(Q->size == 0) return;
	
	if(Q->size == 1){
		free(Q->front);
		Q->front = Q->rear = NULL;
	}
	else{
		IdModifier(Node)* temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	
	Q->size = Q->size - 1;
	
	return;
}

// Returns the data at the front
void IdModifier(getFront)(IdModifier(Queue)* Q, TYPE* dest){
	memcpy(dest, &Q->front->data, sizeof(TYPE));
	return;
}

// --- Stack Operations ---

// Initializes the Stack
void IdModifier(initStack)(IdModifier(Stack)* S){
	S->size = 0;
	S->top = NULL;
}

// Pushs new data onto the stack
void IdModifier(push)(IdModifier(Stack)* S, TYPE newDat){
	IdModifier(Node)* newNode = (IdModifier(Node)*) malloc(sizeof(IdModifier(Node)));
	
	memcpy(&newNode->data, &newDat, sizeof(TYPE));
	
	newNode->next = NULL;
	
	if(S->size == 0)
		S->top = newNode;
	else{
		newNode->next = S->top;
		S->top = newNode;
	}
	
	S->size = S->size + 1;
	
	return;
}

// Pops the data at the top off the Stack.
void IdModifier(pop)(IdModifier(Stack)* S){
	if(S->size == 0) return;
	
	if(S->size == 1)
		free(S->top);
	else{
		IdModifier(Node)* temp = S->top;
		S->top = S->top->next;
		free(temp);
	}
	
	S->size = S->size - 1;
	
	return;
}

// Returns the data at the top of the Stack
void IdModifier(getTop)(IdModifier(Stack)* S, TYPE* dest){
	memcpy(dest, &S->top->data, sizeof(TYPE));
	return;
}

#undef TYPE
#undef IdModifier
