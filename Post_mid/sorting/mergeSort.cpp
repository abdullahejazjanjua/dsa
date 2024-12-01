#include <iostream>
using namespace std;


void merge(int a[], int left, int right, int mid)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    int *left_array = new int[left_size];
    int *right_array = new int[right_size];

    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = a[left + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_array[i] = a[i + mid + 1];
    }
    

    // merge the two arrays
    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
        {
            a[k] = left_array[i];
            i++;
        }
        else
        {
            a[k] = right_array[j];
            j++;
        }
        k++;
    }

    // Add the remaing elements
    while (i < left_size)
    {
        a[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        a[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    merge(a, left, right, mid);
}

int main()
{
    int array[] = {12, 11, 13, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}