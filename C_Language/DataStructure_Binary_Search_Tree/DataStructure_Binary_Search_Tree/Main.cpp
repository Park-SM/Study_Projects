#include <stdio.h>
#include <stdlib.h>		// malloc(), free(), system()

// ����� ����ü ���� �� ����.
typedef struct tagNode {
	int Data;
	struct tagNode *LeftNode;
	struct tagNode *RightNode;
} Node;

// ���ο� ��� �����ϴ� �Լ�, ���� ���� ����� Data�κп� ���� ���� �Ű������� ����.
Node *CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = nData;
	NewNode->LeftNode = NULL;
	NewNode->RightNode = NULL;

	return NewNode;
}

// InputData�Լ� �ȿ��� ���Ǵ� ����Լ�, Tree�� RootNode�� ù��° �Ű������� �ְ� ��� ���� ���� ��͵Ǹ� Ž��.
// CreateNode�Լ��� ���ο� ��带 ����� �� ����� �����ּҸ� �����ϴµ� �� �����ּҸ� NewNode�� ��.
void InputData_in(Node *RootNode, Node *NewNode) {
	if (RootNode->Data != NewNode->Data) {				// ���� Ž���ϰ��ִ� ���� ���� ������� ����� ������ ���� �ٸ��ٸ�.
		if (RootNode->Data > NewNode->Data) {			// ���� Ž���ϰ��ִ� ����� ������ ���� ���� ������� ����� ������ ������ ũ�ٸ�.
			if (RootNode->LeftNode != NULL) InputData_in(RootNode->LeftNode, NewNode);	// ���ʳ�尡 �����Ѵٸ� ���� ���� ����Լ� ����.
			else RootNode->LeftNode = NewNode;			// ���� ��尡 �������� �ʴٸ� ���� ��忡 ���ο� ����� ���� �ּҸ� �����ϹǷν� ���ʳ�忡 ����.
		} else {										// ���� Ž���ϰ��ִ� ����� ������ ���� ���� ������� ����� ������ ������ �۴ٸ�.
			if (RootNode->RightNode != NULL) InputData_in(RootNode->RightNode, NewNode);	// �����ʳ�尡 �����Ѵٸ�
			else RootNode->RightNode = NewNode;			// ������ ��尡 �������� �ʴٸ� ������ ��忡 ���ο� ����� �����ּҸ� �����ϹǷν� �����ʳ�忡 ����.
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

// RootNode�� �ּҸ� �ְ�, sData�� Ž���ϰ� ���� ������ ���� �Է�. �˻��� �����ϸ� -999�� ����.
int SearchData(Node *RootNode, int uData) {
	int SearchedData = -999;			// return SearchedData;������ SearchedData������ �������� �ʰ� -999�� �����ϸ� ã�� ���� ����.
	if (RootNode != NULL) {						// Tree�ȿ� ��尡 1�� �̻��� ���� ���.
		while (RootNode != NULL) {					// Ʈ���� Ž�� ��ȸ�ϴ� �����Ͱ� �˸��� �����͸� ã�� ���ϰ� NULL�� ���� ������ �ݺ�.
			if (RootNode->Data != uData) {						// ���� Ž���ϴ� ����� �����Ϳ� ������ �����Ͱ� ���� �ʴٸ�.
				if (RootNode->Data > uData) RootNode = RootNode->LeftNode;	 // ���� �����Ͱ� ���� Ž���ϴ� �������� ������ �۴ٸ� ���� ��忡�� ���� ���� �̵�.
				else RootNode = RootNode->RightNode;						// ���� �����Ͱ� ���� Ž���ϴ� �������� ������ ũ�ٸ� ���� ��忡�� ������ ���� �̵�.
			} else { SearchedData = RootNode->Data;	break; }	// ���� Ž���ϴ� ����� �����Ϳ� ������ �����Ͱ� ���� �� ������ ������ �����͸� �����ϰ� �ݺ��� Ż��.
		}
	}
	return SearchedData;		// �˻� ��� ����.
}

// Tree�� �ϰ�����.
// �Ű����� RootNode�� ����������(**)�� ������ ������ main�Լ� �ȿ� *RootNode�� ������ ���� �����ϱ� ���� ����.
void DeleteTree(Node **RootNode) {
	if ((*RootNode)->RightNode != NULL) DeleteTree(&((*RootNode)->RightNode));				// ������ ��尡 ����Ǿ��ִٸ� ������ ���� ��� Ž��.
	if ((*RootNode)->LeftNode != NULL) DeleteTree(&((*RootNode)->LeftNode));				// ���� ��尡 ����Ǿ��ֵ��� ���� ���� ��� Ž��.
	free(*RootNode);																		// ���� ��� �Ҵ� ����.
	*RootNode = NULL;																		// ���� ��带 ����Ű�� �����Ϳ� NULL�� ����. ��尡 ���ٴ� ��.
}

// Tree ���� ���.
// �Ű����� level������ Tree�� ���̸� ������.
// ���̸� �����ϴ� ������ ����� �� Tree�� ���� ��ŭ �鿩���⸦ �ϱ� ���ؼ� ������.
void PrintTree(Node *RootNode, int level) {
	if (RootNode != NULL) {									// Tree�� ��尡 1�� �̻��� ���� ���.
		if (RootNode->RightNode != NULL) PrintTree(RootNode->RightNode, level + 1);				// ������ ��尡 ����Ǿ��ִٸ� ������ ���� ��� Ž��.
		for (int i = 0; i < level; i++) printf("\t"); printf("> %d\n", RootNode->Data);			// ���� ����� ���̸�ŭ �鿩���� �� ��, ���� ����� ������ ���� ���.
		if (RootNode->LeftNode != NULL) PrintTree(RootNode->LeftNode, level + 1);				// ���� ��尡 ����Ǿ��ֵ��� ���� ���� ��� Ž��.
	} else puts(">> Error::Tree is empty.");				// Tree�� ��尡 1���� ���� ��� ���� ó��.
}

int main() {

	Node *RootNode = NULL;			// Tree�� RootNode�� ����Ű�� ������, Tree�� �����ּ�.
	int DataArray[] = { 27, 5, 37, 1, 61, 11, 7, 59, 15, 48, 19, 28 };		// ������ ������ ��.

	puts(" ::::::::: Input Data :::::::::");		// ������ ������ �� �迭�� ���� ��ŭ �ݺ��Ͽ� InputData�Լ��� Tree�� �� �ֱ�.
	for (int i = 0; i < sizeof(DataArray) / sizeof(DataArray[0]); i++)
		InputData(&RootNode, CreateNode(DataArray[i]));

	puts("\n ::::::::: Print Tree :::::::::");		// Tree���, �ι�° �Ű����� level�� 0�� �ִ� ������ RootNode�� ���̰� 0�̱� ����.
	PrintTree(RootNode, 0);

	puts("\n ::::::::: Search Data :::::::::");
	int uData = 15;									// ã�� ���� �����͸� 15�� ����.
	uData = SearchData(RootNode, uData);
	if (uData == -999) puts(">> Error::Failed to search.");
	else printf("> Successfully searched::The data retrieved is %d.\n", uData);

	puts("\n ::::::::: Delete Tree :::::::::");		// Tree �ϰ� ����.
	DeleteTree(&RootNode);
	if (RootNode == NULL) puts("> Successfully deleted!");
	else puts(">> Error::Failed to delete.");

	puts("\n ::::::::: Print Tree :::::::::");		// Ʈ�������� Ȯ���ϱ� ���� Tree�� ���.
	PrintTree(RootNode, 0);

	system("PAUSE");	// ��� ���� Ȯ���ϱ� ���� Console�� �Ͻ�������.
	return 0;
}