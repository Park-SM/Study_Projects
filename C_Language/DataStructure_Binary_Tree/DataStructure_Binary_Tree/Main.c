#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode *LeftNode;
	struct tagNode *RightNode;
}Node;

Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->LeftNode = NULL;
	NewNode->RightNode = NULL;

	return NewNode;
}

void InputData_in(Node *Current, Node *NewNode) {
	if (Current->Data != NewNode->Data) {
		if (Current->Data > NewNode->Data) {
			if (Current->LeftNode != NULL) InputData_in(Current->LeftNode, NewNode);
			else Current->LeftNode = NewNode;
		}
		else {
			if (Current->RightNode != NULL) InputData_in(Current->RightNode, NewNode);
			else Current->RightNode = NewNode;
		}
	}
	else puts("\n>> Error: Data Duplication.");
}

int SearchData(Node *RootNode, int level, int sData) {
	int SearchedData = -1;

	if (RootNode != NULL) {
		if (RootNode->Data != sData) {
			if (RootNode->Data > sData) {
				if (RootNode->LeftNode != NULL) SearchedData = SearchData(RootNode->LeftNode, level + 1, sData);
			}
			else {
				if (RootNode->RightNode != NULL) SearchedData = SearchData(RootNode->RightNode, level + 1, sData);
			}
		}
		else {
			SearchedData = RootNode->Data;
			printf("\n>> Success searching: Searced data is %d.\n", SearchedData);
		}
	}
	else puts("\n>> Error: Tree is empty.");

	return SearchedData;
}

void InputData(Node **RootNode, Node *NewNode) {
	if (*RootNode == NULL) *RootNode = NewNode;
	else InputData_in(*RootNode, NewNode);
}

void PrintTree(Node *RootNode, int level) {
	if (RootNode->RightNode != NULL) PrintTree(RootNode->RightNode, level + 1);
	for (int i = 0; i < level; i++) printf("\t"); printf("> %d\n", RootNode->Data);
	if (RootNode->LeftNode != NULL) PrintTree(RootNode->LeftNode, level + 1);
}

int main() {

	Node *RootNode = NULL;
	int DataArray[] = { 24, 5, 37, 1, 61, 11, 7, 59, 15, 48, 19, 28 };

	for (int i = 0; i < sizeof(DataArray) / sizeof(int); i++)
		InputData(&RootNode, CreateNode(DataArray[i]));

	PrintTree(RootNode, 0);

	int uSearchData = 29;
	if (SearchData(RootNode, 0, uSearchData) == -1) puts("\n>> Error: There is no data");

	system("PAUSE");
	return 0;
}