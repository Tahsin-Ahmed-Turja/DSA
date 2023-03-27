#include<bits/stdc++.h>
using namespace std;

class circularqueue{
    public:
    int *a;
    int front, rear;
    int size, capacity;
    circularqueue(int cap){
        a = new int[cap];
        front = 0, rear = 0;
        size = 0;
        capacity = cap;
    }

    void push(int x){
        if(!isfull()){
            size++;
            a[rear] = x;
            rear = (rear+1)%capacity;
        }
    }

    int pop(){
        if(!isempty()){
            int res = a[front];
            front = (front+1)%capacity;
            size--;
            return res;
        }
    }

    int top(){
        if(!isempty()){
            return a[front];
        }
    }

    bool isempty(){
        return size == 0;
    }

    bool isfull(){
        return size == capacity;
    }

    int getsize(){
        return size;
    }
};

int main(){
    circularqueue q = circularqueue(3);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(9);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    q.push(9);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
}
