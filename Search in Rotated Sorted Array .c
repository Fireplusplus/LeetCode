/*
 * leetcode, Search in Rotated Sorted Array  
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target)		//二分查找，难度主要在于左右边界的确定
{
	int first = 0;
	int last = numsSize - 1;

	while (first <= last) {
		int mid = (last - first) / 2 + first;
		if (*(nums + mid) == target)
			return mid;
		else if (*(nums + first) <= *(nums + mid)) {
			if (*(nums + first) <= target && target < *(nums + mid))
				last = mid - 1;
			else
				first = mid + 1;
		}
		else {
			if (*(nums + mid) < target && target <= *(nums + last))
				first = mid + 1;
			else
				last = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {4, 5, 6, 7, 1, 2, 3};
	int sz = sizeof(arr) / sizeof(arr[0]);

	int index = search(arr, sz, 3);
	if (index != -1)
		printf("%d\n", index);

	system("pause");
	return 0;
}
