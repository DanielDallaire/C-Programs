// Created by Daniel Dallaire
// 10/30/2017
/* Description:
	priority queue implemented with a linked list.
	Use the following line to import the queue structure and its 
	respective functions:
		#include "priorityQueue.h"
*/

#include <stdio.h>
#include <stdlib.h>

//Defaults to int
#ifndef TYPE
	#define TYPE int
	#ifdef GI
		#undef GI
	#endif
	#define GI(name) name ## int
#endif

typedef struct GI(nStruct){
	TYPE data;
	int priority;
	struct GI(nStruct)* next;
} GI(node);

typedef struct GI(qStruct){
	GI(node)* front;
	GI(node)* rear;
	int size;
} GI(queue_);

// Returns queue size
int GI(getSize_)(GI(queue_)* pQueue){
	return pQueue->size;
}

// Returns true if the queue only contains data of one priority
_Bool GI(isRegular_)(GI(queue_)* pQueue){
	GI(node)* tempPtr = pQueue->front;
	
	if(tempPtr == NULL) return 1;
	
	int test = tempPtr->priority;
	tempPtr = tempPtr->next;
	
	while(tempPtr != NULL){
		if(tempPtr->priority != test) return 0;
		tempPtr = tempPtr->next;
	}
	
	return 1;
}

// Returns the element that will next be dequeued
TYPE GI(peek_)(GI(queue_)* pQueue){
	return pQueue->front->data;
}

_Bool GI(isEmpty_)(GI(queue_)* pQueue){
	return pQueue->size == 0;
}

_Bool GI(isFull_)(GI(queue_)* pQueue){
	return 0;
}

// Dequeues the element at the front
void GI(deque_)(GI(queue_)* pQueue){
	GI(node)* tempPtr = pQueue->front;
	
	if(pQueue->front->next == NULL)
		pQueue->front = pQueue->rear = NULL;
	else
		pQueue->front = pQueue->front->next;
	
	pQueue->size = pQueue->size - 1;
	free(tempPtr);
}

// Initializes the queue
void GI(initQ_)(GI(queue_)* pQueue){
	pQueue->front = pQueue->rear = NULL;
	pQueue->size = 0;
}

// Calls the passed function with data in each node
void GI(display_)(GI(queue_)* pQueue, void (*printFormat)(TYPE data, int priority)){
	GI(node)* tempPtr = pQueue->front;
	
	while(tempPtr != NULL){
		
		(*printFormat)(tempPtr->data, tempPtr->priority);
		tempPtr = tempPtr->next;
	}
	
	return;
}

// Enqueues data at the proper position in the queue
void GI(enqueue_)(TYPE e, int prior, GI(queue_)* pQueue){
	GI(node)* newNode = (GI(node)*) malloc(sizeof(GI(node)));
	newNode->data = e; 
	newNode->priority = prior;
	newNode->next = NULL;
	
	if(pQueue->size == 0){
		pQueue->front = newNode;
		pQueue->rear = newNode;
	}
	else if(pQueue->size == 1){
		if(newNode->priority < pQueue->front->priority){
			newNode->next = pQueue->front;
			pQueue->front = newNode;
		}
		else{
			pQueue->front->next = newNode;
			pQueue->rear = newNode;
		}
	}
	else{
		GI(node)* tempPtr1 = pQueue->front, *tempPtr2 = NULL;
		
		while(tempPtr1->next != NULL && newNode->priority >= tempPtr1->next->priority)
			tempPtr1 = tempPtr1->next;
		
		if(tempPtr1->next == NULL){
			tempPtr1->next = newNode;
			pQueue->rear = newNode;
		}
		else if(tempPtr1 == pQueue->front){
			if(newNode->priority >= pQueue->front->priority){
				tempPtr1 = pQueue->front->next;
				pQueue->front->next = newNode;
				newNode->next = tempPtr1;
			}
			else{
				newNode->next = pQueue->front;
				pQueue->front = newNode;
			}
		}
		else{
			tempPtr2 = tempPtr1->next;
			tempPtr1->next = newNode;
			newNode->next = tempPtr2;
		}
	}
	
	pQueue->size = pQueue->size + 1;
	
	return;	
}

#undef GI
#undef TYPE