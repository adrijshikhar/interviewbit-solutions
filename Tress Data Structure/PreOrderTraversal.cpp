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

vector<int> preorderTraversal(TreeNode *A)
{
  vector<int> result;
  if (!A)
    return result;
  stack<TreeNode *> path;
  path.push(A);

  while (!path.empty())
  {
    TreeNode *tmp = path.top();
    result.push_back(tmp->val);
    path.pop();
    if (tmp->right)
      path.push(tmp->right);
    if (tmp->left)
    {
      path.push(tmp->left);
    }
  }

  return result;
}
int main()
{
  vector<int> v1{1, 2, 3, 4, 5};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  TreeNode *root = new TreeNode(818);
  root->right = new TreeNode(2510);
  root->right->left = new TreeNode(212);
  root->right->left->right = new TreeNode(9881);

  vector<int> v3 = preorderTraversal(v2);

  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
