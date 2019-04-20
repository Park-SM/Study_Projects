#include <stdio.h>
#include <stdlib.h>

typedef struct tagSpareMatrix {
	int row;
	int col;
	int val;
} SpaMATRIX;

int* CreateSparseMatrix(int *mMatrix, int mRow, int mCol) {
	int nValue = 0;
	SpaMATRIX *sMatrix;
	for (int i = 0; i < mRow * mCol; i++) if (*(mMatrix + i)) nValue++;

	sMatrix = (SpaMATRIX*)calloc(nValue + 1, sizeof(SpaMATRIX));	// nValue + 1�� +1�� ������ �ε��� 0��°�� ���� �κ�.
	sMatrix[0].row = mRow;
	sMatrix[0].col = mCol;
	sMatrix[0].val = nValue;

	nValue = 1;
	for (int i = 0; i < mRow * mCol; i++)
		if (*(mMatrix + i)) {
			sMatrix[nValue].row = i / mCol;
			sMatrix[nValue].col = i % mCol;
			sMatrix[nValue++].val = *(mMatrix + i);
		}

	return (int*)sMatrix;
}

int* CreateTransposedMatrix(int *mMatrix, int mRow, int mCol) {
	int *tMatrix = (int*)calloc(mRow * mCol, sizeof(int));
	
	for (int t = 0; t < mCol; t++) {
		for (int i = 0; i < mRow; i++) {
			*(tMatrix + i + (t * mRow)) = *(mMatrix + (i * mCol) + t);
		}
	}

	return tMatrix;
}

// ���������ͷ� �Ű������� ���� ��� Matrix[r][c] �̷� ���� ������ �Ұ����ϴ�.
// �� ������ Matrix[r][c]���� r�� ���� 1�� ������ ������ �� ���� col�� ��ŭ �ǳ� �پ���ϴµ�
// ������ int **Matrix�θ� �Ǿ������Ƿ� r�� ���� 1�� ������ ������ ��ŭ �ǳ� �پ���ϴ��� �𸣱� ������ ���� �������־����.
// Ȥ�� �迭�� �׳� ����ϰų� �Ű������� �迭�� �����ؼ� �����ؾ���.
void PrintMatrix(int *Matrix, int row, int col) {
	for (int i = 0; i < row * col;) {
		printf("%d ", *(Matrix + i++));
		if (i % col == 0) puts("");
	}
}

int main() {

	int MainMatrix[6][7] = { {0, 0, 1, 0, 2, 0, 0}, {0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 7}, {3, 0, 0, 0, 0, 0, 0}, {0, 5, 0, 0, 0, 6, 0}, {0, 0, 0, 0, 0, 0, 9} };
	int *SparseMtxOfMainMtx = CreateSparseMatrix(MainMatrix, 6, 7);								// ���� ����� ������.
	int *TransposeMtxOfMainMtx = CreateTransposedMatrix(MainMatrix, 6, 7);							// ���� ����� ��ġ���.
	int *TransposeMtxOfSparseMtxOfMainMtx = CreateTransposedMatrix(SparseMtxOfMainMtx, 9, 3);		// ���� ����� �������� ��ġ���.
	
	puts(">>>> ���� ��� ���.");
	PrintMatrix(MainMatrix, 6, 7);
	puts("\n>>>> ���� ����� ��ġ���.");
	PrintMatrix(TransposeMtxOfMainMtx, 7, 6);
	puts("\n>>>> ���� ����� ������.");
	PrintMatrix(SparseMtxOfMainMtx, 9, 3);
	puts("\n>>>> ���� ����� �������� ��ġ���.");
	PrintMatrix(TransposeMtxOfSparseMtxOfMainMtx, 3, 9);

	puts("\n");
	system("PAUSE");
	return 0;
}