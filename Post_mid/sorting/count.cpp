#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(int arr[], int n) 
{
    // Step 1: Find the maximum element in the array
    int maxElement = *max_element(arr, arr + n);
    
    // Step 2: Create a count array to store the frequency of each element
    int count[maxElement + 1] = {0};  // Initialize all elements to 0
    
    // Step 3: Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Step 4: Create a position array to store the position of each element
    int position[maxElement + 1] = {0};
    position[0] = count[0];
    for (int i = 1; i <= maxElement; i++) {
        position[i] = position[i - 1] + count[i];
    }
    
    // Step 5: Create a temporary sorted array
    int sortedArr[n];
    
    // Step 6: Place elements in the sorted array using the position array
    for (int i = n - 1; i >= 0; i--) 
    {
        
        int num = arr[i];
        sortedArr[position[num] - 1] = num;
        position[num]--;
    }
    
    // Step 7: Copy the sorted array back to the original array
    for (int i = 0; i < n; i++) 
    {
        arr[i] = sortedArr[i];
    }
}

int main() {
    // Example usage
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
