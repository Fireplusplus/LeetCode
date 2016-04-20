/* 
 * Plus One:
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
	int i = 0;
	int num = 1;

	assert(digits);
	assert(digitsSize > 0);
	assert(returnSize);

	*returnSize = digitsSize;

	for (i = 0; i < digitsSize; i++)										
	{
		digits[digitsSize - i - 1] = (digits[digitsSize - i - 1] + num) % 10;
		if ((digits[digitsSize - i - 1] + num) < 10)							//没有进位
			break;
		else																	//ÓÐ½øÎ»
			num = (digits[digitsSize - i - 1] + num) % 10;
	}
	if (i < digitsSize && num != 0)												
	{
		digits = (int *)realloc(returnSize, (digitsSize + 1) * sizeof(int));
		memmove(digits + 1, digits, digitsSize * sizeof(int));
		digits[0] = num;
		*returnSize += 1;
	}
	
	return returnSize;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int arr2[7] = {0};
	int i = 0;
	int *p = &i;

	p = plusOne(arr, 6, p);

	system("pause");
	return 0;
}
