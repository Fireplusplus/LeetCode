/* 
 * Given a string, determine if it is a palindrome, considering only 
 * alphanumeric characters and ignorin cases.
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		string::iterator left = s.begin();
		string::iterator right = --s.end();

		while (left < right)
		{
			if (!isalnum(*left))
				++left;
			else if (!isalnum(*right))
				--right;
			else if (*left != *right)
				return false;
			else
			{
				++left;
				--right;
			}
		}
		return true;
	}
};

int main()
{
	string s("A man, a plan, a canal: panama");

	Solution so;
	cout << so.isPalindrome(s) << endl;

	return 0;
}
