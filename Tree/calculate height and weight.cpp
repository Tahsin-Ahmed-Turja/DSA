
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

int calheight(node *r)
{
    if (r == NULL)
        return 0;

    int lh = calheight(r->left);
    int rh = calheight(r->right);

    return max(lh, rh) + 1;
}

int height(node *r)
{
    queue<node *> q;
    q.push(r);
    q.push(NULL);
    int h = 0;
    while (!q.empty())
    {
        node *tem = q.front();
        q.pop();

        if (tem == NULL)
        {
            h++;
        }

        if (tem != NULL)
        {
            if (tem->left != NULL)
            {
                q.push(tem->left);
            }
            if (tem->right != NULL)
            {
                q.push(tem->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    return h;
}

int heightbfs(node *root)
{
    queue<node *> q;
    q.push(root);
    int height = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        height++;
    }
    return height;
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
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << calheight(root) << endl;
    cout << height(root) << endl;
    cout << heightbfs(root) << endl;
}
