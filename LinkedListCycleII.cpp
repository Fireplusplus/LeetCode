/* 
 *  单链表节点
 * struct ListNode {
 *	int val;
 *	ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) { }
 * };
 */
/*  
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 * Follow up: Can you solve it without using extra space?
 */

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				ListNode *slow2 = head;

				while (slow2 != slow)
				{
					slow2 = slow2->next;
					slow = slow->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};
