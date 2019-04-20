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
		result = stack->RearNode->Data;		// 출력할 데이터 임시저장
		free(stack->RearNode);					// 최상위 노드 삭제.
		if (stack->FrontNode == stack->RearNode) {	// 스택에 노드가 한개라면.
			stack->FrontNode = NULL;
			stack->RearNode = NULL;
		} else {									// 스택에 노드가 한개 이상이라면.
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
	
	puts(":::: Push 연산 ::::");
	for (i = 1; i <= 3; i++) Push(&stack, CreateNode(i));		// 스택의  push연산.
	PrintStack(&stack);	// 스택 출력.

	puts("\n:::: Pop 연산 ::::");	//  개행.
	Pop(&stack);		// 스택의 pop연산.
	Pop(&stack);
	Pop(&stack);
	Pop(&stack);

	puts("\n:::: Stack 출력 ::::");	// 개행.
	PrintStack(&stack);	// 스택 출력.

	puts("");
	system("PAUSE");
	return 0;
}