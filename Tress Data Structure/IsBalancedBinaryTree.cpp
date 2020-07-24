#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

TreeNode *insertNode(TreeNode *root, int val)
{
  if (root == NULL)
  {
    root = new TreeNode(val);
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

TreeNode *makeBinaryTree(vector<int> &A)
{
  TreeNode *root = NULL;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] != -1)
    {
      root = insertNode(root, A[i]);
    }
  }
  return root;
}

int subTreeHeight(TreeNode *root)
{
  if (root != NULL)
  {
    int x = subTreeHeight(root->left);
    int y = subTreeHeight(root->right);
    if (x > y)
      return x + 1;
    else
      return y + 1;
  }
  return 0;
}

int isBalanced(TreeNode *A)
{
  if (A == NULL)
    return 1;
  int l = subTreeHeight(A->left);
  int r = subTreeHeight(A->right);
  if (abs(l - r) <= 1 && isBalanced(A->left) && isBalanced(A->right))
  {
    return 1;
  }
  return 0;
}

void printBinaryTree(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->val << " ";
  printBinaryTree(root->left);
  printBinaryTree(root->right);
}

int main()
{
  vector<int> v1{1, 2, 3, 4, 5, -1, 6, 10, -1, -1, -1, -1, -1, -1, 8};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;
  int t2 = isBalanced(temp);
  cout << t2 << endl;

  return 0;
}
