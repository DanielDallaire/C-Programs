#include <stdlib.h>
#include <string.h>

// Node Type
typedef struct nodeStructure{
	int data;
	struct nodeStructure* next;
}Node;

// Queue Type
typedef struct queueStructure{
	int size;
	Node* front;
	Node* rear;
}Queue;

// Stack type
typedef struct stackStructure{
	int size;
	Node* top;
}Stack;

// Gets the size of the data structure, expects either a Stack or a Queue
int getSize(void* DS){
	int temp;
	
	memcpy(&temp, DS, sizeof(int));
	
	return temp;
}

// Returns true if the DS is empty.
_Bool isEmpty(void* DS){
	return getSize(DS) == 0;
}

_Bool isFull(void* DS){
	return 0;
}

// --- Queue operations ---

// Initializes the Queue
void initQueue(Queue* Q){
	Q->size = 0;
	Q->rear = NULL;
	Q->front = NULL;
}

// Enqueues new data.
void enque(Queue* Q, int newDat){
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	newNode->data = newDat;
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
void deque(Queue* Q){
	if(Q->size == 0) return;
	
	if(Q->size == 1){
		free(Q->front);
		Q->front = Q->rear = NULL;
	}
	else{
		Node* temp = Q->front;
		Q->front = Q->front->next;
		free(temp);
	}
	
	Q->size = Q->size - 1;
	
	return;
}

// Returns the data at the front
int getFront(Queue* Q){
	return Q->front->data;
}

// --- Stack Operations ---

// Initializes the Stack
void initStack(Stack* S){
	S->size = 0;
	S->top = NULL;
}

// Pushs new data onto the stack
void push(Stack* S, int newDat){
	Node* newNode = (Node*) malloc(sizeof(Node));
	
	newNode->data = newDat;
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
void pop(Stack* S){
	if(S->size == 0) return;
	
	if(S->size == 1)
		free(S->top);
	else{
		Node* temp = S->top;
		S->top = S->top->next;
		free(temp);
	}
	
	S->size = S->size - 1;
	
	return;
}

// Returns the data at the top of the Stack
int getTop(Stack* S){
	return S->top->data;
}
