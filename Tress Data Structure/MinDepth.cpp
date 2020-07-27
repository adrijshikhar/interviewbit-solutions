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
    if (A[i] == -1)
    {
      return NULL;
    }

    TreeNode *temp = new TreeNode(A[i]);
    root = temp;
    root->left = makeBinaryTree(A, root->left, 2 * i + 1);
    root->right = makeBinaryTree(A, root->right, 2 * i + 2);
  }

  return root;
}
int depthPath(TreeNode *root, int h, int minH)
{
  if (!root)
    return h;

  h++;

  int hl = depthPath(root->left, h, minH);
  int hr = depthPath(root->right, h, minH);
  if (hl < minH && !root->right)
  {
    return hl;
  }
  else if (hr < minH && !root->left)
    return hr;
  else if (root->right && root->left)
  {
    if (hl < hr)
      return hl;
    else
      return hr;
  }
  else
    return minH;
}
int minDepth(TreeNode *A)
{
  int h = INT_MAX;
  int minHeight = depthPath(A, 0, h);
  return minHeight;
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
  vector<int> v1{1, 2, 3, -1, -1, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(v2);
  cout << endl;
  int v3 = minDepth(v2);
  cout << v3;

  return 0;
}
