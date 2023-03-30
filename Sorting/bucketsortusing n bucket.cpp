void bucketSort(float arr[], int n) {
    const int numBuckets = 15;

    // Create buckets
    Node* buckets[numBuckets];

    // Initialize empty buckets
    for (int i = 0; i < numBuckets; ++i) {
        buckets[i] = nullptr;
    }

    // Fill the buckets with respective elements
    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] * numBuckets;
        Node* current = new Node(arr[i]);
        current->next = buckets[bucketIndex];
        buckets[bucketIndex] = current;
    }

    // Sort the elements of each bucket using insertion sort
    for (int i = 0; i < numBuckets; ++i) {
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
    for (int i = 0; i < numBuckets; ++i) {
        Node* bucket = buckets[i];
        while (bucket) {
            arr[k++] = bucket->data;
            bucket = bucket->next;
        }
    }

    // Free memory
    for (int i = 0; i < numBuckets; ++i) {
        Node* bucket = buckets[i];
        while (bucket) {
            Node* tmp = bucket;
            bucket = bucket->next;
            delete tmp;
        }
    }
}
