#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    int *a;
    int size;
    int capacity;
    int tos;

    mystack(int cap)
    {
        a = new int[cap];
        capacity = cap;
        tos = -1;
        size = 0;
    }

    void push(int x)
    {
        if (size != capacity)
        {
            a[++tos] = x;
            size++;
        }
    }

    int pop()
    {
        size--;
        return a[tos--];
    }

    int top()
    {
        return a[tos];
    }

    bool isempty()
    {
        return size == 0;
    }
    bool isfull()
    {
        return size == capacity;
    }
    int getsize(){
        return size;
    }
};

int main(){
    mystack s = mystack(10);
    s.push(10);
    s.push(19);
    s.push(11);
    cout << s.top() << endl;
    cout << s.pop() <<endl;
    cout << s.top() << endl;
    cout << s.isempty() << endl;
}
