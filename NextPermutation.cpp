/* 
 * Implement next permutation, which rearranges numbers into the 
 * lexicographically next greater permu-tation of numbers.
 * If such arrangement is not possible, it must rearrange it as the 
 * lowest possible order (ie, sorted in ascend-ing order).
 * The replacement must be in-place, do not allocate extra memory
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 1.从右至左依次找出第一个破坏升序的元素(可能找不到，已经是最大排列顺序,
// reverse后直接返回)
// 2.再从又至左找第一个比这个元素大的元素
// 3.交换这两个元素
// 4.reverse第一个找到的元素的下标之后的所有元素
class Solution
{
public:
	int nextPermutation(vector<int> &num)
	{
		next_permutation(num);
	}
	bool next_permutation(vector<int> &num)
	{
		vector<int>::reverse_iterator rfirst = num.rbegin();
		vector<int>::reverse_iterator rlast = num.rend();

		vector<int>::reverse_iterator first = rfirst + 1;
		while (rlast != first && *first > *(first - 1))
		{
			++first;
		}
		if (rlast == first)
		{
			reverse(rfirst, rlast);
			return false;
		}

		vector<int>::reverse_iterator change = 
		find_if(rfirst, first, bind1st(less<int>(), *first));

		swap(*first, *change);
		reverse(rfirst, first);

		return true;
	}
};

 int main()
 {
 	vector<int> v;
	v.push_back(6);
	v.push_back(8);
	v.push_back(7);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	
	Solution s;
	s.nextPermutation(v);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " "; 
	}
	std::cout << std::endl;

 	return 0;
 }
