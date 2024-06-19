#include <stdio.h>
#include <malloc.h>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
	{
        for (int j = 0; j < size - 1 - i; j++)
		{
            if (arr[j] > arr[j + 1])
			{
				arr[j] = arr[j] + arr[j + 1];
				arr[j + 1] = arr[j] - arr[j + 1];
				arr[j] = arr[j] - arr[j + 1];
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
				arr[i] = arr[i] + arr[j];
				arr[j] = arr[i] - arr[j];
				arr[i] = arr[i] - arr[j];
			}
		}
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int L[left_size], R[right_size];

    for (i = 0; i < left_size; i++)
        L[i] = arr[left + i];
    for (j = 0; j < right_size; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
	//merge the two arrays back into the original array in sorted order
    while (i < left_size && j < right_size)
	{
        if (L[i] <= R[j])
		{
            arr[k] = L[i];
            i++;
        }
        else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
	{
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size)
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
	{
        int mid = (right + left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}



int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
	{
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) return mid;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
