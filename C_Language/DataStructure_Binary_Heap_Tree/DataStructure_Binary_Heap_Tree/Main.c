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

void PrintTree_tree(Tree *tree, int sIndex, int indent) {
	if (!indent) puts("> Data Tree::\n");
	if ((sIndex * 2) + 1 <= tree->Index && tree->TreeArr[(sIndex * 2) + 1] != NULLDATA) PrintTree_tree(tree, (sIndex * 2) + 1, indent + 1);
	for (int d = 0; d < indent; d++) printf("     "); printf("|%d|\n", tree->TreeArr[sIndex]);
	if (sIndex * 2 <= tree->Index && tree->TreeArr[sIndex * 2] != NULLDATA) PrintTree_tree(tree, sIndex * 2, indent + 1);
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

	puts(" ::: Print array :::");
	PrintTree_array(tree);

	puts("\n ::: After heap-sort :::");
	HeapSort(tree, 1);
	
	puts("\n ::: Print array :::");
	PrintTree_array(tree);

	puts("\n ::: Print tree :::");
	PrintTree_tree(tree, 1, 0);

	system("PAUSE");
	return 0;
}