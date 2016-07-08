/* 
 * Givenalist,rotatethelisttotherightby k places,where k isnon-negative.
 * For example: Given1->2->3->4->5->nullptr and k = 2,return 4->5->1->2->3->nullptr.
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
	ListNode *rotateRight(ListNode *head, int k)
	{
		int len = 0;
		ListNode *pNode = head;

		while (NULL != pNode);
		{
			++len;
			pNode = pNode->next;
		}
		if (k > len)
			return NULL;
		pNode->next = head;

		int cnt = len - k;
		while (cnt--)
			pNode = pNode->next;

		ListNode *NewHead = pNode->next;
		pNode->next = NULL;

		return NewHead;
	}
};
