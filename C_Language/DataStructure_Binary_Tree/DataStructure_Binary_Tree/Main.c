#include <stdio.h>
#include <stdlib.h>		// malloc(), free(), system()

// 노드의 구조체 정의 및 선언.
typedef struct tagNode {
	int Data;
	struct tagNode *LeftNode;
	struct tagNode *RightNode;
}Node;

// 새로운 노드 생성하는 함수, 새로 만든 노드의 Data부분에 넣을 값을 매개변수로 받음.
Node* CreateNode(int nData) {
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = nData;
	NewNode->LeftNode = NULL;
	NewNode->RightNode = NULL;

	return NewNode;
}

// InputData함수 안에서 사용되는 재귀함수, Tree의 RootNode를 첫번째 매개변수로 주고 계속 하위 노드로 재귀되며 탐색.
// CreateNode함수로 새로운 노드를 만들고 그 노드의 시작주소를 리턴하는데 그 시작주소를 NewNode로 줌.
void InputData_in(Node *Current, Node *NewNode) {
	if (Current->Data != NewNode->Data) {				// 현재 탐색하고있는 노드와 새로 만들어진 노드의 데이터 값이 다르다면.
		if (Current->Data > NewNode->Data) {			// 현재 탐색하고있는 노드의 데이터 값이 새로 만들어진 노드의 데이터 값보다 크다면.
			if (Current->LeftNode != NULL) InputData_in(Current->LeftNode, NewNode);	// 왼쪽노드가 존재한다면 왼쪽 노드로 재귀함수 실행.
			else Current->LeftNode = NewNode;			// 왼쪽 노드가 존재하지 않다면 왼쪽 노드에 새로운 노드의 시작 주소를 대입하므로써 왼쪽노드에 연결.
		} else {										// 현재 탐색하고있는 노드의 데이터 값이 새로 만들어진 노드의 데이터 값보다 작다면.
			if (Current->RightNode != NULL) InputData_in(Current->RightNode, NewNode);	// 오른쪽노드가 존재한다면 오른쪽 노드로 재귀함수 실행.
			else Current->RightNode = NewNode;			// 오른쪽 노드가 존재하지 않다면 오른쪽 노드에 새로운 노드의 시작주소를 대입하므로써 오른쪽노드에 연결.
		}
	} else {											// 현재 탐색하고 있는 노드와 새로 만들어진 노드의 데이터 값이 같다면 에러처리.
		puts(">> Error: Data Duplication.");
		free(NewNode);									// CreateNode함수를 통해 이미 Heap영역 메모리 상에 Node가 상주하고 있으므로 필요없는 NewNode는 해제해야함.
	}
}

// 실질적으로 Main함수에서 값 적재를 위해 사용되는 함수.
// RootNode를 더블포인터로 선언한 이유는 InputData함수를 호출하는 Main함수에서 안에 선언되어있는 싱글포인터(*)의 물리적위치주소(&)를 전달받아 다시 역참조하여
// Main함수 안에 선언되어있는 싱글포인터(*)의 값을 바꿔야하기 때문, NewNode는 CreateNode함수를 통해 리턴받은 새로운 노드의 시작주소.
void InputData(Node **RootNode, Node *NewNode) {
	if (*RootNode == NULL) *RootNode = NewNode;		// Main함수에서 Tree의 시작하는 주소를 저장하고 있는 포인터가 NULL이라면 즉 Tree에 노드가 한개도 없다면 새로운 노드를 연결.
	else InputData_in(*RootNode, NewNode);			// Main함수에서 Tree의 시작하는 주소를 저장하고 있는 포인터가 NULL이 아니라면 노드가 1개 이상은 연결되어있다는 뜻이므로,	 재귀함수를 통해 연결 실행.
}

// RootNode의 주소를 넣고, sData에 탐색하고 싶은 데이터 값을 입력.
int SearchData(Node *RootNode, int sData) {
	int SearchedData = -1;							// return SearchedData;전까지 SearchedData변수가 수정되지 않고 -1을 리턴하면 찾지 못한 상태.

	if (RootNode != NULL) {							// Tree안에 노드가 1개 이상은 있을 경우.
		if (RootNode->Data != sData) {				// 현재 탐색하고있는 노드와 탐색하고 싶은 데이터 값과 같지 않다면.
			if (RootNode->Data > sData) {					// 현재 탐색하고있는 노드의 데이터 값이 탐색하고 싶은 데이터 값보다 크다면.
				if (RootNode->LeftNode != NULL) SearchedData = SearchData(RootNode->LeftNode, sData);		// 왼쪽노드가 존재한다면 왼쪽 노드로 재귀 탐색.
			} else {										// 현재 탐색하고있는 노드의 데이터 값이 탐색하고 싶은 데이터 값보다 작다면.
				if (RootNode->RightNode != NULL) SearchedData = SearchData(RootNode->RightNode, sData);		// 오른쪽노드가 존재한다면 오른쪽노드로 재귀 탐색.
			}
		} else {									// 현재 탐색하고 있는 노드와 탐색하고 싶은 데이터 값과 같다면.
			SearchedData = RootNode->Data;			// 현재 탐색하고 있는 노드의 데이터를 반환할 변수에 대입.
			printf(">> Successfully searched:: The data retrieved is %d.\n", SearchedData);		// 데이터 검색 결과를 출력.
		}
	} else puts("\n>> Error: Tree is empty.");		// Tree안에 노드가 1개도 없을 경우 에러처리.

	return SearchedData;							// 검색 결과 리턴.
}

// Tree 중위 출력.
// 매개변수 level변수는 Tree의 깊이를 전달함. 깊이를 전달하는 이유는 출력할 때 Tree의 깊이 만큼 들여쓰기를 하기 위해서 전달함.
void PrintTree(Node *RootNode, int level) {
	if (RootNode != NULL) {										// Tree에 노드가 1개 이상은 있을 경우.
		if (RootNode->RightNode != NULL) PrintTree(RootNode->RightNode, level + 1);				// 오른쪽 노드가 연결되어있다면 오른쪽 노드로 재귀 탐색.
		for (int i = 0; i < level; i++) printf("\t"); printf("> %d\n", RootNode->Data);			// 현재 노드의 깊이만큼 들여쓰기 한 후, 현재 노드의 데이터 값을 출력.
		if (RootNode->LeftNode != NULL) PrintTree(RootNode->LeftNode, level + 1);				// 왼쪽 노드가 연결되어있따면 왼쪽 노드로 재귀 탐색.
	} else puts(">> Error: Tree is empty.");					// Tree에 노드가 1개도 없을 경우 에러 처리.
}

// Tree를 일괄삭제.
// 매개변수 RootNode를 더블포인터(**)로 선언한 이유는 main함수 안에 *RootNode의 데이터 값을 변경하기 위해 선언.
void DeleteTree(Node **RootNode) {
	if ((*RootNode)->RightNode != NULL) DeleteTree(&((*RootNode)->RightNode));				// 오른쪽 노드가 연결되어있다면 오른쪽 노드로 재귀 탐색.
	if ((*RootNode)->LeftNode != NULL) DeleteTree(&((*RootNode)->LeftNode));				// 왼쪽 노드가 연결되어있따면 왼쪽 노드로 재귀 탐색.
	free(*RootNode);																		// 현재 노드 할당 해제.
	*RootNode = NULL;																		// 현재 노드를 가르키는 포인터에 NULL을 대입. 노드가 없다는 뜻.
}

int main() {

	Node *RootNode = NULL;			// Tree의 RootNode를 가르키는 포인터, Tree의 시작주소.
	int DataArray[] = { 24, 5, 37, 1, 61, 11, 7, 59, 15, 48, 19, 28 };			// 임의의 데이터 값.

	puts(" :::: Input data :::::");
	for (int i = 0; i < sizeof(DataArray) / sizeof(DataArray[0]); i++)			// 임의의 데이터 값 배열의 길이 만큼 반복하여 InputData함수로 Tree에 값 넣기.
		InputData(&RootNode, CreateNode(DataArray[i]));

	puts("\n :::: Print Tree :::::");
	PrintTree(RootNode, 0);							// Tree출력, 두번째 매개변수 level에 0을 넣는 이유는 RootNode의 깊이가 0이기 때문.

	puts("\n :::: Search data :::::");
	int uSearchData = 7;							// 찾고 싶은 데이터를 7로 저장.
	if (SearchData(RootNode, uSearchData) == -1) puts(">> Error: There is no data");		// 찾으려는 데이터 값이 Tree안에 없다면 에러처리.

	puts("\n :::: Delete Tree :::::");
	DeleteTree(&RootNode);										// Tree 일괄 삭제.
	if (RootNode == NULL) puts(">> Successfully deleted");		// Tree 일괄 삭제가 성공했다면.

	puts("\n :::: Print Tree :::::");
	PrintTree(RootNode, 0);							// 일괄삭제처리를 확인하기 위해 Tree를 출력.

	system("PAUSE");			// 결과 값을 확인하기 위해 Console을 일시정지함.
	return 0;
}