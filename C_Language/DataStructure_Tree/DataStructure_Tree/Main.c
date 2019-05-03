#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	char *Data;
	struct tagNode *RightSimbing;
	struct tagNode *LeftChild;
} Node;

Node* CreateNode(char *nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(nData) + 1);
	
	strncpy(NewNode->Data, nData, strlen(nData) + 1);
	NewNode->RightSimbing = NULL;
	NewNode->LeftChild = NULL;

	return NewNode;
}

void AppendChildNode(Node *HeadNode, Node *NewNode) {
	if (HeadNode->LeftChild == NULL) {
		HeadNode->LeftChild = NewNode;
	} else {
		Node *TailNode = HeadNode->LeftChild;
		while (TailNode->RightSimbing != NULL) TailNode = TailNode->RightSimbing;
		TailNode->RightSimbing = NewNode;
	}
}

void PrintTree(Node *Current, int Level) {
	for (int i = 0; i < Level; i++) printf("\t");
	printf("> %s\n", Current->Data);

	if (Current->LeftChild != NULL) PrintTree(Current->LeftChild, Level + 1);
	if (Current->RightSimbing != NULL) PrintTree(Current->RightSimbing, Level);
	
}

int main() {

	Node *RootNode = CreateNode("Park");
	Node *Data1 = CreateNode("Sang");
	Node *Data2 = CreateNode("Min");
	Node *Data3 = CreateNode("PSM");
	Node *Data4 = CreateNode("ParkLand");
	Node *Data5 = CreateNode("ParkWorld");
	Node *Data6 = CreateNode("Park97_SM");
	Node *Data7 = CreateNode("Park97.SM");
	Node *Data8 = CreateNode("Park.SM");

	AppendChildNode(RootNode, Data1);
	AppendChildNode(RootNode, Data2);
	AppendChildNode(RootNode, Data3);
	AppendChildNode(Data1, Data4);
	AppendChildNode(Data1, Data5);
	AppendChildNode(Data2, Data6);
	AppendChildNode(Data6, Data7);
	AppendChildNode(Data3, Data8);

	PrintTree(RootNode, 0);

	system("PAUSE");
	return 0;
}