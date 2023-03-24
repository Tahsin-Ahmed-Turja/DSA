#include <bits/stdc++.h>
using namespace std;

class mystack
{
public:
    string *a;
    int size;
    int capacity;
    int tos;

    mystack(int cap)
    {
        a = new string[cap];
        capacity = cap;
        tos = -1;
        size = 0;
    }

    void push(string x)
    {
        if (size != capacity)
        {
            a[++tos] = x;
            size++;
        }
    }

    string pop()
    {
        return a[tos--];
        size--;
    }

    string top()
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
    s.push("Welcome! say, hello world");
    s.push("How are you, Takrim");
    s.push("yeah well but world is dirty so i fill nervous");
    cout << s.top() << endl;
    cout << s.pop() <<endl;
    cout << s.top() << endl;
    cout << s.isempty() << endl;
}
