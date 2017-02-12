#include <stdio.h>

int iterSelectionSort(int array[], int n);
int recurSelectionSort(int array[], int n, int split);

int main()
{
	int array[] = {2,3,1,6,8,5};
	recurSelectionSort(array,6,0);
	
	for(int i = 0; i < 6; i++)
		printf("%d ", array[i]);
	
	return 0;
}

int iterSelectionSort(int array[], int n)
{
	int lvalue = 0, temp;
	for (int i = 0; i < n; i++)
	{
		lvalue = 0;
		for (int j = 0; j < n-i; j++)
			if (array[j] > array[lvalue])
				lvalue = j;
		temp = array[lvalue];
		array[lvalue] = array[n-i-1];
		array[n-i-1] = temp;
	}
	return 0;
}


int recurSelectionSort(int array[], int n, int split)
{
	if (n - split == 1)
		return 0;
	int temp, large = 0;
	for (int i = 1; i <= n-split-1; i++)
		if (array[i] > array[large])
			large = i;
	temp = array[large];
	array[large] = array[n-1-split];
	array[n-1-split] = temp;
	
	return recurSelection(array,n,++split);
	
}