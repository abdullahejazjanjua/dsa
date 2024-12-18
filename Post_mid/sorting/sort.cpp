#include <iostream>
using namespace std;

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        swap(arr[minIdx], arr[i]);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high)
{
    if (low > high)
    {
        return;
    }
    int pi = partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
}

void merge(int arr[], int left, int right, int mid)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int *left_arr = new int[left_size];
    int *right_arr = new int[right_size];

    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (i < right_size)
    {
        arr[k] = right_arr[i];
        j++;
        k++;
    }    
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right, mid);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    QuickSort(arr, 0, n - 1);
    
    cout << "\nSorted array by Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int arr2[] = {12, 11, 13, 5, 6};
    selectionSort(arr2, n);
    cout << "\nSorted array by Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    int arr3[] = {12, 11, 13, 5, 6};
    mergeSort(arr3, 0, n - 1);
    cout << "\nSorted array by Merge Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr3[i] << " ";



    return 0;
}