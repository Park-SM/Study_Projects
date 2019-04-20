/*
	다항식 연산 구현.
*/
#include <stdio.h>
#include <stdlib.h>		// malloc(), free()
#include <math.h>		// pow()

// 리스트 구조체 정의 및 선언.
typedef struct tagNode {
	int Data1;
	int Data2;
	struct tagNode *NextNode;
} Node;

// 리스트 생성 및 초기화.
Node* CreateNode(int nData1, int nData2) {
	Node *NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data1 = nData1;
	NewNode->Data2 = nData2;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 연결.
void AppendNode(Node **HeadNode, Node *NewNode) {
	if (*HeadNode == NULL) {
		*HeadNode = NewNode;
	} else {
		Node *TailNode = *HeadNode;
		while (TailNode->NextNode != NULL) TailNode = TailNode->NextNode;
		TailNode->NextNode = NewNode;
	}
}

// 리스트 출력, 리스트가 비어있으면 "No Data.." 출력.
void PrintList(Node *List) {
	if (List != NULL) {
		while (List != NULL) {
			printf("(%dx^%d)", List->Data1, List->Data2, List->NextNode);
			if (List->NextNode != NULL) printf(" + ");
			List = List->NextNode;
		}
		puts("");
	} else puts("No data..");
}

// 리스트 일괄삭제, 재귀함수로 구현.
void DeleteList(Node *Current) {
	if (Current->NextNode != NULL) DeleteList(Current->NextNode);
	free(Current);
}


// 정렬에 사용 //
// 정렬상태 검사, 정렬 상태면 0을 리턴, 비정렬 상태면 1을 리턴.
int CheckSort(Node *List) {
	while (List->NextNode != NULL && List->Data2 > List->NextNode->Data2) List = List->NextNode;
	if (List->NextNode == NULL) return 0;
	else return 1;
}

// 정렬에 사용 //
// 매개변수 *SwapNode의 바로 앞 노드와 자리를 바꿈.
void SwapNode(Node **HeadNode, Node *SwapNode) {
	if (*HeadNode == SwapNode) {
		*HeadNode = SwapNode->NextNode;
		SwapNode->NextNode = (*HeadNode)->NextNode;
		(*HeadNode)->NextNode = SwapNode;
	}
	else {
		Node *TempNode = *HeadNode;
		while (TempNode->NextNode != SwapNode) TempNode = TempNode->NextNode;
		TempNode->NextNode = SwapNode->NextNode;
		SwapNode->NextNode = TempNode->NextNode->NextNode;
		TempNode->NextNode->NextNode = SwapNode;
	}
}

// 정렬에 사용 //
// 리스트를 정렬, 실제 main()에서 쓰이는 부분.
void BubbleSort(Node **List) {
	Node *Current;
	while (CheckSort(*List)) {
		Current = *List;
		while (Current->NextNode != NULL) {
			if (Current->Data2 < Current->NextNode->Data2) SwapNode(List, Current);
			else Current = Current->NextNode;
		}
	}
}

// List2를 List1에 병합, List2의 노드들은 List1에 병합되었으므로 List2의 시작부분은 NULL로 배정.
void MergeList(Node **List1, Node **List2) {	// main()의 지역변수인 List1, List2 포인터변수의 값을 변경하기 위해, 더블 포인터를 사용.
	Node *TempList1, *TempList2, *TempNode;		// List1, List2 리스트 순회를 위한 포인터 변수 *TempList1, *TempList2를 선언, 삭제할 노드의 주소값을 임시저장 및 List2의 다음 노드를 임시저장을 위해 *TempNode를 선언.

	BubbleSort(List1);	// List1을 정렬.
	BubbleSort(List2);	// List2을 정렬.
	TempList1 = *List1;
	TempList2 = *List2;
	while (TempList2 != NULL && (*List1)->Data2 < TempList2->Data2) {		// 첫 노드 처리 => List1의 첫번째 노드의 지수가 List2의 첫번째 노드의 지수보다 무조건 큰 상황으로 만듬.
		TempNode = TempList2->NextNode;
		TempList2->NextNode = *List1;
		*List1 = TempList2;
		TempList2 = TempNode;
	}

	while (TempList2 != NULL) {
		if (TempList1->Data2 == TempList2->Data2) {
			TempList1->Data1 += TempList2->Data1;
			TempNode = TempList2;
			TempList1 = TempList1->NextNode;
			TempList2 = TempList2->NextNode;
			free(TempNode);
		} else if (TempList1->Data2 > TempList2->Data2) {
			Node *cTempList1 = TempList1;					// List1의 노드가 List2의 노드보다 연속적으로 클 수 있기 때문에 변수를 선언해주고 다음 줄의 while문에서 순회.
			while (cTempList1->NextNode != NULL && cTempList1->NextNode->Data2 > TempList2->Data2) cTempList1 = cTempList1->NextNode;
			if (cTempList1->NextNode != NULL) {
				if (cTempList1->NextNode->Data2 == TempList2->Data2) {
					cTempList1->NextNode->Data1 += TempList2->Data1;
					TempNode = TempList2;								// 삭제할 노드의 주소를 임시 저장.
					TempList2 = TempList2->NextNode;					//     => List1의 지수와 List2의 지수가 같다면 List2의 노드의 계수부분을 List1의 노드에 더해주고 List2를 free해줌. => 메모리 누수 방지.
					free(TempNode);
				}
				else {
					TempNode = TempList2->NextNode;
					TempList2->NextNode = cTempList1->NextNode;
					cTempList1->NextNode = TempList2;
					TempList2 = TempNode;
				}
			} else {		// List1의 끝에다가 List2를 붙이기
				cTempList1->NextNode = TempList2;
				TempList2 = NULL;
			}
		}
	}
	*List2 = NULL;
}

// 다항식 계산
int Calculator(int x, Node *List) {
	if (List != NULL) {
		int Result = 0;
		while (List != NULL) {
			Result += List->Data1 * (int)pow((double)x, (double)(List->Data2));
			List = List->NextNode;
		}
		return Result;
	}
	return 0;
}

int main() {

	// 리스트의 시작주소를 저장하는 포인터변수 선언.
	Node *List1 = NULL;
	Node *List2 = NULL;

	// List1에 노드 추가.
	AppendNode(&List1, CreateNode(1, 1));
	AppendNode(&List1, CreateNode(2, 7));
	AppendNode(&List1, CreateNode(3, 9));
	AppendNode(&List1, CreateNode(3, 3));
	AppendNode(&List1, CreateNode(3, 11));

	// List2에 노드 추가.
	AppendNode(&List2, CreateNode(10, 2));
	AppendNode(&List2, CreateNode(20, 5));
	AppendNode(&List2, CreateNode(20, 7));
	AppendNode(&List2, CreateNode(20, 8));
	AppendNode(&List2, CreateNode(20, 12));
	AppendNode(&List2, CreateNode(20, 1));
	AppendNode(&List2, CreateNode(20, 0));

	// List1과 List2를 출력.
	printf("List1 >> "); PrintList(List1);
	printf("List2 >> "); PrintList(List2);

	// List1과 List2를 병합.
	puts("\n   ::: Merging :::\n");
	MergeList(&List1, &List2);

	// List1과 List2를 출력.
	printf("List1 >> "); PrintList(List1);
	printf("List2 >> "); PrintList(List2);

	// List1의 다항식에 x값을 넣어 계산한 결과값 출력.
	printf("\nf(1) >> %d\n", Calculator(1, List1));
	printf("f(2) >> %d\n", Calculator(2, List1));
	printf("f(3) >> %d\n", Calculator(3, List1));

	// List1을 일괄삭제.
	DeleteList(List1);
	List1 = NULL;

	puts("");
	system("PAUSE");
	return 0;
} 