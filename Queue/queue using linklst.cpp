#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* pre;
    node* next;

    node(int x) {
        data = x;
        pre = NULL;
        next = NULL;
    }
};

class myqueue {
public:
    node* front;
    node* rear;
    int size;

    myqueue() {
        front = new node(0);
        rear = NULL;
        size = 0;
    }

    void push(int x) {
        if (size == 0) {
            rear = new node(x);
            front->next = rear;
        }
        else {
            node* temp = new node(x);
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    int pop() {
        if (!isempty()) {
            size--;
            node* temp = front->next;
            int res = temp->data;
            front->next = temp->next;
            delete(temp);
            if (size == 0) {
                rear = NULL;
            }
            return res;
        }
    }

    int top() {
        if (!isempty()) {
            return front->next->data;
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
