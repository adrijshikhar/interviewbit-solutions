
#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
  treeNode *left;
  treeNode *right;
  int val;
};
class bst
{
  treeNode *root;

public:
  bst()
  {
    root = NULL;
  }
  bool isempty()
  {
    if (root == NULL)
      return true;
    else
      return false;
  }

  void insertNode(int item)
  {
    treeNode *p = new treeNode;
    treeNode *parent;
    p->val = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if (isempty())
    {
      root = p;
    }
    else
    {
      treeNode *ptr;
      ptr = root;
      while (ptr != NULL)
      {
        parent = ptr;
        if (item > ptr->val)
          ptr = ptr->right;
        else
          ptr = ptr->left;
      }
      if (item < parent->val)
      {
        parent->left = p;
      }
      else
      {
        parent->right = p;
      }
    }
  }

  void inOrderTraversal()
  {
    inOrderRec(root);
  }

  void inOrderRec(treeNode *ptr)
  {
    if (ptr != NULL)
    {
      inOrderRec(ptr->left);
      cout << "  " << ptr->val << "     ";
      inOrderRec(ptr->right);
    }
  }

  void preOrderTraversal()
  {
    preOrderRec(root);
  }

  void preOrderRec(treeNode *ptr)
  {
    if (ptr != NULL)
    {
      cout << "  " << ptr->val << "     ";
      preOrderRec(ptr->left);
      preOrderRec(ptr->right);
    }
  }

  void postOrderTraversal()
  {
    postOrderRec(root);
  }

  void postOrderRec(treeNode *ptr)
  {
    if (ptr != NULL)
    {
      postOrderRec(ptr->left);
      postOrderRec(ptr->right);
      cout << "  " << ptr->val << "     ";
    }
  }
};

int main()
{
  bst b;
  b.insertNode(52);
  b.insertNode(25);
  b.insertNode(50);
  b.insertNode(15);
  b.insertNode(40);
  b.insertNode(45);
  b.insertNode(20);
  cout << "inorder" << endl;
  b.inOrderTraversal();
  cout << endl
       << "postorder" << endl;
  b.postOrderTraversal();
  cout << endl
       << "preorder" << endl;
  b.postOrderTraversal();
}
