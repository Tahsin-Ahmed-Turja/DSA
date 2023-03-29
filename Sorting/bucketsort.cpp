#include <iostream>

using namespace std;

class Node {
public:
    float data; // Change int to float to match the data type of the array
    Node* next;
    Node(float d){
        data = d;
        next = NULL;
    }
};

void bucketSort(float arr[], int n) {
    // Create buckets
    Node* buckets[n];

    // Initialize empty buckets
    for (int i = 0; i < n; ++i) {
        buckets[i] = nullptr;
    }

    // Fill the buckets with respective elements
    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] * n;
        Node* current = new Node(arr[i]);
        current->next = buckets[bucketIndex];
        buckets[bucketIndex] = current;
    }

    // Sort the elements of each bucket using insertion sort
    for (int i = 0; i < n; ++i) {
        Node* bucket = buckets[i];
        Node* sortedBucket = nullptr;
        while (bucket) {
            Node* current = bucket;
            bucket = bucket->next;
            if (!sortedBucket || current->data < sortedBucket->data) {
                current->next = sortedBucket;
                sortedBucket = current;
            }
            else {
                Node* ptr = sortedBucket;
                while (ptr->next && current->data > ptr->next->data) {
                    ptr = ptr->next;
                }
                current->next = ptr->next;
                ptr->next = current;
            }
        }
        buckets[i] = sortedBucket;
    }

    // Put sorted elements back into the original array
    int k = 0;
    for (int i = 0; i < n; ++i) {
        Node* bucket = buckets[i];
        while (bucket) {
            arr[k++] = bucket->data;
            bucket = bucket->next;
        }
    }

    // Free memory
    for (int i = 0; i < n; ++i) {
        Node* bucket = buckets[i];
        while (bucket) {
            Node* tmp = bucket;
            bucket = bucket->next;
            delete tmp;
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Initial array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    bucketSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
