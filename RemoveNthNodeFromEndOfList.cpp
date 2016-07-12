/* 
 * Given a linked list,remove the nth node from the end of list and return it shead. For example,Given linked 
 * list: 1->2->3->4->5,and n =2. After removing the second node from the end,the linked list 
 * becomes 1->2->3->5. Note: • Given n will always bevalid.
 * Try to do this in one pass.
 */

#include <iostream>


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x)
		: val(x)
		, next(nullptr)
	{}
};

class Solution
{
	//1, 2,    3, 4, 5
public:
	ListNode *removeNthFromEnd(ListNode *&head, int n)
	{
		ListNode *pFast = head, *pSlow = head;
		if (NULL == head || n <= 0)
			return NULL;

		while (--n)
		{
			if (pFast->next == NULL)
				return NULL;
			pFast = pFast->next;
		}

		ListNode *pPre = pSlow;
		while (NULL != pFast->next)
		{
			pPre = pSlow;
			pSlow = pSlow->next;
			pFast = pFast->next;
		}
		if (pSlow == head)	//要删除的是头结点
		{
			head = head->next;
			delete pSlow;
		}
		else
		{
			pPre->next = pSlow->next;
			delete pSlow;
		}
		return head;
	}
};

void print(ListNode *head)
{
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void test()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	print(p1);

	Solution s;
	ListNode *head = s.removeNthFromEnd(p1, 2);
	print(head);
}

int main()
{
	test();
	return 0;
}