/*
 * Given an unsorted integer array, find the first missing positive 
 * integer.
 * For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 */

#include <iostream>
#include <string.h>

// 适用于数字范围较小
class Solution 
{
public:
	int firstMissingPositive(int A[], int n)
	{
		int max = A[0];
		int min = A[0];
		int i = 1;
		for (; i < n; ++i)
		{
			if (max < A[i])
				max = A[i];
			if (A[i] > 0 && min > A[i])
				min = A[i];
		}
		if (min <= 0)
			return 0;

		int *cnt = new int[max + 1];
		memset(cnt, 0, (max+1) * sizeof(int));

		for (i = 0; i < n; ++i)
		{
			if (A[i] > 0)
				cnt[A[i]]++;
		}

		for (i = 1; i <= max; ++i)
		{
			if (cnt[i] == 0)
				break;
		}
		
		delete[] cnt;
		return i;
	}
};

int main()
{
	int arr[] = {3, 4, -1, 1};
	Solution s;
	int ret = s.firstMissingPositive(arr, sizeof(arr)/sizeof(arr[0]));
	std::cout << ret << std::endl;

	return 0;
}
