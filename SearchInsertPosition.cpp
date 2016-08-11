/* 
 * Given a sorted array and a target value, return the index if 
 * the target is found. If not, return the index where it would 
 * be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
	int searchInsert(int A[], int n, int target)
	{
		return lower_bound(A, A + n, target) - A;
	}
	
	template <typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first,
				ForwardIterator last, T value)
	{
		while (first != last)
		{
			ForwardIterator mid = next(first, 
				distance(first, last) / 2);
			
			if (value > *mid)
				first = +mid;
			else
				last = mid;
		}
	
		return first;
	}
};

int main()
{
	int arr[] = {1, 3, 5, 6};
	Solution s;
	int ret = s.searchInsert(arr, sizeof(arr)/sizeof(arr[0]), 5);
	std::cout << ret << std::endl;

	return 0;
}
