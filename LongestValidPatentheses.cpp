/* 
 * Given a string containing just the characters ’(’ and ’)’, 
 * find the length of the longest valid (well-formed) parentheses substring.
 * For ”(()”, the longest valid parentheses substring is ”()”, 
 * which has length = 2.
 * Another example is ”)()())”, where the longest valid parentheses 
 * substring is ”()()”, which has length = 4.
 */

#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
	int longestValidParentheses(string s)
	{
		int max_len = 0;
		int last = -1; //记录栈底'('的前一个位置

		stack<int> left;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				left.push(i);
			}
			else
			{
				if (left.empty())
				{
					last = i;
				}
				else
				{	
					left.pop();
					if (s.empty())
						max_len = max(max_len, i - last);
					else
						max_len = max(max_len, i - left.top());
				}
			}
		
		}
		return max_len;
	}
};

int main()
{
	Solution s;	
	int ret = s.longestValidParentheses(")(()()");
	std::cout << ret << std::endl;

	return 0;
}
