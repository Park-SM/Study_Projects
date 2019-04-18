#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode *NextNode;
} Node;

typedef struct tagQueue {
	Node *FrontNode;
	Node *RearNode;
} Queue;

Node* CreateNode() {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void AppendNode(Queue *queue, Node *NewNode) {
	if (queue->FrontNode == NULL) {
		queue->FrontNode = NewNode;
		queue->RearNode = NewNode;
	} else {
		queue->RearNode->NextNode = NewNode;
		queue->RearNode = NewNode;
	}
}

void PrintList(Node *List) {
	if (List != NULL) {
		while (List != NULL) {
			printf("> %d\n", List->Data);
			List = List->NextNode;
		}
	} else puts("");
}

void CreateQueue(Queue *queue, int capacity) {
	if (capacity) {
		for (int i = 0; i < capacity; i++) AppendNode(queue, CreateNode());
		queue->RearNode->NextNode = queue->FrontNode;
		queue->RearNode = queue->FrontNode;
	} else puts("Error: Failed to create queue..");
}

int main() {

	system("");
	return 0;
}