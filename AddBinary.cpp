/*
 * Given two binary strings, return their sum (also a binary string).
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string result;
		const size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int carry = 0;

		for (size_t i = 0; i < n; ++i)
		{
			int ai = i < a.size() ? a[i]-'0' : 0;
			int bi = i < b.size() ? b[i]-'0' : 0;
			int val = (ai + bi + carry) % 2;
			result.insert(result.begin(), val + '0');
		}
		if (1 == carry)
			result.insert(result.begin(), '1');
		return result;
	}
};

int main()
{
	string s1("11");
	string s2("1");
	
	Solution s;
	cout << s.addBinary(s1, s2) << endl;

	return  0;
}

