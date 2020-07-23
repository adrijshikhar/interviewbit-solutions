#include <bits/stdc++.h>

using namespace std;

struct BSTNode
{
  int val;
  BSTNode *left, *right;
  BSTNode(int x) : val(x), right(NULL), left(NULL) {}
};

BSTNode *insertNode(BSTNode *root, int val)
{
  if (root == NULL)
  {
    root = new BSTNode(val);
  }
  else if (val <= root->val)
  {
    root->left = insertNode(root->left, val);
  }
  else
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}

BSTNode *makeBinaryTree(vector<int> &A)
{
  BSTNode *root = NULL;
  for (int i = 0; i < A.size(); i++)
  {
    root = insertNode(root, A[i]);
  }
  return root;
}

void printBinaryTree(BSTNode *root)
{
  if (root == NULL)
  {
    return;
  }
  printBinaryTree(root->left);
  printBinaryTree(root->right);
  cout << root->val << " ";
}

int main()
{
  vector<int> v1{4, 2, 6, 1, 3, 5, 7};
  BSTNode *temp;

  BSTNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;
  printBinaryTree(temp);

  return 0;
}
