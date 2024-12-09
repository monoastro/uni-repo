#include <stdio.h>
#include <malloc.h>

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
	{
        for (int j = 0; j < size - 1 - i; j++)
		{
            if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
	{
        for (int j = i + 1; j < size; j++)
		{
            if (arr[j] < arr[i])
			{
				swap(&arr[j], &arr[i]);
			}
		}
    }
}

int main()
{
	int choice, size, *arr;
	while(1)
	{
		printf("\nEnter option:\n[0] bubble sort\n[1] selection sort\n");
		scanf("%d", &choice);

		printf("Enter size of array\n");
		scanf("%d", &size);
		arr = (int*)malloc(sizeof(int)*size);
		printf("Enter array in unsorted form\n");
		for(int i = 0; i<size; i++) scanf("%d", &arr[i]);

		switch(choice)
		{
			case 0:
				bubbleSort(arr, size);
				printf("Sorted array using Bubble Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
			case 1:
				selectionSort(arr, size);
				printf("Sorted array using Selection Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
		}
		free(arr);
	}
}
