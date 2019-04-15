#include <stdio.h>
#include <stdlib.h>

typedef struct tagSpareMatrix {
	int row;
	int col;
	int val;
} SpaMATRIX;

int** CreateSparseMatrix(int *mMatrix, int mRow, int mCol) {
	int nValue = 0;
	SpaMATRIX *sMatrix;
	for (int i = 0; i < mRow * mCol; i++) if (*(mMatrix + i)) nValue++;

	sMatrix = (SpaMATRIX*)calloc(nValue + 1, sizeof(SpaMATRIX));	// nValue + 1의 +1은 희소행렬 인덱스 0번째의 정보 부분.
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

	return (int**)sMatrix;
}

// 더블포인터로 매개변수를 받을 경우 Matrix[r][c] 이런 식의 참조가 불가능하다.
// 그 이유는 Matrix[r][c]에서 r의 값이 1씩 증가할 때마다 한 줄의 col값 만큼 건너 뛰어야하는데
// 선언이 int **Matrix로만 되어있으므로 얼만큼 건너 뛰어야하는지 모르기 때문에 직접 설정해주어야함. 혹은 배열을 그냥 출력하면 됨.
void PrintMatrix(int *Matrix, int row, int col) {
	for (int i = 0; i < row * col;) {
		printf("%d ", *(Matrix + i++));
		if (i % col == 0) puts("");
	}
}

int main() {

	int MainMatrix[6][7] = { {0, 0, 1, 0, 2, 0, 0}, {0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 7}, {3, 0, 0, 0, 0, 0, 0}, {0, 5, 0, 0, 0, 6, 0}, {0, 0, 0, 0, 0, 0, 9} };
	int **sMatrix = CreateSparseMatrix(MainMatrix, 6, 7);
	
	PrintMatrix(MainMatrix, 6, 7);
	puts("");
	PrintMatrix(sMatrix, 9, 3);


	system("PAUSE");
	return 0;
}