#include<bits/stdc++.h>
using namespace std;

class mydeque{
    public:
    int *a;
    int front,rear;
    int capacity,size;
    mydeque(int cap){
        capacity = cap;
        a = new int[cap];
        front = 0;
        rear = 0;
        size = 0;
    }

    void push_front(int x){
        if(size == capacity) return;
        if(front == 0){
            front = capacity-1;
            a[front] = x;
        } else {
            front--;
            a[front] = x;
        }
        size++;
    }

    int pop_front(){
        if(!isempty()){
            size--;
            int value = a[front];
            if(front == capacity-1){
                front = 0;
            } else {
                front++;
            }
            return value;
        }
    }

    int top_front(){
        if(!isempty()){
            return a[front];
        }
    }

    void push_back(int x){
        if(size == capacity) return;
        a[rear] = x;
        rear = (rear+1)%capacity;
        size++;
    }

    int pop_back(){
        if(!isempty()){
            size--;
            if(rear == 0){
                rear = capacity-1;
                return a[rear];
            } else {
                rear--;
                return a[rear];
            }
        }
    }

    int back(){
        if(!isempty()){
            if(rear == 0){
                return a[capacity-1];
            } else {
                return a[rear-1];
            }
        }
    }

    bool isempty(){
        return size == 0;
    }

    int getsize(){
        return size;
    }
};

int main(){
    mydeque q = mydeque(5);
    q.push_front(1);
    q.push_back(2);
    q.push_front(3);
    q.push_back(4);
    cout << q.top_front() << endl; // output: 3
    cout << q.back() << endl; // output: 4
    cout << q.pop_front() << endl; // output: 3
    cout << q.pop_back() << endl; // output: 4
    cout << q.top_front() << endl; // output: 1
    cout << q.back() << endl; // output: 2
    return 0;
}
