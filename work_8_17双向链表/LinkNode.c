#include"LinkNode.h"
ListNode* BuyListNode()
{
	ListNode *lt = (ListNode*)malloc(sizeof(ListNode));
	lt->_next = lt;
	lt->_prev = lt;
	return lt;
}
void ListInit(List* lt)
{
	assert(lt);
	lt->_head = BuyListNode();
	lt->_head->_next = lt->_head;
	lt->_head->_prev = lt->_head;
}
void ListDestory(List* lt)
{
	assert(lt);
	
	ListNode *cur = lt->_head->_next;
	while (cur != lt->_head)
	{
		cur = lt->_head->_next;
		lt->_head->_next = cur->_next;
		cur->_next->_prev = lt->_head;
		cur->_next = NULL;
		cur->_prev = NULL;
		free(cur);
		cur = NULL;
		cur = lt->_head->_next;
	}
}
void ListPushBack(List* lt, LTDataType x)
{
	assert(lt);
	ListInsert(lt->_head, x);

}
void ListPushFront(List* lt, LTDataType x)
{
	assert(lt);
	ListInsert(lt->_head->_next, x);
}
void ListPopBack(List* lt)
{
	assert(lt);
	ListNode *cur = lt->_head;
	while (cur->_next != lt->_head)
	{
		cur = cur->_next;
	}
	cur->_prev->_next = lt->_head;
	lt->_head->_prev = cur->_prev;
	cur->_next = NULL;
	cur->_prev = NULL;
	free(cur);
	cur = NULL;
}
void ListPopFront(List* lt)
{
	assert(lt);
	ListNode *cur = lt->_head->_next;
	if (cur != lt->_head)
	{
		lt->_head->_next = cur->_next;
		cur->_next->_prev = lt->_head;
		cur->_next = NULL;
		cur->_prev = NULL;
		free(cur);
		cur = NULL;
	}
	else
		return;
}

ListNode* ListFind(List* lt, LTDataType x)
{
	assert(lt != NULL);
	ListNode *cur = lt->_head->_next;
	if (cur == lt->_head)
		return NULL;//没有节点
	while (cur!=lt->_head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
return NULL;//没有找到元素
}
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	//ListNode *Find = ListFind(pos, x);
	ListNode* newnode = BuyListNode();
	newnode->_data = x;
	newnode->_next = pos;
	newnode->_prev = pos->_prev;
	pos->_prev->_next = newnode;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode *del = pos;
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	pos->_next = NULL;
	pos->_prev = NULL;
	free(del);
	del = NULL;
}

int ListSize(List* lt)
{
	assert(lt);
	int count = 0;
	ListNode *cur = lt->_head;
	while (cur->_next != lt->_head)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}
int ListEmpty(List* lt)
{
	if (ListSize(lt) == 0)
		return 0;
	return 1;
}

void ListPrint(List* lt)
{
	ListNode *cur = lt->_head->_next;
	assert(lt != NULL);
	while (lt->_head != cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}