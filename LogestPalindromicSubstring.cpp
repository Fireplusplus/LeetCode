/* 
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there exists 
 * one unique longest palindromic substring.
 */

#include <iostream>
#include <string>

using namespace std;


// 暴力枚举,以每个元素为中间元素,同时从左右出发
class Solution 
{
public:
	string longestPalindrome(string s)
	{
		int size = s.size();
		const char *begin = s.c_str();
		const char *end = begin + size - 1;
		if (0 == size)
			return s;

		int max = 0;
		string rs;
		
		// 奇数串
		for (int i = 0; i < size; ++i)
		{
			const char *left = begin + i;		
			const char *right = left;
			int cnt = 0;
			for (; left >= begin && right <= end; --left, ++right)
			{
				if (*left != *right)
					break;
				++cnt;
			}
			if (cnt > max)
			{
				rs = string(left + 1, right);
				max = cnt;
			}
		}
		
		// 偶数串
		for (int i = 0; i < size - 1; ++i)
		{
			const char *left = begin + i;
			const char *right = left + 1;
			int cnt = 0;
			
			for (; left >= begin && right <= end; --left, ++right)
			{
				if (*left != *right)
					break;
				++cnt;
			}
			if (cnt > max)
			{
				rs = string(++left, right);
				max = cnt;
			}
		}
		return rs;
	}
};

int main()
{
	string str("bbbbabcdcba");

	Solution s;
	string ret = s.longestPalindrome(str);
	cout << ret << endl;
	
	return 0;
}
