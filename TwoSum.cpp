/* 
 * Given an array of integers,find two numbers such that they add up to a specific target number. 
 * The function two Sum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
 * are not zero-based. You may assume that each input would have exactly one solution. 
 * Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

//暴力求解
class Solution1
{
public: 
	vector<int> twoSum(vector<int> &num, int target)
	{
		vector<int> rs;

		for (int i = 0; i < num.size(); ++i)
		{
			for (int j = i + 1; j < num.size(); j++)
			{
				if (num[i] + num[j] == target)
				{
					rs.push_back(i + 1);
					rs.push_back(j + 1);
					return rs;
				}
			}
		}
		return rs;
	}
};

//用一个哈希表，存储每个数对应的下标
class Solution2
{
public:
	vector<int> twoSum(vector<int> &num, int target)
	{
		vector<int> rs;
		unordered_map<int, int> m;

		int i;
		for (i = 0; i < num.size(); i++)
			m[num[i]] = i;
		
		for (i = 0; i < num.size(); i++)
		{
			int sub = target - num[i];
			if (m.find(sub) != m.end() && m[sub] > i)
			{
				rs.push_back(i + 1);
				rs.push_back(m[sub] + 1);
				break;
			}
		}

		return rs;
	}
};

void test1()
{
	vector<int> arr;
	arr.push_back(7);
	arr.push_back(11);
	arr.push_back(2);
	arr.push_back(15);

	Solution2 s;
	vector<int> rs = s.twoSum(arr, 9);

	cout << rs[0] << endl;
	cout << rs[1] << endl;
}

int main()
{

	test1();

	return 0;
}