/* 
 * Given a sorted array of integers, find the starting and ending 
 * position of a given target value.
 * Your algorithm’s runtime complexity must be in the order of O(log n)
 */

#include <iostream>
#include <assert.h>
#include <vector>

class Solution 
{
public:
	std::vector<int> searchRange(int A[], int n, int target)
	{
		assert(NULL != A && n > 0);

		int left = BinarySearch(A, 0, n, target);
		if (left != -1)
		{
			int index = left;
			while ((index = BinarySearch(A, 0, index - 1, target)) != -1)
				left = index;
		}

		int right = left;
		if (left != -1)
		{
			int index = right;
			while ((index = BinarySearch(A, index + 1, n - 1, target)) != -1)
				right = index;
		}

		std::vector<int> ret;
		ret.push_back(left);
		ret.push_back(right);

		return ret;
	}

private:
	int BinarySearch(int arr[], int l, int r, int target)
	{
		if (l > r)
			return -1;

		assert(NULL != arr && l >= 0);

		int left = l;
		int right = r;

		while (left <= right)
		{
			int mid = ((right - left)>>1) + left;
			if (arr[mid] == target)
			{
				return mid;
			}
			else if (arr[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

		return -1;
	}

};

 int main()
 {
 	int arr[] = {1, 2, 3, 4, 4, 8, 8, 8, 9, 10};
 	Solution s;
	std::vector<int> ret = s.searchRange(arr, sizeof(arr)/sizeof(arr[0]), 8);
	
	std::cout << "[" << ret[0] << "," << ret[1] << "]" << std::endl;

 	return 0;
 }
