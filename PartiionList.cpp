/* 
 * Given a linked list and a value x, partition it such that all nodes less than x come before 
 * nodes greater thanorequalto x. You should preserve the original relative order of the nodes 
 * in each of the two partitions. 
 * For example,Given1->4->3->2->5->2andx = 3,return1->2->2->4->3->5.
 */

#include <iostream>

using namespace std;

// 单链表节点 
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
	ListNode* partition(ListNode* head, int x)
	{
		ListNode l(-1), r(-1);
		ListNode *left = &l;
		ListNode *right = &r;

		for (head; head != NULL; head = head->next)
		{
			if (head->val < x)
			{
				left->next = head;
				left = left->next;
			}
			else
			{
				right->next = head;
				right = right->next;
			}
		}
		left->next = r.next;
		right->next = NULL;
		return l.next;
	}
};

void test()
{
	ListNode n1(1);
	ListNode n2(4);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(5);
	ListNode n6(2);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;

	Solution s;
	ListNode *ret = s.partition(&n1, 3);

	while (NULL != ret)
	{
		cout << ret->val << "->";
		ret = ret->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	test();

	return 0;
}