/* 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example, Given1->1->2,return1->2.
 * Given1->1->2->3->3,return1->2->3. 
 */

#include <iostream>

using namespace std;

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
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (NULL == head)
			return NULL;

		ListNode real_head(head->val - 1);
		real_head.next = head;

		recur(&real_head, head);
		return real_head.next;
	}
private:
	static void recur(ListNode *pPre, ListNode *pCur)
	{
		if (NULL == pCur)
			return;
		if (pPre->val == pCur->val)
		{
			pPre->next = pCur->next;
			delete pCur;
			recur(pPre, pPre->next);
		}
		else
			recur(pPre->next, pCur->next);
	}
};

class Solution2
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (NULL == head)
			return NULL;

		for (ListNode *pPre = head, *pCur = head->next; NULL != pCur; pCur = pPre->next)
		{
			if (pPre->val == pCur->val)
			{
				pPre->next = pCur->next;
				delete pCur;
			}
			else
				pPre = pCur;
		}

		return head;
	}
};

void test()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(2);
	ListNode *p4 = new ListNode(3);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	Solution2 s;
	ListNode *ret = s.deleteDuplicates(p1);
	ListNode *tmp = ret;
	while (NULL != tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;

	//destroy
}

int main()
{
	test();

	return 0;
}