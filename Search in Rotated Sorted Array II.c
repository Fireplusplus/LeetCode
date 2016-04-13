/* 
 * leetcode, Search in Rotated Sorted Array II
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

bool search(int* nums, int numsSize, int target) {
	int first = 0;
	int last = numsSize - 1;
	/*
	 * �����ظ�����ȣ���ͬ���ǣ��� nums[first] <= nums[mid] ʱ�������Դ��ж�[first,mid]�ǵ�����
	 * ���Ե� nums[first] = nums[mid] ʱ��++first,����һ���ظ�����������ѭ���жϣ�
	 * ֱ��nums[first] ��= nums[mid],��ʱ������������ظ�������������ͬ��
	 */
	while (first <= last) {
		int mid = (last - first) / 2 + first;
		if (*(nums + mid) == target)
			return true;
		else if (*(nums + first) < *(nums + mid)) {
			if (*(nums + first) <= target && *(nums + mid) > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
		else if (*(nums + first) > *(nums + mid)) {
			if (*(nums + last) >= target && *(nums + mid) < target)
				first = mid + 1;
			else
				last = mid - 1;
		}
		else {    //����һ���ظ�����
			++first;
		}
	}
	return false;
}
int main()
{
	int arr[] = { 1, 3, 1, 1, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	bool ret = search(arr, sz, 1);
	if (ret == true)
		printf("true\n");
	else
		printf("false\n");
	system("pause");
	return 0;
}