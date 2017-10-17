// Created by Daniel Dallaire

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Sort Test
void testSort(void (*sort)(int*, int), int testData[], const int n, const char name[]);

// Sorting 
void bubbleSort(int array[], int size);
void selectionSort(int array[], int n);
void insertionSort(int array[], int n);
void cocktailShaker(int array[], int n);
void mergeSort(int array[], int n);
void quickSort(int array[], int n);

// Helper
void mergeList(int* a, int* b, int aSize, int bSize);	

int main(){
	srand(time(NULL));
	const int testSize = 200000;
	int testData[testSize];
	
	for(int i = 0; i < testSize; i++) testData[i] = rand()%testSize;
	
	testSort(&bubbleSort, testData, testSize, "bubble");
	testSort(&selectionSort, testData, testSize, "selection");
	testSort(&insertionSort, testData, testSize, "insertion");
	testSort(&cocktailShaker, testData, testSize, "cocktail shaker");
	testSort(&mergeSort, testData, testSize, "merge");
	testSort(&quickSort, testData, testSize, "quick");
  
  return 0;
}

// Sort Test
void testSort(void (*sort)(int*, int), int testData[], int n, const char name[]){
	int array[n];
	for(int i = 0; i < n; i++) array[i] = testData[i];
	
	int temp = clock();
	printf("*** %s sort start ***\n", name);
	(*sort)(array, n);
	printf("*** %s sort end (%d milliseconds) ***\n\n",name , (int) (clock() - temp));

	return;
}

// Sorting algorithms
void bubbleSort(int array[], int n){
	int temp;
	for(int i = 0; i < n - 1 ; i++){
		for(int j = 0; j < n - i -1; j++)
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	}
	
}

void selectionSort(int array[], int n){
	int hi, temp;
	for(int i = 0; i < n - 1; i++){
		hi = 0;
		for(int j = 1; j < n - i; j++){
			if(array[j] > array[hi]) hi = j;
		}
		temp = array[n-i-1];
		array[n-i-1] = array[hi];
		array[hi] = temp;
	}
}

void insertionSort(int array[], int n){
	int temp;
	for(int i = 1; i < n; i++){
		for(int j = i; j > 0; j--){
			if(array[j] < array[j-1]){
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
	}
	
	return;
}

void cocktailShaker(int array[], int n){
	int hi, lo, temp;
	
	for(int i = 0; i < (n+1)/2; i++){
		hi = lo = i;
		for(int j = 0; j < n-i-1; j++){
			if(array[j+1] < array[lo]) lo = j+1;
			if(array[j+1] > array[hi]) hi = j+1;
		}
		
		temp = array[n-1-i];
		array[n-1-i] = array[hi];
		array[hi] = temp;
		
		temp = array[i];
		array[i] = array[lo];
		array[lo] = temp;
	}
	
	return;
}

void mergeSort(int array[], int n){
	if(n == 0 || n == 1) return;

	mergeSort(array, n/2);
	mergeSort(array + n/2, n/2 + n%2);

	mergeList(array, array + n/2, n/2, n/2 + n%2);

	return;
}

void quickSort(int array[], int n){
	if(n == 0 || n == 1) return;

	int partition = 0, pivot = array[n-1], temp;

	for(int i = 0; i < n - 1; i++){
	if(array[i] < pivot){
	  temp = array[partition];
	  array[partition] = array[i];
	  array[i] = temp;

	  partition++;
	}
	}

	temp = array[partition];
	array[partition] = array[n - 1];
	array[n - 1] = temp;

	quickSort(array, partition);
	quickSort(array + partition + 1, n - partition - 1);

	return;
}

// Helper functions
void mergeList(int* a, int* b, const int aSize, const int bSize){

	int sorted[aSize + bSize];

	int i = 0, j = 0, k = 0;

	while(i != aSize || j != bSize){
	if(i == aSize){
	  sorted[k] = *(b+j);
	  j++;
	}
	else if(j == bSize){
	  sorted[k] = *(a+i);
	  i++;
	}
	else{
	  if(*(a+i) > *(b+j)){
		sorted[k] = *(b+j);
		j++;
	  }
	  else{
		sorted[k] = *(a+i);
		i++;
	  }
	}
	k++;
	}

	for(int r = 0; r < aSize + bSize; r++)
	*(a+r) = sorted[r];

	return;
}
