#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *r){
    if(r==NULL) return;
    inorder(r->left);
    cout << r->data <<"->";
    inorder(r->right);
}

void preorder(node* r){
    if(r==NULL) return;
    cout << r->data <<"->";
    preorder(r->left);
    preorder(r->right);
}

void postorder(node *r){
    if(r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data <<"->";
}

int main(){
    node* root = new node(5);
    node *l1 = new node(3);
    node *r1 = new node(7);
    root->left = l1;
    root->right = r1;
    node *l = new node(1);
    node *r = new node(4);
    l1->left = l;
    l1->right = r;
    l = new node(6);
    r = new node(9);
    r1->left = l;
    r1->right = r;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}
