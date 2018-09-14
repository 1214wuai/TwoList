#include"LinkNode.h"
int main()
{
	List lt;
	ListInit(&lt);
	ListInsert(lt._head, 7);
	ListPushFront(&lt, 1);
	ListPushFront(&lt, 2);
	ListPushFront(&lt, 3);
	ListPushFront(&lt, 4);
	ListPushFront(&lt, 5);
	ListPrint(&lt);
	ListPopBack(&lt);
	ListPrint(&lt);
	ListPushBack(&lt, 0);
	ListPrint(&lt);
	ListPopFront(&lt);
	ListPrint(&lt);
	ListNode *F = ListFind(&lt, Find);
	if (F == NULL)
		printf("ц╩сп%d\n", Find);
	else
		printf("\n%d\n", F->_data);
	ListErase(ListFind(&lt, 2));
	ListPrint(&lt);
	int Empty = ListEmpty(&lt);
	printf("%d\n", ListSize(&lt));
	ListDestory(&lt);
	printf("%d\n", ListSize(&lt));
	ListPrint(&lt);
	system("pause");
	return 0;
}