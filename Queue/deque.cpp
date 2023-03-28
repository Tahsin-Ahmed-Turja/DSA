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

class mydeque {
public:
    node* front;
    node* rear;
    int size;

    mydeque() {
        front = new node(0);
        rear = new node(0);
        front->next = rear;
        rear->pre = front; 
        size = 0;
    }
    
    void push_front(int x){
        node* tem = new node(x);
        tem->next = front->next;
        tem->next->pre = tem;
        tem->pre = front;
        front->next = tem;
        size++;
    }

    void push_back(int x){
        node* tem = new node(x);
        tem->pre = rear->pre;
        tem->pre->next = tem;
        tem->next = rear;
        rear->pre = tem;
        size++;
    }

    int pop_front(){
        if(!isempty()){
            node* tem = front->next;
            front->next = tem->next;
            tem->next->pre = front;
            int res = tem->data;
            delete(tem);
            size--;
            return res;
        }
        return -1; // to handle case where the deque is empty
    }

    int pop_back(){
        if(!isempty()){
            node* tem = rear->pre;
            rear->pre = tem->pre;
            tem->pre->next = rear;
            int res = tem->data;
            delete(tem);
            size--;
            return res;
        }
        return -1; // to handle case where the deque is empty
    }

    int front_value() {
        if (!isempty()) {
            return front->next->data;
        }
        return -1; // to handle case where the deque is empty
    }

    int rear_value(){
        if (!isempty()) {
            return rear->pre->data;
        }
        return -1; // to handle case where the deque is empty
    }

    bool isempty() {
        return size == 0;
    }

    int getsize() {
        return size;
    }
};

int main() {
    mydeque dq;
    dq.push_front(10); //20 10 30 40
    dq.push_front(20);
    dq.push_back(30);
    dq.push_back(40);
    cout << dq.pop_front() << endl; // Output: 20
    cout << dq.pop_back() << endl; // Output: 40
    cout << dq.front_value() << endl; // Output: 10
    cout << dq.rear_value() << endl; // Output: 30
    return 0;
}
