#include <stdio.h>
#include <stdlib.h>

typedef struct tagQueue {
	int *QueueArray;
	int Capacity;
	int RearIndex;
} Queue;

void CreateQueue(Queue *queue, int MaxCapacity) {
	queue->QueueArray = (int*)calloc(MaxCapacity, sizeof(int));
	queue->Capacity = MaxCapacity;
	queue->RearIndex = 0;
}

void Enqueue(Queue *queue, int nData) {
	if (queue->Capacity > queue->RearIndex) queue->QueueArray[queue->RearIndex++] = nData;
	else puts("> Queue is full.");
}

void Dequeue(Queue *queue) {
	if (queue->RearIndex != 0) {
		printf("> Poped data: %d\n", *(queue->QueueArray));
		for (int t = 0; t < queue->RearIndex; t++) queue->QueueArray[t - 1] = queue->QueueArray[t];
		queue->RearIndex--;
	} else puts("> Queue is empty.");
}

void PrintQueue(Queue *queue) {
	if (queue->RearIndex != 0)
		for (int i = 0; i < queue->RearIndex; i++)
			printf("> %d\n", queue->QueueArray[i]);
	else puts("> There is no data");
}

int main() {

	Queue queue;
	CreateQueue(&queue, 5);

	for (int data = 1; data <= 6; data++) Enqueue(&queue, data);

	PrintQueue(&queue);

	Dequeue(&queue);
	Dequeue(&queue);

	PrintQueue(&queue);

	Dequeue(&queue);
	Dequeue(&queue);
	Dequeue(&queue);
	Dequeue(&queue);
	Dequeue(&queue);

	system("PAUSE");
	return 0;
}