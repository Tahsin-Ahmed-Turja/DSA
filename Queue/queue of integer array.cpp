#include<bits/stdc++.h>
using namespace std;

class myqueue{
    public:
    int *a;
    int front,rear;
    int capacity,size;
    myqueue(int cap){
        capacity = cap;
        a = new int[cap];
        front = 0;
        rear = 0;
        capacity = cap;
        size = 0;
    }

    void push(int x){
       if(rear == capacity) return;
       a[rear] = x;
       rear++;
       size++;
    }

    int pop(){
        if(!isempty()){
            size--;
            return a[front++];
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

    int getsize(){
        return size;
    }
};

int main(){
    myqueue q = myqueue(10000);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.top() << endl;
    cout << q.pop() << endl;
}
