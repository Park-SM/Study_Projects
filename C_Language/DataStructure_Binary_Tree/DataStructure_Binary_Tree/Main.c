#include <stdio.h>
#include <stdlib.h>		// malloc(), free(), system()

// ����� ����ü ���� �� ����.
typedef struct tagNode {
	int Data;
	struct tagNode *LeftNode;
	struct tagNode *RightNode;
}Node;

// ���ο� ��� �����ϴ� �Լ�, ���� ���� ����� Data�κп� ���� ���� �Ű������� ����.
Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->LeftNode = NULL;
	NewNode->RightNode = NULL;

	return NewNode;
}

// InputData�Լ� �ȿ��� ���Ǵ� ����Լ�, Tree�� RootNode�� ù��° �Ű������� �ְ� ��� ���� ���� ��͵Ǹ� Ž��.
// CreateNode�Լ��� ���ο� ��带 ����� �� ����� �����ּҸ� �����ϴµ� �� �����ּҸ� NewNode�� ��.
void InputData_in(Node *Current, Node *NewNode) {
	if (Current->Data != NewNode->Data) {				// ���� Ž���ϰ��ִ� ���� ���� ������� ����� ������ ���� �ٸ��ٸ�.
		if (Current->Data > NewNode->Data) {			// ���� Ž���ϰ��ִ� ����� ������ ���� ���� ������� ����� ������ ������ ũ�ٸ�.
			if (Current->LeftNode != NULL) InputData_in(Current->LeftNode, NewNode);	// ���ʳ�尡 �����Ѵٸ� ���� ���� ����Լ� ����.
			else Current->LeftNode = NewNode;			// ���� ��尡 �������� �ʴٸ� ���� ��忡 ���ο� ����� ���� �ּҸ� �����ϹǷν� ���ʳ�忡 ����.
		} else {										// ���� Ž���ϰ��ִ� ����� ������ ���� ���� ������� ����� ������ ������ �۴ٸ�.
			if (Current->RightNode != NULL) InputData_in(Current->RightNode, NewNode);	// �����ʳ�尡 �����Ѵٸ� ������ ���� ����Լ� ����.
			else Current->RightNode = NewNode;			// ������ ��尡 �������� �ʴٸ� ������ ��忡 ���ο� ����� �����ּҸ� �����ϹǷν� �����ʳ�忡 ����.
		}
	} else {											// ���� Ž���ϰ� �ִ� ���� ���� ������� ����� ������ ���� ���ٸ� ����ó��.
		puts(">> Error: Data Duplication.");
		free(NewNode);									// CreateNode�Լ��� ���� �̹� Heap���� �޸� �� Node�� �����ϰ� �����Ƿ� �ʿ���� NewNode�� �����ؾ���.
	}
}

// ���������� Main�Լ����� �� ���縦 ���� ���Ǵ� �Լ�.
// RootNode�� ���������ͷ� ������ ������ InputData�Լ��� ȣ���ϴ� Main�Լ����� �ȿ� ����Ǿ��ִ� �̱�������(*)�� ��������ġ�ּ�(&)�� ���޹޾� �ٽ� �������Ͽ�
// Main�Լ� �ȿ� ����Ǿ��ִ� �̱�������(*)�� ���� �ٲ���ϱ� ����, NewNode�� CreateNode�Լ��� ���� ���Ϲ��� ���ο� ����� �����ּ�.
void InputData(Node **RootNode, Node *NewNode) {
	if (*RootNode == NULL) *RootNode = NewNode;		// Main�Լ����� Tree�� �����ϴ� �ּҸ� �����ϰ� �ִ� �����Ͱ� NULL�̶�� �� Tree�� ��尡 �Ѱ��� ���ٸ� ���ο� ��带 ����.
	else InputData_in(*RootNode, NewNode);			// Main�Լ����� Tree�� �����ϴ� �ּҸ� �����ϰ� �ִ� �����Ͱ� NULL�� �ƴ϶�� ��尡 1�� �̻��� ����Ǿ��ִٴ� ���̹Ƿ�,	 ����Լ��� ���� ���� ����.
}

// RootNode�� �ּҸ� �ְ�, sData�� Ž���ϰ� ���� ������ ���� �Է�.
int SearchData(Node *RootNode, int sData) {
	int SearchedData = -1;							// return SearchedData;������ SearchedData������ �������� �ʰ� -1�� �����ϸ� ã�� ���� ����.

	if (RootNode != NULL) {							// Tree�ȿ� ��尡 1�� �̻��� ���� ���.
		if (RootNode->Data != sData) {				// ���� Ž���ϰ��ִ� ���� Ž���ϰ� ���� ������ ���� ���� �ʴٸ�.
			if (RootNode->Data > sData) {					// ���� Ž���ϰ��ִ� ����� ������ ���� Ž���ϰ� ���� ������ ������ ũ�ٸ�.
				if (RootNode->LeftNode != NULL) SearchedData = SearchData(RootNode->LeftNode, sData);		// ���ʳ�尡 �����Ѵٸ� ���� ���� ��� Ž��.
			} else {										// ���� Ž���ϰ��ִ� ����� ������ ���� Ž���ϰ� ���� ������ ������ �۴ٸ�.
				if (RootNode->RightNode != NULL) SearchedData = SearchData(RootNode->RightNode, sData);		// �����ʳ�尡 �����Ѵٸ� �����ʳ��� ��� Ž��.
			}
		} else {									// ���� Ž���ϰ� �ִ� ���� Ž���ϰ� ���� ������ ���� ���ٸ�.
			SearchedData = RootNode->Data;			// ���� Ž���ϰ� �ִ� ����� �����͸� ��ȯ�� ������ ����.
			printf(">> Successfully searched:: The data retrieved is %d.\n", SearchedData);		// ������ �˻� ����� ���.
		}
	} else puts("\n>> Error: Tree is empty.");		// Tree�ȿ� ��尡 1���� ���� ��� ����ó��.

	return SearchedData;							// �˻� ��� ����.
}

// Tree ���� ���.
// �Ű����� level������ Tree�� ���̸� ������. ���̸� �����ϴ� ������ ����� �� Tree�� ���� ��ŭ �鿩���⸦ �ϱ� ���ؼ� ������.
void PrintTree(Node *RootNode, int level) {
	if (RootNode != NULL) {										// Tree�� ��尡 1�� �̻��� ���� ���.
		if (RootNode->RightNode != NULL) PrintTree(RootNode->RightNode, level + 1);				// ������ ��尡 ����Ǿ��ִٸ� ������ ���� ��� Ž��.
		for (int i = 0; i < level; i++) printf("\t"); printf("> %d\n", RootNode->Data);			// ���� ����� ���̸�ŭ �鿩���� �� ��, ���� ����� ������ ���� ���.
		if (RootNode->LeftNode != NULL) PrintTree(RootNode->LeftNode, level + 1);				// ���� ��尡 ����Ǿ��ֵ��� ���� ���� ��� Ž��.
	} else puts(">> Error: Tree is empty.");					// Tree�� ��尡 1���� ���� ��� ���� ó��.
}

// Tree�� �ϰ�����.
// �Ű����� RootNode�� ����������(**)�� ������ ������ main�Լ� �ȿ� *RootNode�� ������ ���� �����ϱ� ���� ����.
void DeleteTree(Node **RootNode) {
	if ((*RootNode)->RightNode != NULL) DeleteTree(&((*RootNode)->RightNode));				// ������ ��尡 ����Ǿ��ִٸ� ������ ���� ��� Ž��.
	if ((*RootNode)->LeftNode != NULL) DeleteTree(&((*RootNode)->LeftNode));				// ���� ��尡 ����Ǿ��ֵ��� ���� ���� ��� Ž��.
	free(*RootNode);																		// ���� ��� �Ҵ� ����.
	*RootNode = NULL;																		// ���� ��带 ����Ű�� �����Ϳ� NULL�� ����. ��尡 ���ٴ� ��.
}

int main() {

	Node *RootNode = NULL;			// Tree�� RootNode�� ����Ű�� ������, Tree�� �����ּ�.
	int DataArray[] = { 24, 5, 37, 1, 61, 11, 7, 59, 15, 48, 19, 28 };			// ������ ������ ��.

	puts(" :::: Input data :::::");
	for (int i = 0; i < sizeof(DataArray) / sizeof(DataArray[0]); i++)			// ������ ������ �� �迭�� ���� ��ŭ �ݺ��Ͽ� InputData�Լ��� Tree�� �� �ֱ�.
		InputData(&RootNode, CreateNode(DataArray[i]));

	puts("\n :::: Print Tree :::::");
	PrintTree(RootNode, 0);							// Tree���, �ι�° �Ű����� level�� 0�� �ִ� ������ RootNode�� ���̰� 0�̱� ����.

	puts("\n :::: Search data :::::");
	int uSearchData = 7;							// ã�� ���� �����͸� 7�� ����.
	if (SearchData(RootNode, uSearchData) == -1) puts(">> Error: There is no data");		// ã������ ������ ���� Tree�ȿ� ���ٸ� ����ó��.

	puts("\n :::: Delete Tree :::::");
	DeleteTree(&RootNode);										// Tree �ϰ� ����.
	if (RootNode == NULL) puts(">> Successfully deleted");		// Tree �ϰ� ������ �����ߴٸ�.

	puts("\n :::: Print Tree :::::");
	PrintTree(RootNode, 0);							// �ϰ�����ó���� Ȯ���ϱ� ���� Tree�� ���.

	system("PAUSE");			// ��� ���� Ȯ���ϱ� ���� Console�� �Ͻ�������.
	return 0;
}