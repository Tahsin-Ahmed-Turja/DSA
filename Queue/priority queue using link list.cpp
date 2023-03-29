#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;
    
    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;
    int size;
    
public:
    PriorityQueue() {
        front = nullptr;
        size = 0;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    void enqueue(int item, int priority) {
        Node* newNode = new Node(item, priority);
        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && priority <= temp->next->priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        Node* temp = front;
        int item = temp->data;
        front = front->next;
        delete temp;
        size--;
        return item;
    }
    
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(3, 2);
    pq.enqueue(1, 1);
    pq.enqueue(4, 3);
    pq.enqueue(1, 2);
    pq.enqueue(5, 1);
    
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Peek: " << pq.peek() << std::endl;
    std::cout << "Dequeue: " << pq.dequeue() << std::endl;
    std::cout << "Peek: " << pq.peek() << std::endl;
    
    return 0;
}
