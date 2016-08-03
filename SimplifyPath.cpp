/* 
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * Corner Cases:
 * • Did you consider the case where path = "/../"? 
 * In this case, you should return "/".
 * • Another corner case is the path might contain multiple 
 * slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string simplifyPath(string const& path) 
	{
		std::stack<std::string> rs;
		
		std::string::const_iterator begin = path.begin();
		while (begin != path.end())
		{
			++begin;
			std::string::const_iterator last = 
				find(begin, path.end(), '/');
			std::string tmp(begin, last);

			if (!tmp.empty() && tmp != ".")
			{
				if (tmp == "..")
				{
					if (!rs.empty())
						rs.pop();
				}
				else
					rs.push(tmp);
			}

			begin = last; 
		}

		std::string ret;
		if (rs.empty())
			ret.insert(0, "/");
		else
		{
			while (!rs.empty())
			{
				ret.insert(0, rs.top());
				ret.insert(0, "/");
				rs.pop();
			}
		}

		return ret;
	}
};

int main()
{
	Solution s;
	std::string ret = s.simplifyPath("/home/gao/..//liang");
	std::cout << ret << std::endl;

	return 0;
}
