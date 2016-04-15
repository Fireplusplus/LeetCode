/* 
 * LeetCode, Remove Element
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
	int index = 0;
	int i = 0;

	for (i = 0; i < numsSize; i++)
	{
		if (*(nums + i) != val)		//index记录相等数组中val值的位置（遇到val则不动，否则将val覆盖掉）
			*(nums + index++) = *(nums + i);
	}

	return index;
}

int main()
{
	int arr[] = {3, 2, 2, 3};

	int len = removeElement(arr, sizeof(arr) / sizeof(arr[0]), 3);

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}

	system("pause");
	return 0;
}
