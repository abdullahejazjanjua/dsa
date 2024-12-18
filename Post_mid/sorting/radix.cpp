#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to perform counting sort on the basis of a particular digit (place)
void countingSortByDigit(int arr[], int n, int exp) {
    int output[n];  // Output array to store sorted numbers
    int count[10] = {0};  // Count array to store frequency of digits

    // Store the count of occurrences of digits (0-9)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Update the count array to store the position of each digit
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing each element at its correct position
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted numbers into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int maxElement = *max_element(arr, arr + n);

    // Apply counting sort for every digit (place)
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
    }
}

int main() {
    // Example usage
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
