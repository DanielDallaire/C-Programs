#include <stdio.h>

int iterBubbleSort(int array[], int n);
int recurBubbleSort(int array[], int n);

int main()
{
	int array[] = {2,3,1,6,8,5};
	recurBubbleSort(array,6);
	
	for(int i = 0; i < 6; i++)
		printf("%d ", array[i]);
	
	return 0;
}

int iterBubbleSort(int array[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	return 0;
}

int recurBubbleSort(int array[], int n)
{
	if (n == 1)
		return 0; 
	
	int temp;
	
	for (int i = 0; i < n-1; i++)
		if (array[i] > array[i+1])
		{
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	
	return recurBubbleSort(array, --n);
}



