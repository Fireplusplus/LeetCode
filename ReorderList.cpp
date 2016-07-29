/*
 * Given a singly linked list L : L 0 → L 1 → · · · → L n−1 → L n , 
 * reorder it to: L 0 → L n → L 1 → L n−1 → L 2 → L n−2 → · · ·
 * You must do this in-place without altering the nodes’ values.
 * For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include <iostream>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) 
		: val(x)
		, next(NULL) 
	{}
};

//先从中间断开，然后归并
class Solution
{
public:
	void recorderList(ListNode *head)
	{
		if (NULL == head || NULL == head->next)
			return;

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *prev = NULL;

		while (NULL != fast && NULL != fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		
		slow = reverse(slow);

		ListNode *cur = head;
		while (NULL != cur->next)
		{
			ListNode *tmp = cur->next;
			cur->next = slow;
			slow = slow->next;
			cur->next->next = tmp;
			cur->next = slow;
		}
		cur->next = slow;
	}

	ListNode *reverse(ListNode *head)
	{
		if (NULL == head || NULL == head->next)
			return head;
		
		ListNode *prev = head;
		for (ListNode *cur = head->next, *next = cur->next; cur;
			prev = cur, cur = next, next = next ? next->next : NULL)
		{
			cur->next = prev;
		}
		head->next = NULL;
		return prev;
	}
};

