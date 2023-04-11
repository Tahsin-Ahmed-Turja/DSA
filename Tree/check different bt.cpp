#include <bits/stdc++.h>
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

void preorder(node *r)
{
    if (r == NULL)
        return;
    cout << r->data << "->";
    preorder(r->left);
    preorder(r->right);
}

void postorder(node *r)
{
    if (r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << "->";
}

bool isfull(node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if ((root->left) && (root->right))
    {
        return (isfull(root->left) && isfull(root->right));
    }
    return false;
}

bool isComplete(node *root)
{
    if (root == NULL)
        return true;

    queue<node *> q;
    q.push(root);

    bool flag = false;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            if (flag)
                return false;
            q.push(temp->left);
        }
        else
            flag = true;

        if (temp->right)
        {
            if (flag)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;
    }

    return true;
}

int finddepth(node *root)
{
    int d = 0;
    while (root)
    {
        d++;
        root = root->left;
    }
    return d;
}

bool isperfecttree(node* root,int d,int level = 0){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL){
        return (d==level+1);
    }
    else if(root->left==NULL || root->right==NULL){
        return false;
    }
    return isperfecttree(root->left,d,level+1) && isperfecttree(root->right,d,level+1);
}

bool isperfect(node *root)
{
    int d = finddepth(root);
    return isperfecttree(root,d);
}

int height(node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left),height(root->right));
}

bool isbanlanced(node* root){
    if(root == NULL) return 1;
    int lh;
    int rh;
    lh = height(root->left);
    rh = height(root->right);
    if(abs(lh-rh)<=1 && isbanlanced(root->left) && isbanlanced(root->right)){
        return 1;
    }
    return 0;
}

bool left_skew(node* root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->right!=NULL) return 0;
    else
        return left_skew(root->right);
}

bool right_skew(node* root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left!=NULL) return 0;
    else
        right_skew(root->right);
}

bool Degenerate(node* root){
    bool f = left_skew(root) || right_skew(root);
    return f;
}

int main()
{
    node *root = new node(5);
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
    cout << isfull(root) << endl;
    cout << isComplete(root) << endl;
    cout << isperfect(root) << endl;
    cout << isbanlanced(root) << endl;
    cout << Degenerate(root) << endl;
}
