#include <stdio.h>
#include <stdlib.h>
#define NULLDATA 987654

typedef struct tagTree {
	int *TreeArr;
	int Capacity;
	int Index;
} Tree;

Tree* CreateTree(int nCapacity) {
	Tree *NewTree = (Tree*)malloc(sizeof(Tree));
	
	NewTree->TreeArr = (int*)calloc(nCapacity + 1, sizeof(int));
	NewTree->Capacity = nCapacity;
	NewTree->Index = 0;
	for (int i = 0; i < nCapacity + 1; i++) NewTree->TreeArr[i] = NULLDATA;

	return NewTree;
}

void SwapData(int *left, int *right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}

void InsertData(Tree *tree, int *uData, int uDataSize) {
	if (tree->Capacity >= uDataSize) {
		for (int i = 1; i <= uDataSize; i++) tree->TreeArr[i] = uData[i - 1];
		tree->Index = uDataSize;
	} else puts(">> Error:: User data size is larger than tree size.");
}

void PrintTree_array(Tree *tree) {
	printf("> Data Array:: ");
	for (int i = 1; i <= tree->Index; i++) printf("|%d| ", tree->TreeArr[i]);
	puts("");
}

void PrintTree_tree(Tree *tree) {
	int indent = 0;
	for (int i = 2; i <= tree->Index; i += 2) {
		for (int d = 0; d < indent; d++) printf("\t"); printf("|%d|\n", tree->TreeArr[i / 2]);
		indent++;
		if (tree->TreeArr[i] != NULLDATA) {
			for (int d = 0; d < indent; d++) printf("|%d|\n", tree->TreeArr[i]);
		}
		if ((i + 1) <= tree->Index && tree->TreeArr[i + 1] != NULLDATA) {
			for (int d = 0; d < indent; d++) printf("|%d|\n", tree->TreeArr[i + 1]);
		}
	}
}

// if mode is 1, desc. if mode is 0, asce.
int CheckSort(Tree *tree, int mode) {
	for (int i = 2; i <= tree->Index; i++) {
		if (mode && tree->TreeArr[1] < tree->TreeArr[i]) return 1;
		if (!mode && tree->TreeArr[1] > tree->TreeArr[i]) return 1;
	}
	return 0;
}

// if mode is 1, desc. if mode is 0, asce.
void HeapSort(Tree *tree, int mode) {
	while (CheckSort(tree, mode)) {
		for (int i = 2; i <= tree->Index; i++) {
			if (tree->TreeArr[i] != NULLDATA) {
				if (mode && tree->TreeArr[i / 2] < tree->TreeArr[i])
					SwapData(&tree->TreeArr[i], &tree->TreeArr[i / 2]);
				if (!mode && tree->TreeArr[i / 2] > tree->TreeArr[i])
					SwapData(&tree->TreeArr[i], &tree->TreeArr[i / 2]);
			}
		}
	}
}

int main() {
	Tree *tree = CreateTree(10);
	int uDataArr[10] = { 1, 5, 3, 4, 6, 0, 7, 9, 8, 2 };

	InsertData(tree, uDataArr, sizeof(uDataArr) / sizeof(uDataArr[0]));

	PrintTree_array(tree);

	HeapSort(tree, 1);
	
	PrintTree_array(tree);
	//PrintTree_tree(tree);

	system("PAUSE");
	return 0;
}