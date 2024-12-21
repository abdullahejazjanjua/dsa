#include <iostream>
using namespace std;

void selectionSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        swap(a[minIdx], a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int j = low, i = low - 1;
    while(j < high)
    {
        if(a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
        j++;
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort(int a[], int low, int high)
{
    if (low > high)
    {
        return;
    }

    int pi = partition(a, low, high);
    QuickSort(a, low, pi - 1);
    QuickSort(a, pi + 1, high);
    
}

void merge(int a[], int left, int right, int mid)
{
    int left_size = mid - left + 1; 
    int right_size = right - mid;

    int *left_arr = new int[left_size];
    int *right_arr = new int[right_size];

    for(int i = 0; i < left_size; i++)
    {
        left_arr[i] = a[left + i];
    }
    for(int i = 0; i < right_size; i++)
    {
        right_arr[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while(i < left_size && j < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            a[k] = left_arr[i];
            i++;
        }
        else
        {
            a[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i < left_size)
    {
        a[k] = left_arr[i];
        i++;
        k++;
    }
    while(j < right_size)
    {
        a[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, right, mid);
}


int main()
{

    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}