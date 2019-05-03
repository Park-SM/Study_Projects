#include <stdio.h>
#include <stdlib.h>

typedef struct tagQueue {
	int FrontIndex;
	int RearIndex;
	int Capacity;
	int DataCount;
	int *Array;
} Queue;

void CreateQueue(Queue *queue, int uCapacity) {
	queue->Array = (int*)calloc(uCapacity, sizeof(int));
	queue->Capacity = uCapacity;
	queue->DataCount = 0;
	queue->FrontIndex = 0;
	queue->RearIndex = 0;
}

void EnQueue(Queue *queue, int nData, int type) {
	if (queue->DataCount < queue->Capacity) {
		queue->Array[queue->RearIndex++ % queue->Capacity] = nData;
		queue->DataCount++;
		if (type) printf("> EnQueue data: %d\n", nData);
	} else puts(">> Error(100): Queue is full.");
}

int DeQueue(Queue *queue, int type) {
	int retData = -1;
	if (queue->DataCount != 0) {
		retData = queue->Array[queue->FrontIndex % queue->Capacity];
		queue->Array[queue->FrontIndex++ % queue->Capacity] = 0;
		queue->DataCount--;
	} else puts(">> Error(101): Queue is empty.");
	if (type && retData != -1) printf("> DeQueue data: %d\n", retData);

	return retData;
}

void PrintQueue(Queue *queue) {
	if (queue->DataCount != 0) {
		int TempIndex = queue->FrontIndex;
		for (int i = 1; i <= queue->DataCount; i++)
			printf("> %d: %d\n", i, queue->Array[TempIndex++ % queue->Capacity]);
	} else puts(">> Error(102): Queue is empty.");
}

int main() {

	Queue queue;
	CreateQueue(&queue, 7);
	
	for(int i = 11; i < 20; i++) EnQueue(&queue, i, 1);

	PrintQueue(&queue);

	DeQueue(&queue, 1);
	DeQueue(&queue, 1);
	DeQueue(&queue, 1);
	EnQueue(&queue, 99, 1);

	PrintQueue(&queue);

	for (int i = 11; i < 20; i++) DeQueue(&queue, 1);

	for (int i = 11; i < 20; i++) EnQueue(&queue, i, 1);
	PrintQueue(&queue);
	DeQueue(&queue, 1);
	DeQueue(&queue, 1);
	system("PAUSE");
	return 0;
}