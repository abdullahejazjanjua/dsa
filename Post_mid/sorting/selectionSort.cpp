/*

### Merge Sort
- **Best Time Complexity**: O(n log n)
- **Worst Time Complexity**: O(n log n)
- **Average Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

---

### Quick Sort
- **Best Time Complexity**: O(n log n)
- **Worst Time Complexity**: O(n²)
- **Average Time Complexity**: O(n log n)
- **Space Complexity**: O(log n)

---

### Selection Sort
- **Best Time Complexity**: O(n²)
- **Worst Time Complexity**: O(n²)
- **Average Time Complexity**: O(n²)
- **Space Complexity**: O(1)
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int idx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[idx] )
                idx = j;
        }
        swap(a[i], a[idx]);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    selectionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}