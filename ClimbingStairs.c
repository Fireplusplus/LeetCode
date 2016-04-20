/* Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top? 
 */
#define _CRT_SECURE_NO_WARNINGS
/* 
 * 思路:设爬n个阶梯有f(n)种不同的方法，那么为了爬到第n阶，有两种选择：
 * 1、从第n-1阶前进一步
 * 2、从第n-2阶前进两步
 * 其实就是斐波那契数列：f(n) = f(n-1) + f(n-2)
 * 爬到第n阶的方法数为爬到第n-1阶的方法数加上爬到第n-2阶的方法数之和
 * 注意：爬到第n-2阶是还剩两阶，看似有两种方法，但一次走一阶的方法包含在f(n-1)里面了，所以只能一次走两阶
 * 所以走到n-1或者n-2时，就没得选了
 * 所以此题实际求第n+1个斐波那契数(边界)
 */
int climbStairs(int n)
{
	int i = 0;
	int num1 = 1, num2 = 1, num3 = 1;

	for (i = 2; i < n + 1; i++)
	{
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;	
	}
	return num3;
}

int main()
{
	int i = 0;

	i = climbStairs(3);

	return 0; 
}