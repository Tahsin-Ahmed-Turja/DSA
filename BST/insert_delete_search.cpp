#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *r)
{
    if (r == NULL)
        return;
    inorder(r->left);
    cout << r->data << "->";
    inorder(r->right);
}

node* insertion(node* r,int k){
    if(r==NULL) return new node(k);
    if(k<r->data){
        r->left = insertion(r->left,k);
    }
    else{
        r->right = insertion(r->right,k);
    }
    return r;
}

bool search(node* r,int k){
    if(r==NULL) return false;
    if(r->data == k) return true;
    if(k<r->data){
        return search(r->left,k);
    }
    else{
        return search(r->right,k);
    }
}

node* minValue(node* r){
    node* c = r;

    while(c && c->left){
        c = c->left;
    }
    return c;
}

node* deleteNode(node* r,int k){
    if(r==NULL) return r;

    if(k<r->data) r->left = deleteNode(r->left,k);

    else if(k>r->data) r->right = deleteNode(r->right,k);

    else{
        if(r->left == NULL){
            node* tem = r->right;
            free(r);
            return tem;
        }
        else if(r->right == NULL){
            node* tem = r->left;
            free(r);
            return tem;
        }
        node* tem = minValue(r->right);
        r->data = tem->data;
        r = deleteNode(r->right,tem->data);
    }
    return r;
}

int main(){
    node* root = NULL;
    root = insertion(root, 8);
    root = insertion(root, 5);
    root = insertion(root, 4);
    root = insertion(root, 3);
    root = insertion(root, 1);
    root = insertion(root, 9);
    root = insertion(root, 10);
    root = insertion(root, 11);
    inorder(root);
    cout << endl;
    root = deleteNode(root,5);
    inorder(root);
    cout << endl;
}
