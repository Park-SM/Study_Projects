#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode *NextNode;
} Node;

typedef struct tagStack {
	Node *FrontNode;
	Node *RearNode;
	int capacity;
} Stack;

Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->NextNode = NULL;
	return NewNode;
}

void Push(Stack *stack, Node *NewNode) {
	if (stack->FrontNode == NULL) {
		stack->FrontNode = NewNode;
		stack->RearNode = NewNode;
	}
	else {
		stack->RearNode->NextNode = NewNode;
		stack->RearNode = NewNode;
	}
	stack->capacity++;
}

int Pop(Stack *stack) {
	int result = 0;
	if (stack->FrontNode != NULL) {
		result = stack->RearNode->Data;		// ����� ������ �ӽ�����
		free(stack->RearNode);					// �ֻ��� ��� ����.
		if (stack->FrontNode == stack->RearNode) {	// ���ÿ� ��尡 �Ѱ����.
			stack->FrontNode = NULL;
			stack->RearNode = NULL;
		} else {									// ���ÿ� ��尡 �Ѱ� �̻��̶��.
			Node *TempNode = stack->FrontNode;
			while (TempNode->NextNode != stack->RearNode) TempNode = TempNode->NextNode;
			stack->RearNode = TempNode;
			stack->RearNode->NextNode = NULL;
		}
		stack->capacity--;
		printf(">> Poped data: %d\n", result);
	} else puts(">> Empty stack..");
	return result;
}

void PrintStack(Stack *stack) {
	if (stack->FrontNode != NULL) {
		Node *Current = stack->FrontNode;
		while (Current != NULL) {
			printf("> %d\n", Current->Data);
			Current = Current->NextNode;
		}
	}
	else puts("> No data..");
}

int main() {
	int i;
	Stack *stack = NULL;
	
	puts(":::: Push ���� ::::");
	for (i = 1; i <= 3; i++) Push(&stack, CreateNode(i));		// ������  push����.
	PrintStack(&stack);	// ���� ���.

	puts("\n:::: Pop ���� ::::");	//  ����.
	Pop(&stack);		// ������ pop����.
	Pop(&stack);
	Pop(&stack);
	Pop(&stack);

	puts("\n:::: Stack ��� ::::");	// ����.
	PrintStack(&stack);	// ���� ���.

	puts("");
	system("PAUSE");
	return 0;
}