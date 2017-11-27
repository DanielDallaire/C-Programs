// Generic Sorting Function for Arrays
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

static void IdModifier(mergeArrays)(TYPE A[], const int ASize, TYPE B[], const int BSize, int (*cmp)(TYPE, TYPE)){
	
	int Acount = ASize, Bcount = BSize, index = 0;
	
	TYPE newArray[ASize+BSize];
	
	while(Acount > 0 && Bcount > 0){
		
		if((*cmp)(A[ASize - Acount], B[BSize - Bcount]) > 0){
			memcpy(&newArray[index++], &B[BSize - Bcount], sizeof(TYPE));
			Bcount--;
		}
		else{
			memcpy(&newArray[index++], &A[ASize - Acount], sizeof(TYPE));
			Acount--;
		}
	}
	
	if(Acount == 0)
		memcpy(&newArray[index], &B[BSize - Bcount], Bcount*sizeof(TYPE));
	
	else if(Bcount == 0)
		memcpy(&newArray[index++], &A[ASize - Acount], Acount*sizeof(TYPE));
	
	memcpy(A, newArray, (ASize+BSize)*sizeof(TYPE));
	
	return;
}

// Merge Sort 
void IdModifier(SortArray)(TYPE A[], int size, int (*cmp)(TYPE, TYPE)){
	
	if(size <= 1) return;
	
	IdModifier(SortArray)(A, size/2, cmp);
	IdModifier(SortArray)(A+size/2, size - size/2, cmp);
	
	IdModifier(mergeArrays)(A, size/2, A+size/2, size - size/2, cmp);
	
	return;
}

#undef TYPE
#undef IdModifier