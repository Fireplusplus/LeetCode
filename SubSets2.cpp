#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) 
	{
		sort(S.begin(), S.end()); // 必须排序
		vector<vector<int> > result;
		vector<int> path;
		dfs(S, S.begin(), path, result);
		return result;
	}

private:

	static void dfs(const vector<int> &S, vector<int>::iterator start,
		vector<int> &path, vector<vector<int> > &result) 
	{
		result.push_back(path);
		for (vector<int>::iterator i = start; i < S.end(); i++) 
		{
			// 保证路径的同一位置不会出现两次同一个数的不同副本
			if (i != start && *i == *(i-1)) 
				continue;
			path.push_back(*i);
			dfs(S, i + 1, path, result);
			path.pop_back();
		}
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);

	vector<vector<int> > ret;
	ret = s.subsetsWithDup(v);

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
