#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *DataArr, int Length) {
	printf("> Data Array :: ");
	for (int i = 0; i < Length; i++) printf("|%d| ", DataArr[i]);
	puts("");
}

void SwapData(int *LeftData, int *RightData) {
	int temp = *LeftData;
	*LeftData = *RightData;
	*RightData = temp;
}

int Partition(int *DataArr, int LeftIndex, int RightIndex) {
	int PivotIndex = LeftIndex;
	int PivotData = DataArr[LeftIndex++];

	while (LeftIndex < RightIndex) {
		while (PivotData >= DataArr[LeftIndex] && LeftIndex < RightIndex) LeftIndex++;
		while (PivotData < DataArr[RightIndex] && LeftIndex <= RightIndex) RightIndex--;

		if (LeftIndex < RightIndex) SwapData(&DataArr[LeftIndex], &DataArr[RightIndex]);
		else break;
	}
	SwapData(&DataArr[PivotIndex], &DataArr[RightIndex]);

	return RightIndex;
}

void QuickSort(int *DataArr, int LeftIndex, int RightIndex) {
	if (LeftIndex < RightIndex) {
		int tRightIndex = Partition(DataArr, LeftIndex, RightIndex);

		QuickSort(DataArr, LeftIndex, tRightIndex - 1);
		QuickSort(DataArr, tRightIndex + 1, RightIndex);
	}
}

int main() {

	int uDataArray[] = { 4, 5, 3, 1, 0, 6, 2, 9, 7, 8 };

	PrintArray(uDataArray, sizeof(uDataArray) / sizeof(uDataArray[0]));

	QuickSort(uDataArray, 0, sizeof(uDataArray) / sizeof(uDataArray[0]) - 1);

	PrintArray(uDataArray, sizeof(uDataArray) / sizeof(uDataArray[0]));


	system("PAUSE");
	return 0;
}