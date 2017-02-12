#include <stdio.h>


int recurInsertionSort(int array[], int n, int sorted);
int iterInsertionSort(int array[], int n);

int main()
{

	int array[] = {2,3,1,6,8,5};
  recurInsertionSort(array,6,1);

	for(int i = 0; i < 6; i++)
  	printf("%d ", array[i]);

  return 0;
}

int iterInsertionSort(int array[], int n)
{
  int split = 0, temp, j;
  for (int i = 1; i < n; i++)
  {
    temp = array[i];
    for (j = i-1; j>=0 && array[j] > temp; array[j+1] = array[j], j--);
    array[j+1] = temp;
  }

  return 0;
}

int recurInsertionSort(int array[], int n, int sorted)
{
  if (sorted == n)
    return 0;
  int j, temp = array[sorted];
  for (j = sorted-1; j >= 0 && array[j] > temp; array[j+1] = array[j], j--);
  array[j+1] = temp;

  return recurInsertionSort(array, n, ++sorted);
}
