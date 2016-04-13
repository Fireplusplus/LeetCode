/* 
 * LeetCode, Remove Duplicates from Sorted Array II 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
 * It doesn't matter what you leave beyond the new length. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 2

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int index = 2;

	if (numsSize <= 2)					//bunsSize小于等于2，必定符合要求
		return numsSize;
	for (i = 2; i < numsSize; i++) {
		if (*(nums + index - 2) != *(nums + i)) {	
			*(nums + (index++)) = *(nums + i);	//从左向右依次排列
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
