/*
 * Given an array of non-negative integers, you are initially positioned 
 * at the first index of the array.
 * Each element in the array represents your maximum jump length at 
 * that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */

// 由于每层最多可以跳 A[i] 步,也可以跳 0 或 1 步,
// 因此如果能到达最高层,则说明每一层都
// 可以到达
// 正向,从 0 出发,一层一层网上跳,看最后能不能超过最高层,能超过,
// 说明能到达,
// 否则不能到达
class Solution 
{
public:
 	bool canJump(int A[], int n)
	{
		int m = 0;	// 记录从每个位置开始能跳的最远的位置
		for (int i = 0; i < n && i <= max; i++)
		{
			m = std::max(m, i + A[i]);
		}
		
		return m >= n;
	}
};

