/* 
 * Given an array of integers,every element appears three times except for one. 
 * Find that single one. 
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extramemory?
 */

#include <iostream>

using namespace std;

class Solution
{
public: 
	int singleNumber(int A[], int n)
	{
		const int width = sizeof(int) * 8;
		int cnt[width] = {0};

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				cnt[j] += (A[i] >> j) & 1;
				cnt[j] %= 3;
			}
		}
		int rs = 0;
		for (int i = 0; i < width; ++i)
		{
			rs += cnt[i] << i;
		}

		return rs;
	}

};

int  main()
{
	int arr[] = {1, 10, 1, 6, 10, 1, 10};
	Solution s;
	int ret = s.singleNumber(arr, 7);
	cout << ret << endl;

	return 0;
}