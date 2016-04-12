/* LeetCode, Remove Duplicates from Sorted Array II */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 2

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int index = 2;

	if (numsSize <= 2)
		return numsSize;
	for (i = 2; i < numsSize; i++) {
		if (*(nums + index - 2) != *(nums + i)) {
			*(nums + (index++)) = *(nums + i);
		}
	}

	return index;
}
int main()
{
	int arr[] = { 1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8 };
	int i = 0, j = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int len = 0;

	len = removeDuplicates(arr, sz);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	system("pause");
	return 0;
}