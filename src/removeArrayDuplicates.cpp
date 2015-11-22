/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int i = 0, j = 0, flag, k = 0;
	if (Arr == NULL || len<0)
		return NULL;
	for (i = 0; i < len; i++)
	{
		flag = 1;
		for (j = 0; j < i; j++)
		{
			if (Arr[j] == Arr[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			Arr[k++] = Arr[i];
	}
	for (i = k; i < len; i++)
		Arr[i] = '\0';
}