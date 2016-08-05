/* 
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes 
 * of the first two lists.
 */

class Solution 
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (NULL == l1)
			return l2;
		if (NULL == l2)
			return l1;

		ListNode dummy(-1);
		for (; l1 != NULL && NULL != l2; p = p->next)
		{
			if (l1->val > l2->val)
			{
				p->next = l2;
				l2 = l2->next;
			}
			else
			{
				p->next = l1;
				l1 = l1->next;
			}
		}
		p->next = l1 != NULL ? l1 : l2;
		
		return dummy.next;
	}
};
