/* leetcode, Search in Rotated Sorted Array  */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target)
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