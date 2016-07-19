/* 
 * 简单背包问题：假设有一个能装入总体积为T的背包和N件体积分别为w1,w2,w3...wn的物品，能否从n件物品中挑选若干件恰好
 * 装满背，即w1+w2+...+wn = T,要求满足上述条件的解。
 */

#include <iostream>
#include <stack>
#include <queue>

//T = 10 {1, 8, 4, 3, 5, 2}
void pack(int T, int arr[], int n)
{
	if (NULL == arr || n <= 0)
		return;

	std::stack<int> pack;
	std::stack<int> index;
	int sum = 0;
	
	int tag = -1; //记录上次入栈的位置

	while (!(tag == n - 1 && pack.empty()))
	{
		for (int i = tag + 1; i < n; ++i)
		{
			if (sum + arr[i] <= T)
			{
				sum += arr[i];
				pack.push(arr[i]);
				index.push(i);
				
				//打印
				if (T == sum)
				{
					std::stack<int> print(pack);
					std::stack<int> tmp;
					while (!print.empty())
					{
						tmp.push(print.top());
						print.pop();
					}
					while (!tmp.empty())
					{
						std::cout << tmp.top() << " ";
						tmp.pop();
					}
					std::cout << std::endl;
				}
			}		
		}
		
		//失效元素退栈
		sum -= pack.top();
		pack.pop();
		tag = index.top();		
		index.pop();
	}
}

int main()
{
	int arr[] = {1, 8, 4, 3, 5, 2};
	pack(10, arr, 6);

	return 0;
}
