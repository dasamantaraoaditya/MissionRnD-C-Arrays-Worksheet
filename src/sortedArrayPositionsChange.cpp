/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int start = 0, end = len - 1, temp;
	if (Arr == NULL || len<0)
		return NULL;

	while (Arr[start] < Arr[start + 1])start++;
	while (Arr[end] > Arr[end - 1])end--;
	temp = Arr[start];
	Arr[start] = Arr[end];
	Arr[end] = temp;
}