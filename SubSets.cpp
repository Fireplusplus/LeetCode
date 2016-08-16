/*
 * Given a set of distinct integers, S, return all possible subsets.
 * Note:
 * • Elements in a subset must be in non-descending order.
 * • The solution set must not contain duplicate subsets.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int> > subsets(vector<int> &s)
	{
		sort(s.begin(), s.end());
		vector<vector<int> > result;
		vector<int> path;
		subsets(s, path, 0, result);

		return result;
	}

private:
	static void subsets(const vector<int> &s, vector<int> &path, 
		int step, vector<vector<int> > &result)
	{
		if (step == s.size())
		{
			result.push_back(path);
			return;
		}

		subsets(s, path, step + 1, result);

		path.push_back(s[step]);
		subsets(s, path, step + 1, result);
		path.pop_back();
	}
};



int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<vector<int> > ret;
	ret = s.subsets(v);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			std::cout << ret[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
