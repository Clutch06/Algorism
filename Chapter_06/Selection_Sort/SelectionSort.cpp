#include <stdio.h>

#define MAX_SIZE 6

void SelectionSort(int arr[], int size);

int main()
{
	int arr[MAX_SIZE] = { 3, 1, 6, 5, 2, 4 };

	printf("정렬 전 : ");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}

	SelectionSort(arr, MAX_SIZE);

	printf("\n정렬 후 : ");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void SelectionSort(int arr[], int size)
{
	int temp, min;

	for (int i = 0; i <= size - 2; i++) {
		min = i;

		for (int j = i + 1; j <= size - 1; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}	
		}

		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}