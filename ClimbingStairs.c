/* Climbing Stairs
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top? 
 */
#define _CRT_SECURE_NO_WARNINGS
/* 
 * ˼·:����n��������f(n)�ֲ�ͬ�ķ�������ôΪ��������n�ף�������ѡ��
 * 1���ӵ�n-1��ǰ��һ��
 * 2���ӵ�n-2��ǰ������
 * ��ʵ����쳲��������У�f(n) = f(n-1) + f(n-2)
 * ������n�׵ķ�����Ϊ������n-1�׵ķ���������������n-2�׵ķ�����֮��
 * ע�⣺������n-2���ǻ�ʣ���ף����������ַ�������һ����һ�׵ķ���������f(n-1)�����ˣ�����ֻ��һ��������
 * �����ߵ�n-1����n-2ʱ����û��ѡ��
 * ���Դ���ʵ�����n+1��쳲�������(�߽�)
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