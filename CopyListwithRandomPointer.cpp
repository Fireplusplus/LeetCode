/* 
 * A linked list is given such that each node contains an additional 
 * random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

#include <iostream>

using namespace std;

struct RandomListNode 
{
	int val;
	RandomListNode *rand;
	RandomListNode *next;
	
	RandomListNode(int x = 0) 
		: val(x)
		, rand(NULL)
		, next(NULL) 
	{}
};

void print_by_next(RandomListNode *head);
void print_by_rand(RandomListNode *head);

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode *newHead = NULL;
		RandomListNode *newTail = NULL;
		RandomListNode *p1 = head;
		
		newHead = new RandomListNode();
		newTail = newHead;
		while (NULL != p1)
		{
			newTail->next = new RandomListNode(p1->val);	
			newTail = newTail->next;
			p1 = p1->next;
		}
		
		RandomListNode *p2 = newHead->next;
		for (p1 = head; NULL != p1; )
		{
			RandomListNode *tmp_p2 = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2 = tmp_p2;
		}
		
		p1 = head;
		while (NULL != p1)
		{
			if (NULL == p1->rand)
				p1->next->rand = NULL;
			else
				p1->next->rand = p1->rand->next;
			p1 = p1 ->next->next;
		}
		
		p2 = newHead;
		RandomListNode *pre;
		p1 = head;
		while (NULL != p1)
		{
			pre = p1;
			p2->next = p1->next;
			p1->next = p2->next;
			p1 = p1->next->next;
			p2 = p2->next;
		}
		pre->next = NULL;
		p2 = newHead->next;
		delete newHead;
		
		return p2;
	}
};

void print_by_rand(RandomListNode *head)
{	
	while (NULL != head)
	{
		cout << head->val << " ";
		head = head->rand;
	}
	cout << endl;
}

void print_by_next(RandomListNode *head)
{
	while (NULL != head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void test()
{
	RandomListNode *p1 = new RandomListNode(1);
	RandomListNode *p2 = new RandomListNode(2);
	RandomListNode *p3 = new RandomListNode(3);
	RandomListNode *p4 = new RandomListNode(4);
	RandomListNode *p5 = new RandomListNode(5);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	
	p1->rand = p2;
	p2->rand = p3;
	p3->rand = p4;
	p4->rand = p5;

	print_by_next(p1);
	print_by_rand(p1);

	Solution s;
	RandomListNode *ret = s.copyRandomList(p1);
	
	print_by_next(ret);
	print_by_rand(ret);
}

int main()
{
	test();

	return 0;
}
