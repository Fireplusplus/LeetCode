/* 
 * LeetCode, Remove Duplicates from Sorted Array  
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 2

int remove(int *arr, int sz)
{
	int i = 0;
	int index = 0;
	if(numsSize == 0)
		return 0;
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
