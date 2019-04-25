#include <stdio.h>
#include <stdlib.h>

typedef struct tagStack {
	int *StackArray;
	int Capacity;
	int Index;
} Stack;

void CreateStack(Stack *stack, int Capacity) {
	stack->StackArray = (int*)calloc(Capacity, sizeof(int));
	stack->Capacity = Capacity;
	stack->Index = 0;
}

void Push(Stack *stack, int nData) {
	if (stack->Index < stack->Capacity)
		stack->StackArray[stack->Index++] = nData;
	else puts("> Stack is full");
}

void Pop(Stack *stack) {
	if (stack->Index != 0) {
		printf("> Poped data: %d\n", stack->StackArray[--stack->Index]);
		stack->StackArray[stack->Index] = 0;
	} else puts("> There is no data");
}

void PrintStack(Stack *stack) {
	if (stack->Index != 0) {
		for (int tIndex = 0; tIndex < stack->Index; tIndex++)
			printf("> %d\n", stack->StackArray[tIndex]);
	} else puts("> Stack is empty");
}

int main() {

	Stack stack;
	CreateStack(&stack, 5);

	for (int i = 1; i <= 6; i++) Push(&stack, i);

	puts("\n:::: 스택 Push 후 출력 ::::");
	PrintStack(&stack);

	puts("\n:::: 스택 Pop 후 출력 ::::");
	Pop(&stack);
	Pop(&stack);
	PrintStack(&stack);

	puts("\n:::: 스택을 오버해서 Pop 후 출력 ::::");
	Pop(&stack);
	Pop(&stack);
	Pop(&stack);
	Pop(&stack);
	Pop(&stack);
	PrintStack(&stack);

	system("PAUSE");
	return 0;
}