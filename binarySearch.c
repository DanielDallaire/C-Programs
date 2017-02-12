#include <stdio.h>

int iterBinSearch(int array[], int sv, int n);
int recurBinSearch(int array[], int sv, int hi, int lo);

int main()
{
	int array[] = {2,3,1,6,8,5};
	printf("%d", recurBinSearch(array, 8, 5,0));
	return 0;
}

int iterBinSearch(int array[], int sv, int n)
{
	int hi = n-1, lo = 0, mid = (hi + lo)/2;
	
	while (array[mid] != sv && hi > lo)
	{
		if (sv > array[mid])
			lo = mid+1;
		else
			hi = mid-1;
		mid = (hi + lo)/2;
	}
	return mid;
}

int recurBinSearch(int array[], int sv, int hi, int lo)
{
	int mid = (hi + lo) / 2;
	if (array[mid] == sv)
		return mid;
	if (array[mid] > sv)
		return recurBinSearch(array,sv,mid-1,lo);
	return recurBinSearch(array,sv,hi,mid+1);
	
}