#include <iostream>
using namespace std;


void merge(int a[], int left, int right, int mid)
{
    int l_size = mid - left + 1;
    int r_size = right - mid;

    int *la = new int[l_size];
    int *ra = new int[r_size];

    for (int i = 0; i < l_size; i++)
    {
        la[i] = a[i + left];
    }
    for (int i = 0; i < r_size; i++)
    {
        ra[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < l_size && j < r_size)
    {
        if (la[i] <= ra[j])
        {
            a[k] = la[i];
            i++;
        }
        else
        {
            a[k] = ra[j];
            j++;
        }
        k++;
    }

    while(i < l_size)
    {
        a[k] = la[i];
        i++;
        k++;
    }
    while(j < r_size)
    {
        a[k] = ra[j];
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
    return 0;
}