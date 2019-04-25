/*
	���׽� ���� ����.
*/
#include <stdio.h>
#include <stdlib.h>		// malloc(), free()
#include <math.h>		// pow()

// ����Ʈ ����ü ���� �� ����.
typedef struct tagNode {
	int Data1;
	int Data2;
	struct tagNode *NextNode;
} Node;

// ����Ʈ ���� �� �ʱ�ȭ.
Node* CreateNode(int nData1, int nData2) {
	Node *NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data1 = nData1;
	NewNode->Data2 = nData2;
	NewNode->NextNode = NULL;

	return NewNode;
}

// ��� ����.
void AppendNode(Node **HeadNode, Node *NewNode) {
	if (*HeadNode == NULL) {
		*HeadNode = NewNode;
	} else {
		Node *TailNode = *HeadNode;
		while (TailNode->NextNode != NULL) TailNode = TailNode->NextNode;
		TailNode->NextNode = NewNode;
	}
}

// ����Ʈ ���, ����Ʈ�� ��������� "No Data.." ���.
void PrintList(Node *List) {
	if (List != NULL) {
		while (List != NULL) {
			printf("(%dx^%d)", List->Data1, List->Data2, List->NextNode);
			if (List->NextNode != NULL) printf(" + ");
			List = List->NextNode;
		}
		puts("");
	} else puts("No data..");
}

// ����Ʈ �ϰ�����, ����Լ��� ����.
void DeleteList(Node *Current) {
	if (Current->NextNode != NULL) DeleteList(Current->NextNode);
	free(Current);
}


// ���Ŀ� ��� //
// ���Ļ��� �˻�, ���� ���¸� 0�� ����, ������ ���¸� 1�� ����.
int CheckSort(Node *List) {
	while (List->NextNode != NULL && List->Data2 > List->NextNode->Data2) List = List->NextNode;
	if (List->NextNode == NULL) return 0;
	else return 1;
}

// ���Ŀ� ��� //
// �Ű����� *SwapNode�� �ٷ� �� ���� �ڸ��� �ٲ�.
void SwapNode(Node **HeadNode, Node *SwapNode) {
	if (*HeadNode == SwapNode) {
		*HeadNode = SwapNode->NextNode;
		SwapNode->NextNode = (*HeadNode)->NextNode;
		(*HeadNode)->NextNode = SwapNode;
	}
	else {
		Node *TempNode = *HeadNode;
		while (TempNode->NextNode != SwapNode) TempNode = TempNode->NextNode;
		TempNode->NextNode = SwapNode->NextNode;
		SwapNode->NextNode = TempNode->NextNode->NextNode;
		TempNode->NextNode->NextNode = SwapNode;
	}
}

// ���Ŀ� ��� //
// ����Ʈ�� ����, ���� main()���� ���̴� �κ�.
void BubbleSort(Node **List) {
	Node *Current;
	while (CheckSort(*List)) {
		Current = *List;
		while (Current->NextNode != NULL) {
			if (Current->Data2 < Current->NextNode->Data2) SwapNode(List, Current);
			else Current = Current->NextNode;
		}
	}
}

// List2�� List1�� ����, List2�� ������ List1�� ���յǾ����Ƿ� List2�� ���ۺκ��� NULL�� ����.
void MergeList(Node **List1, Node **List2) {	// main()�� ���������� List1, List2 �����ͺ����� ���� �����ϱ� ����, ���� �����͸� ���.
	Node *TempList1, *TempList2, *TempNode;		// List1, List2 ����Ʈ ��ȸ�� ���� ������ ���� *TempList1, *TempList2�� ����, ������ ����� �ּҰ��� �ӽ����� �� List2�� ���� ��带 �ӽ������� ���� *TempNode�� ����.

	BubbleSort(List1);	// List1�� ����.
	BubbleSort(List2);	// List2�� ����.
	TempList1 = *List1;
	TempList2 = *List2;
	while (TempList2 != NULL && (*List1)->Data2 < TempList2->Data2) {		// ù ��� ó�� => List1�� ù��° ����� ������ List2�� ù��° ����� �������� ������ ū ��Ȳ���� ����.
		TempNode = TempList2->NextNode;
		TempList2->NextNode = *List1;
		*List1 = TempList2;
		TempList2 = TempNode;
	}

	while (TempList2 != NULL) {
		if (TempList1->Data2 == TempList2->Data2) {
			TempList1->Data1 += TempList2->Data1;
			TempNode = TempList2;
			TempList1 = TempList1->NextNode;
			TempList2 = TempList2->NextNode;
			free(TempNode);
		} else if (TempList1->Data2 > TempList2->Data2) {
			Node *cTempList1 = TempList1;					// List1�� ��尡 List2�� ��庸�� ���������� Ŭ �� �ֱ� ������ ������ �������ְ� ���� ���� while������ ��ȸ.
			while (cTempList1->NextNode != NULL && cTempList1->NextNode->Data2 > TempList2->Data2) cTempList1 = cTempList1->NextNode;
			if (cTempList1->NextNode != NULL) {
				if (cTempList1->NextNode->Data2 == TempList2->Data2) {
					cTempList1->NextNode->Data1 += TempList2->Data1;
					TempNode = TempList2;								// ������ ����� �ּҸ� �ӽ� ����.
					TempList2 = TempList2->NextNode;					//     => List1�� ������ List2�� ������ ���ٸ� List2�� ����� ����κ��� List1�� ��忡 �����ְ� List2�� free����. => �޸� ���� ����.
					free(TempNode);
				}
				else {
					TempNode = TempList2->NextNode;
					TempList2->NextNode = cTempList1->NextNode;
					cTempList1->NextNode = TempList2;
					TempList2 = TempNode;
				}
			} else {		// List1�� �����ٰ� List2�� ���̱�
				cTempList1->NextNode = TempList2;
				TempList2 = NULL;
			}
		}
	}
	*List2 = NULL;
}

// ���׽� ���
int Calculator(int x, Node *List) {
	if (List != NULL) {
		int Result = 0;
		while (List != NULL) {
			Result += List->Data1 * (int)pow((double)x, (double)(List->Data2));
			List = List->NextNode;
		}
		return Result;
	}
	return 0;
}

int main() {

	// ����Ʈ�� �����ּҸ� �����ϴ� �����ͺ��� ����.
	Node *List1 = NULL;
	Node *List2 = NULL;

	// List1�� ��� �߰�.
	AppendNode(&List1, CreateNode(1, 1));
	AppendNode(&List1, CreateNode(2, 7));
	AppendNode(&List1, CreateNode(3, 9));
	AppendNode(&List1, CreateNode(3, 3));
	AppendNode(&List1, CreateNode(3, 11));

	// List2�� ��� �߰�.
	AppendNode(&List2, CreateNode(10, 2));
	AppendNode(&List2, CreateNode(20, 5));
	AppendNode(&List2, CreateNode(20, 7));
	AppendNode(&List2, CreateNode(20, 8));
	AppendNode(&List2, CreateNode(20, 12));
	AppendNode(&List2, CreateNode(20, 1));
	AppendNode(&List2, CreateNode(20, 0));

	// List1�� List2�� ���.
	printf("List1 >> "); PrintList(List1);
	printf("List2 >> "); PrintList(List2);

	// List1�� List2�� ����.
	puts("\n   ::: Merging :::\n");
	MergeList(&List1, &List2);

	// List1�� List2�� ���.
	printf("List1 >> "); PrintList(List1);
	printf("List2 >> "); PrintList(List2);

	// List1�� ���׽Ŀ� x���� �־� ����� ����� ���.
	printf("\nf(1) >> %d\n", Calculator(1, List1));
	printf("f(2) >> %d\n", Calculator(2, List1));
	printf("f(3) >> %d\n", Calculator(3, List1));

	// List1�� �ϰ�����.
	DeleteList(List1);
	List1 = NULL;

	puts("");
	system("PAUSE");
	return 0;
} 