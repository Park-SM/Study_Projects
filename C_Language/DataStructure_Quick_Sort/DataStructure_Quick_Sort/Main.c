#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *arr, int arr_size) {
	printf("> Data Array:: ");
	for (int i = 0; i < arr_size; i++) printf("|%d| ", arr[i]);
	puts("");
}

void SwapData(int *LeftData, int *RightData) {
	int temp = *LeftData;
	*LeftData = *RightData;
	*RightData = temp;
}

int Partition(int *arr, int LeftIndex, int RightIndex) {
	int PivotData = arr[LeftIndex];
	int PivotIndex = LeftIndex++;

	while (LeftIndex <= RightIndex) {
		while (PivotData >= arr[RightIndex] && RightIndex >= LeftIndex) RightIndex--;
		while (PivotData < arr[LeftIndex] && LeftIndex < RightIndex) LeftIndex++;

		if (LeftIndex < RightIndex) SwapData(&arr[LeftIndex], &arr[RightIndex]);
		else break;
	}
	SwapData(&arr[PivotIndex], &arr[RightIndex]);

	return RightIndex;
}

void QuickSort(int *arr, int LeftIndex, int RightIndex) {
	if (LeftIndex < RightIndex) {
		int CurrentPivotIndex = Partition(arr, LeftIndex, RightIndex);

		QuickSort(arr, LeftIndex, CurrentPivotIndex - 1);
		QuickSort(arr, CurrentPivotIndex + 1, RightIndex);
	}
}

int main() {

	int DataArray[] = { 5, 2, 1, 6, 4, 0, 3, 9, 7, 8 };

	PrintArray(DataArray, sizeof(DataArray) / sizeof(DataArray[0]));

	QuickSort(DataArray, 0, sizeof(DataArray) / sizeof(DataArray[0]) - 1);

	PrintArray(DataArray, sizeof(DataArray) / sizeof(DataArray[0]));
	
	system("PAUSE");
	return 0;
}