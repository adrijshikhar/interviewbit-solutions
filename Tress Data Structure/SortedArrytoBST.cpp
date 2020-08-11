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
    root = new TreeNode(val);
  else if (val <= root->val)
    root->left = insertNode(root->left, val);
  else
    root->right = insertNode(root->right, val);
  return root;
}

TreeNode *makeBinaryTree(vector<int> &A, TreeNode *root, int i)
{
  if (i < A.size())
  {
    TreeNode *temp = new TreeNode(A[i]);
    root = temp;
    root->left = makeBinaryTree(A, root->left, 2 * i + 1);
    root->right = makeBinaryTree(A, root->right, 2 * i + 2);
  }

  return root;
}

TreeNode *makeBST(const vector<int> &A, TreeNode *root, int low, int high)
{
  int mid = low + (high - low) / 2;
  if (low <= high)
  {
    root = new TreeNode(A[mid]);
  }
  else
  {
    return NULL;
  }

  root->left = makeBST(A, root->left, low, mid - 1);
  root->right = makeBST(A, root->right, mid + 1, high);
  return root;
}

TreeNode *sortedArrayToBST(const vector<int> &A)
{
  TreeNode *root = makeBST(A, root, 0, A.size() - 1);
  return root;
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
  vector<int> v1{1, 2, 3, 4, 5, 6, 7};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(v2);
  cout << endl;
  TreeNode *v3 = sortedArrayToBST(v1);
  printBinaryTree(v3);

  return 0;
}
