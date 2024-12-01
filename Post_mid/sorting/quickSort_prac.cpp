#include <iostream>
using namespace std;
void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int low, int high)
{
    int j = low;
    int i = low - 1;
    int pivot = a[high];

    while (j < high)
    {
        if (a[j] <= pivot)
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
        return;

    int pi = partition(a, low, high);
    QuickSort(a, low, pi - 1);
    QuickSort(a, pi + 1, high);
}   

int main()
{
    int arr[] = {12, 11, 13, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    QuickSort(arr, 0, n - 1);
    
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}