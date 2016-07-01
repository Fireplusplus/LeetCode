/* 
 * Given an array S of n integers,are there elements a,b,c,and d in S such that a+b+c+d = target? 
 * Find all unique quadruplets in the array which gives the sum of target. 
 * Note:
 * • Elements in a quadruplet (a,b,c,d) must be in non-descend in gorder. (ie, a ≤ b ≤ c ≤ d) 
 * • The solution set must not contain duplicate quadruplets. 
 * For example,given array S = {1 0 -1 0 -2 2},and target = 0. 
 * A solution set is: (-1, 0, 0, 1) (-2, -1, 1, 2) (-2, 0, 0, 2)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//方法一：暴力求解，先排序，再左右夹逼，时间复杂度O(n3)
class Solution1
{
public:
	vector<vector<int> > fourSum(vector<int>& num, int target)
	{
		vector<vector<int> > rs;
		
		if (num.size() < 4)
			return rs;
		
		sort(num.begin(), num.end());
		auto last = num.end();
		for (auto a = num.begin(); a < prev(last, 3); ++a)
		{
			for (auto b = next(a); b < prev(last, 2); ++b)
			{
				auto c = next(b);
				auto d = prev(last);

				while (c < d)
				{
					int sum = *a + *b + *c + *d;
					if (sum < target)
						++c;
					else if (sum > target)
						--d;
					else
					{
						rs.push_back({*a, *b, *c, *d});
						++c;
						--d;
					}
				}
			}
		}

		sort(rs.begin(), rs.end());
		rs.erase(unique(rs.begin(), rs.end()), rs.end());
		
		return rs;
	}
};

//用哈希表存储前两个值的和
class Solution2
{
public:
	vector<vector<int> > fourSum(vector<int>& num, int target)
	{
		vector<vector<int> > rs;

		if (num.size() < 3)
			return rs;

		sort(num.begin(), num.end());

		unordered_map < int, vector<pair<int, int> > > cache;
		for (int a = 0; a < num.size(); ++a)
		{
			for (int b = a + 1; b < num.size(); ++b)
			{
				cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
			}
		}

		for (int c = 0; c < num.size(); ++c)
		{
			for (int d = c + 1; d < num.size(); ++d)
			{
				const int key = target - num[c] - num[d];
				if (cache.find(key) == cache.end())
					continue;

				const auto &vec = cache[key];
				for (int k = 0; k < vec.size(); ++k)
				{
					if (c <= vec[k].second)
						continue;

					rs.push_back({ num[vec[k].first], num[vec[k].second], num[c], num[d] });
				}
			}
		}
		
		sort(rs.begin(), rs.end());
		rs.erase(unique(rs.begin(), rs.end()), rs.end());

		return rs;
	}
};

void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);

	Solution2 s;
	auto rs = s.fourSum(v, 0);

	for (auto i = rs.begin(); i < rs.end(); i++)
	{
		for (auto j = i->begin(); j < i->end(); j++)
			cout << *j << " ";
		cout << endl;
	}
}

int main()
{
	test();

	return 0;
}