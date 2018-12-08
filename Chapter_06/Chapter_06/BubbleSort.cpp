#include <stdio.h>

#define MAX_SIZE 6

void BubbleSort(int arr[], int size);

int main()
{
	int arr[MAX_SIZE] = { 3, 1, 6, 5, 2, 4 };

	printf("정렬 전 : ");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}

	BubbleSort(arr, MAX_SIZE);

	printf("\n정렬 후 : ");
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

void BubbleSort(int arr[], int size)
{
	int temp;

	for (int i = 1; i <= size - 1; i++) {
		for (int j = 1; j <= size - i; j++) {
			if (arr[j - 1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}