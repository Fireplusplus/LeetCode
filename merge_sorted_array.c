#include <stdio.h>


//有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间容纳A2。
//请实现一个函数，把A2中的所有数字插入到A1中并且所有的数字是排序的。
void merge_sorted_arr(int *dst, int len_d, const int *src, int len_s)
{
	int *left = NULL;
	int *right = NULL;
	const int *src_last;
	int total = len_d + len_s;
	if ((NULL == dst) || (NULL == src))
		return;
	if ((len_s <= 0) || (len_d < 0))
		return;

	left = dst + len_d - 1;
	right = dst + len_d + len_s - 1;
	src_last = src + len_s - 1;
	while (total--)
	{
		if (*left <= *src_last)
		{
			*right-- = *src_last--;
		}
		else
		{
			*right-- = *left--;
		}
	}

}

int main()
{
	int i = 0;
	int a[30] = {1, 3, 5, 7, 9};
	int b[] = {0, 2, 4, 6, 8};
	int len_a = sizeof(a) / sizeof(a[0]);

	merge_sorted_arr(a, 5, b, 5);


	for (i = 0; i < len_a; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}



