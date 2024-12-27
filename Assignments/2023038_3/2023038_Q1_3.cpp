#include <iostream>
#include <algorithm>

using namespace std;

void countingSort(int arr[], int n) 
{
    if (n == 0) return;

    int maxVal = *max_element(arr, arr + n);
    int *count = new int[maxVal + 1];
    
    for (int i = 0; i < maxVal + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < maxVal + 1; i++)
    {
        count[i] += count[i - 1];
    }

    int *tmp = new int[n];
    for (int i = n - 1; i >= 0; i--) 
    {
        tmp[--count[arr[i]]] = arr[i]; 
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = tmp[i];
    }
    delete[] count;
    delete[] tmp;

}

void countingSortRadix(int arr[], int n, int pos) 
{
    int *output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) 
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) 
{
    int maxVal = *max_element(arr, arr + n);

    for (int pos = 1; maxVal / pos > 0; pos *= 10) 
    {
        countingSortRadix(arr, n, pos);
    }
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {12, 11, 13, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original array for Counting Sort: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    countingSort(arr2, n2);

    cout << "Sorted array using Counting Sort: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "\nOriginal array for Radix Sort: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    radixSort(arr1, n1);

    cout << "Sorted array using Radix Sort: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}
