#include <iostream>
#include <vector>

using namespace std;

void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int maxElement = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create a count array to store the count of each element
    vector<int> count(maxElement + 1, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the cumulative count
    for (int i = 1; i <= maxElement; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted array
    int temp[n];

    // Iterate over the original array in reverse order and use the count array to place elements in the correct position in the temporary array
    for (int i = n - 1; i >= 0; --i) {
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements from the temporary array to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, n);

    cout << "After sorting: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
