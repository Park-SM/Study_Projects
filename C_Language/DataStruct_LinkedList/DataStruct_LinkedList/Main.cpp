#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode *NextNode;
} Node;

Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->NextNode = NULL;
	return NewNode;
}

void AppendNode(Node **HeadNode, Node *NewNode) {
	if (*HeadNode == NULL) {
		*HeadNode = NewNode;
	} else {
		Node *TailNode = *HeadNode;
		while (TailNode->NextNode != NULL) TailNode = TailNode->NextNode;
		TailNode->NextNode = NewNode;
	}
}

void PrintList(Node *List) {
	if (List != NULL) {
		while (List != NULL) {
			printf("> Data: %d\tCurrent Address: %p\tNextNode Address: %p\n", List->Data, List, List->NextNode);
			List = List->NextNode;
		}
	} else puts("> No data..");
}

void DeleteList(Node *Current) {
	if (Current->NextNode != NULL) DeleteList(Current->NextNode);
	free(Current);
}

void InsertNode(Node **HeadNode, int TargetData, Node *NewNode) {
	if ((*HeadNode)->Data == TargetData) {
		Node *TempNode = *HeadNode;
		*HeadNode = NewNode;
		NewNode->NextNode = TempNode;
	} else {
		Node *PreNode = *HeadNode;
		while (PreNode->NextNode != NULL && PreNode->NextNode->Data != TargetData) PreNode = PreNode->NextNode;
		if (PreNode->NextNode != NULL) {
			Node *TempNode = PreNode->NextNode;
			PreNode->NextNode = NewNode;
			NewNode->NextNode = TempNode;
		} else puts("> There is no TargetData.");
	}
}

void DeleteNode(Node **HeadNode, int TargetData) {
	if ((*HeadNode)->Data == TargetData) {
		Node *TempNode = *HeadNode;
		*HeadNode = (*HeadNode)->NextNode;
		free(TempNode);
	} else {
		Node *PreNode = *HeadNode;
		while (PreNode->NextNode != NULL && PreNode->NextNode->Data != TargetData) PreNode = PreNode->NextNode;
		if (PreNode->NextNode != NULL) {
			Node *TempNode = PreNode->NextNode;
			PreNode->NextNode = PreNode->NextNode->NextNode;
			free(TempNode);
		} else puts("> There is no TargetData.");
	}
}

int main() {

	Node *List = NULL;

	for (int i = 1; i <= 5; i++)
		AppendNode(&List, CreateNode(i));

	puts(":::: 링크드 리스트 생성 후 출력 ::::");
	PrintList(List);

	puts("\n:::: 링크드 리스트 중간삭제 후 출력 ::::");
	DeleteNode(&List, 1);
	DeleteNode(&List, 3);
	DeleteNode(&List, 5);
	PrintList(List);

	puts("\n:::: 링크드 리스트 중간삽입 후 출력 ::::");
	InsertNode(&List, 2, CreateNode(777));
	InsertNode(&List, 4, CreateNode(999));
	PrintList(List);

	puts("\n:::: 링크드 리스트 일괄삭제 후 출력 ::::");
	DeleteList(List);
	List = NULL;
	PrintList(List);

	system("PAUSE");
	return 0;
}