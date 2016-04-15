#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
	int index = 0;
	int i = 0;

	for (i = 0; i < numsSize; i++)
	{
		if (*(nums + i) != val)
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