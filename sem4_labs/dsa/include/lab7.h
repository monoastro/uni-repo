#include "sorting.h"

void lab7()
{
	int choice, size, *arr, search_data, result;
	while(1)
	{
		printf("\nEnter option:\n (0) merge sort\n (1) binary search\n (2) bubble sort \n (3) selection sort\n ");
		scanf("%d", &choice);

		printf("Enter size of array to sort/search\n");
		scanf("%d", &size);
		arr = (int*)malloc(sizeof(int)*size);
		printf("Enter array in unsorted form\n");
		for(int i = 0; i<size; i++) scanf("%d", &arr[i]);

		switch(choice)
		{
			//cases 0 and 1 both use merge sort so I merged them ;)
			case 0:
			case 1:
				mergeSort(arr, 0, size - 1);
				printf("Sorted array using Merge Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				if(choice == 0) break;

				printf("Enter data to search: ");
				scanf("%d", &search_data);
				result = binarySearch(arr, 0, size - 1, search_data);
				if (result != -1) printf("Element %d is present at index %d\n", search_data, result);
				else printf("Element %d is not present in the array\n", search_data);
				break;
			case 2:
				bubbleSort(arr, size);
				printf("Sorted array using Bubble Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
			case 3:
				selectionSort(arr, size);
				printf("Sorted array using Selection Sort:\n");
				for (int i = 0; i < size; i++) printf("%d ", arr[i]);
				printf("\n");
				break;
		}
		free(arr);
	}
}
