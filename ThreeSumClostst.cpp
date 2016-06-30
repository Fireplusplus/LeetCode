/* 
 * Given an array S of n integers, find three integers in S such that the sum is closest to 
 * a given number, target. Return the sum of the three integers. You may assume that each input 
 * would have exactly one solution. 
 * For example, given array S = {-1 2 1 -4},and target = 1. 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//œ»≈≈–Ú£¨»ª∫Û◊Û”“º–±∆£¨∏¥‘”∂» O(n2)
class Solution
{
public: 
	int threeSumClosest(vector<int>& num, int target)
	{
		int rs;
		int min_sub = INT_MAX;

		sort(num.begin(), num.end());

		for (auto a = num.begin(); a < prev(num.end(), 2); a++)
		{
			auto b = next(a);
			auto c = prev(num.end());

			while (b < c)
			{
				const int sum = *a + *b + *c;
				const int sub = abs(sum - target);

				if (sub < min_sub)
				{
					min_sub = sub;
					rs = sum;
				}

				if (sum < target)
					++b;
				else
					--c;
			}
		}

		return rs;
	}
};

int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-4);

	Solution s;
	int rs = s.threeSumClosest(v, 1);
	
	cout << rs << endl;

	return 0;
}