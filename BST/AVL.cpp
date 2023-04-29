#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int key;
  Node *left;
  Node *right;
  int height;
  Node(int k)
  {
    key = k;
    left = NULL;
    right = NULL;
    height = 1;
  }
};

int height(Node *n)
{
  if (n == NULL)
    return 0;
  else
    return n->height;
}

int getbalancedfactor(Node *n)
{
  if (n == NULL)
    return 0;
  else
    return height(n->left) - height(n->right);
}

Node* rightRotate(Node* y){
  Node* x = y->left;
  Node* z = x->right;
  x->right = y;
  y->left = z;
  y->height = max(height(y->left),height(y->right)) + 1;
  x->height = max(height(x->left),height(x->right)) + 1;
  return x;
}

Node* leftRotate(Node *y){
  Node* x = y->right;
  Node* z = x->left;
  x->left = y;
  y->right = z;
  y->height = max(height(y->left),height(y->right)) + 1;
  x->height = max(height(x->left),height(x->right)) + 1;
  return x;
}

Node *insertNode(Node *r, int key)
{
  if (r == NULL)
    return new Node(key);
  if (key < r->key)
    r->left = insertNode(r->left, key);
  else if (key > r->key)
    r->right = insertNode(r->right, key);
  else
    return r;

  r->height = 1 + max(height(r->left), height(r->right));
  int balancefactor = getbalancedfactor(r);
  if (balancefactor > 1)
  {
    if (key < r->left->key)
    {
      return rightRotate(r);
    }
    else if (key > r->left->key)
    {
      r->left = leftRotate(r->left);
      return rightRotate(r);
    }
  }

  if (balancefactor < -1)
  {
    if (key > r->right->key)
    {
      return leftRotate(r);
    }
    else if (key < r->right->key)
    {
      r->right = rightRotate(r->right);
      return leftRotate(r);
    }
  }
  return r;
}

Node *nodeWithMimumValue(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *deleteNode(Node *root, int key)
{
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right,temp->key);
    }
  }

  if (root == NULL) return root;

  root->height = 1 + max(height(root->left), height(root->right));
  int balancefactor = getbalancedfactor(root);
  if (balancefactor > 1)
  {
    if (key < root->left->key)
    {
      return rightRotate(root);
    }
    else if (key >root->left->key)
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }

  if (balancefactor < -1)
  {
    if (key > root->right->key)
    {
      return leftRotate(root);
    }
    else if (key < root->right->key)
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

void printTree(Node *root, string indent, bool last)
{
  if (root != nullptr)
  {
    cout << indent;
    if (last)
    {
      cout << "R----";
      indent += "   ";
    }
    else
    {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main()
{
  Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
}
