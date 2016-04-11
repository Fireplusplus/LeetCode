/* LeetCode, Remove Duplicates from Sorted Array  */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 2

int remove(int *arr, int sz)
{
	int i = 0;
	int index = 0;

	for (i = 1; i < sz; i++) {
		if (arr[index] != arr[i]) {	//依次向后找不等的，挨个排列
			arr[++index] = arr[i];
		}
	}

	return index + 1;
}

int main()
{
	int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 7, 8};
	int i = 0, j = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int len = 0;

	len = remove(arr, sz);
	printf("%d\n", len);

	system("pause");
	return 0;
}