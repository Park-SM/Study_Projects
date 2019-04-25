#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode *NextNode;
} Node;

typedef struct tagQueue {
	Node *FrontNode;
	Node *RearNode;
	int cpapcity;
} Queue;

Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->NextNode = NULL;
	return NewNode;
}

void AppendNode(Queue *queue, Node *NewNode) {
	if (queue->FrontNode == NULL) {
		queue->FrontNode = NewNode;
		queue->RearNode = NewNode;
	}
	else {
		queue->RearNode->NextNode = NewNode;
		queue->RearNode = NewNode;
	}
	queue->cpapcity++;
}

void PrintQueue(Queue *queue) {
	if (queue->FrontNode != NULL) {
		Node *Current = queue->FrontNode;
		while (Current != NULL) {
			printf("> %d\n", Current->Data);
			Current = Current->NextNode;
		}
	}
	else puts("> No data..");
}

int Pop(Queue *queue) {
	int PopedData = 0;
	if (queue->FrontNode != NULL) {
		PopedData = queue->FrontNode->Data;
		Node *DeleteNode = queue->FrontNode;
		if (queue->FrontNode == queue->RearNode) {
			queue->FrontNode = NULL;
			queue->RearNode = NULL;
		}
		else queue->FrontNode = queue->FrontNode->NextNode;

		queue->cpapcity--;
		printf("> Poped data: %d\n", PopedData);
		free(DeleteNode);
	}
	else puts("> Empty queue..");

	return PopedData;
}

int main() {

	int i;
	Queue queue = { NULL, NULL, 0 };

	puts(":::: Push 연산 ::::");
	for (i = 1; i <= 3; i++) AppendNode(&queue, CreateNode(i));
	PrintQueue(&queue);

	puts("\n:::: Pop 연산 ::::");
	Pop(&queue);
	Pop(&queue);
	Pop(&queue);
	Pop(&queue);

	puts("\n:::: Queue 출력 ::::");
	PrintQueue(&queue);

	system("PAUSE");
	return 0;
}