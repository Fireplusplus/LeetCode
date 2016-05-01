#include <stdio.h>

struct Node
{
	int value;
	struct Node *next;
}NODE, *PNODE;

void AddToTail(PNODE *pHead, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->value = value;
	pNew->next = NULL;
	

	if (NULL == pHead)
		return;
	if (NULL == *pHead)
	{
		*pHead = pNew;
	}
	else
	{
		PNODE p = *pHead;
		while (NULL != *pHead->next)
		{
			p = p->next;
		}
		p->next = pNew;
	}

}


void RemoveNOde(PNODE *pHead, int val)
{
	PNODE p = NULL;
	if ((NULL == pHead) || (NULL == *pHead))
	{
		return;
	}

	if (val == *pHead->value)
	{
		p = *pHead;
		*pHead = p->next;
	}
	else
	{
		while ((NULL != *pHead->next) && (val != *pHead->next->val))
		{
			*pHead->next = *pHead->next->next;
		}
		if ((NULL != *pHead->next) && (val == *pHead->next->val))
		{
			p = *pHead;
			*pHead->next = p->next;
		}
	}
	
	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
	
}

int main()
{




	return 0;
}
