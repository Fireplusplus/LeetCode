/* 
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two number sand return it as a linked list. 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) 
 * Output: 7 -> 0 -> 8
 */
#include <iostream>

using namespace std;

struct ListNode 
{ 
	int val; 
	ListNode *next; 
	ListNode(int x) : val(x), next(nullptr) 
	{} 
};

class Solution {
public: 
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode head(-1);
		ListNode *pHead = &head;
		ListNode *pTail = pHead;
		int carry = 0;

		ListNode *L1 = l1, *L2 = l2;
		while (nullptr != L1 && nullptr != L2)
		{
			int sum = L1->val + L2->val + carry;
			carry = sum / 10;
			sum %= 10;
			L1 = L1->next;
			L2 = L2->next;
			pTail->next = new ListNode(sum);
			pTail = pTail->next;
		}

		ListNode *pTemp ;
		if (nullptr != L1)
			pTemp = L1;
		else
			pTemp = L2;
		while (nullptr != pTemp)
		{
			int sum = pTemp->val + carry;
			carry = sum / 10;
			sum %= 10;
			pTail->next = new ListNode(sum);
			pTail = pTail->next;
			pTemp = pTemp->next;
		}

		if (carry > 0)
			pTail->next = new ListNode(carry);

		return pHead->next;
	}
};

void test()
{
	ListNode *p1 = new ListNode(2);
	p1->next = new ListNode(4);
	p1->next->next = new ListNode(3);

	ListNode *p2 = new ListNode(5);
	p2->next = new ListNode(6);
	p2->next->next = new ListNode(8);
	p2->next->next->next = new ListNode(9);


	Solution s;
	ListNode *p3 = s.addTwoNumbers(p1, p2);

	while (p3)
	{
		cout << p3->val << " ";
		p3 = p3->next;
	}
	cout << endl;
}

int main()
{
	test();

	return 0;
}