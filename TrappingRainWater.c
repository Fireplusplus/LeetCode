/* 
 * Given n non-negative integers representing an elevation map
 * where the width of each bar is 1, compute how much water it is able to trap after raining.
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.  
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int trap(int* height, int heightSize) 
{
	int i = 0;
	int sum = 0;
	int *left_max = (int *)calloc(heightSize, sizeof(int));
	int *right_max = (int *)calloc(heightSize, sizeof(int));

	for (i = 1; i < heightSize; i++)			//求取左右两边最大值
	{
		left_max[i] = max(left_max[i - 1], height[i - 1]);
		right_max[heightSize - 1 - i] = max(right_max[heightSize - i], height[heightSize - i]);
	}
	for (i = 0; i < heightSize; i++)
	{
		int high = min(left_max[i], right_max[i]);
		if (high > height[i])					//把每个柱子的面积并累加
		{
			sum += high - height[i];
		}
	}

	free(left_max);
	free(right_max);
	return sum;
}
/* 
 * 思路：1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
 * 2. 从右往左扫描一遍，对于每个柱子，求最大右值； 
 * 3. 再扫描一遍，把每个柱子的储水量累加 
 */
int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	int sum = trap(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", sum);

	system("pause");
	return 0;
}