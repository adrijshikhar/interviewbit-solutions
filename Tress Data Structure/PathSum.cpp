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

stack<TreeNode *> path;

int pathsum(TreeNode *root, int B, int sum)
{
  if (!root)
    return 0;
  sum += root->val;
  
  if (!root->left && !root->right)
    return sum == B;
  int suml = pathsum(root->left, B, sum);
  int sumr = pathsum(root->right, B, sum);
  if (suml || sumr)
    return 1;
  return 0;
}

int hasPathSum(TreeNode *A, int B)
{
  if (!A)
    return 0;

  return pathsum(A, B, 0);
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
  vector<int> v1{1000, 200};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(v2);
  cout << endl;
  int v3 = hasPathSum(v2, 1000);
  cout << v3;

  return 0;
}
