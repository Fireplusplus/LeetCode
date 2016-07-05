/*
 * Reverse a linked list from position m to n.
 * Doitin - placeandinone - pass.
 * Forexample: Given1->2->3->4->5->nullptr, m = 2and n = 4, return1->4->3->2->5->nullptr.
 * Note : Given m, n satisfy the following condition : 1 ¡Ü m ¡Ü n ¡Ülength of list
 */
struct ListNode 
{ 
	int val; 
	ListNode *next; 
	ListNode(int x) 
		: val(x)
		, next(nullptr) 
	{}
};

class Solution {
public: 
	ListNode *reverseBetween(ListNode *head, int m, int n) 
	{
		ListNode dummy(-1); 
		dummy.next = head;

		ListNode *prev = &dummy; 

		for (int i = 0; i < m - 1; ++i) 
			prev = prev->next;

		ListNode* const head2 = prev;
		prev = head2->next; 
		ListNode *cur = prev->next; 

		for (int i = m; i < n; ++i) 
		{
			prev->next = cur->next; 
			cur->next = head2->next; 
			head2->next = cur; // Í·²å·¨
			cur = prev->next; 
		} 
	return dummy.next;
	}
};