#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    string data;
    node* pre;
    node *next;
    node(string x){
        data = x;
        pre = NULL;
        next = NULL;
    }
};

class mystack{
    public:
    node* tos;
    int size;
    mystack(){
        tos = NULL;
        size = 0;
    }

    void push(string s){
        node *n = new node(s);
        n->next = tos;
        tos = n;
        size++;
    }

    string pop(){
       if(!isempty()){
            string s = tos->data;
            node* n = tos;
            tos = tos->next;
            delete(n);
            size--;
            return s;
       }
    }

    string top(){
        if(!isempty()){
            return tos->data;
        }
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size == 0;
    }
};

int main(){
    mystack s = mystack();
    s.push("Hello Takrim");
    s.push("Say, hello tasnim");
    s.push("Say, hi bushra");
    s.push("say, hi alia");
    cout << s.top() << endl;
    cout << s.pop()<< endl;
    cout << s.top()<< endl;
    cout << s.pop()<< endl;
    cout << s.top()<< endl;
}
