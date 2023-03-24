#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* pre;
    node *next;
    node(int x){
        data = x;
        pre = NULL;
        next = NULL;
    }
};

void print(node* head){
    node* tem = head;
    while(tem!=NULL){
        cout << tem->data <<" ";
        tem = tem->next;
    }
    cout << endl;
}

void push_f(node** head,int x){
    node* tem = new node(x);
    tem->next = *head;
    *head = tem;
}

void push_b(node** head,int x){
    if(*head == NULL){
        (*head) = new node(x);
        return;
    }
    node* tem = *head;
    while(tem->next != NULL){
        tem = tem->next;
    }
    node* i = new node(x);
    tem->next = i;
}

int main(){
    node *head = NULL;
    push_f(&head,5);
    push_f(&head,1);
    push_b(&head,10);
    print(head);
}
