#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class myqueue{
public:
    node* front;
    node* rear;
    int size;

    myqueue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void push(int x) {
       node *tem = new node(x);
       if (rear == NULL) {
           front = rear = tem;
       } else {
           rear->next = tem;
           rear = tem;
       }
       size++;
    }

    int pop() {
        if (!isempty()) {
            size--;
            node *tem = front;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            }
            int res = tem->data;
            delete(tem);
            return res;
        }
    }

    int top() {
        if (!isempty()) {
            return front->data;
        }
    }

    bool isempty() {
        return size == 0;
    }

    int getsize() {
        return size;
    }
};

int main() {
    myqueue q;
    q.push(5);
    q.push(6);
    q.push(7);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    q.push(8);
    cout << q.pop() << endl;
    cout << q.isempty() << endl;
    return 0;
}
