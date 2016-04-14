/* 
 * LeetCode, Median of Two Sorted Arrays 
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)). 
 */

/* 这是一道非常经典的题。
 * 这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第 k 大的元素。 
 * O(m + n) 的解法比较直观，直接 merge 两个数组，然后求第 k 大的元素。 
 * 不过我们仅仅需要第 k 大的元素，是不需要“排序”这么复杂的操作的。
 * 可以用一个计数器， 记录当前已经找到第 m 大的元素了。同时我们使用两个指针 pA 和 pB，
 * 分别指向 A 和 B 数组的第 一个元素，使用类似于mergesort的原理，如果数组A当前元素小，
 * 那么 pA++，同时 m++；如果数 组B当前元素小，那么 pB++，同时 m++。最终当 m 等于 k 的时候，
 * 就得到了我们的答案，O(k) 时 间，O(1) 空间。但是，当 k 很接近 m + n 的时候，
 * 这个方法还是 O(m + n) 的。 有没有更好的方案呢？我们可以考虑从 k 入手。
 * 如果我们每次都能够删除一个一定在第 k 大元 素之前的元素，那么我们需要进行 k 次。
 * 但是如果每次我们都删除一半呢？由于 A 和 B 都是有序 的，我们应该充分利用这里面的信息，
 * 类似于二分查找，也是充分利用了“有序”。 假设 A 和 B 的元素个数都大于 k/2，
 * 我们将 A 的第 k/2 个元素（即 A[k/2-1]）和 B 的第 k/2 个元素（即 B[k/2-1]）进行比较，
 * 有以下三种情况（为了简化这里先假设 k 为偶数，所得到的结论 对于 k 是奇数也是成立的）： 
 * • A[k/2-1] == B[k/2-1] 
 * • A[k/2-1] > B[k/2-1] 
 * • A[k/2-1] < B[k/2-1] 
 * 如果 A[k/2-1] < B[k/2-1]，意味着 A[0] 到 A[k/2-1 的肯定在 A∪B 的 top k 元素的范围 内，
 * 换句话说，A[k/2-1 不可能大于 A∪B 的第 k 大元素。留给读者证明。 
 * 因此，我们可以放心的删除 A 数组的这 k/2 个元素。
 * 同理，当 A[k/2-1] > B[k/2-1] 时，可 以删除 B 数组的 k/2 个元素。 
 * 当 A[k/2-1] == B[k/2-1] 时，说明找到了第 k 大的元素，直接返回 A[k/2-1] 或 B[k/2-1] 即可。 
 * 因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？ 
 * • 当 A 或 B 是空时，直接返回 B[k-1] 或 A[k-1]； 
 * • 当 k=1 是，返回 min(A[0], B[0])； 
 * • 当 A[k/2-1] == B[k/2-1] 时，返回 A[k/2-1] 或 B[k/2-1]
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int find_kth(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
	int i1 = 0, i2 = 0;
	/* 保证nums1Size <= nums2Size */
	if (nums1Size > nums2Size)
		return find_kth(nums2, nums2Size, nums1, nums1Size, k);
	if (nums1Size == 0)
		return *(nums2 + k - 1);
	if (k == 1)
		return *nums1 < *nums2 ? *nums1 : *nums2;

	i1 = nums1Size < (k / 2) ? nums1Size : (k / 2);
	i2 = k - i1;

	if (*(nums1 + i1 - 1) < *(nums2 + i2 - 1))
		return find_kth(nums1 + i1, nums1Size - i1, nums2, nums2Size, k - i1);
	else if (*(nums1 + i1 - 1) > *(nums2 + i2 - 1))
		return find_kth(nums1, nums1Size, nums2 + i2, nums2Size - i2, k - i2);
	else
		return *(nums1 + i1 - 1);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int total = nums1Size + nums2Size;
	if (total & 1)		//total为奇数
		return find_kth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
	else				//total为偶数， 则求最中间两数的平均值
		return (find_kth(nums1, nums1Size, nums2, nums2Size, total / 2) +
		find_kth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1)) / 2.0;

}

int main()
{
	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8, 9};
 
	double mid = findMedianSortedArrays(a,sizeof(a) / sizeof(a[0]), 
				b, sizeof(b) / sizeof(b[0]));
	printf("%lf\n", mid);

	system("pause");
	return 0;
}