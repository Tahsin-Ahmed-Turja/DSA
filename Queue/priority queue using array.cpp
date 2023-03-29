#include <iostream>

#define MAX_SIZE 100

class PriorityQueue {
private:
    int arr[MAX_SIZE];
    int size;
    
public:
    PriorityQueue() {
        size = 0;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void enqueue(int item) {
        if (size == MAX_SIZE) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        int i;
        for (i = size-1; i >= 0; i--) {
            if (item > arr[i]) {
                arr[i+1] = arr[i];
            } else {
                break;
            }
        }
        arr[i+1] = item;
        size++;
    }
    
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int item = arr[size-1];
        size--;
        return item;
    }
    
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[size-1];
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(3);
    pq.enqueue(1);
    pq.enqueue(4);
    pq.enqueue(1);
    pq.enqueue(5);
    
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Peek: " << pq.peek() << std::endl;
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Peek: " << pq.peek() << std::endl;
    
    return 0;
}
