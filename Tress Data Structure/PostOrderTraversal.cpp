#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

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

void pushall(TreeNode *root, stack<TreeNode *> &path)
{
  while (root)
  {
    if (root->right)
      path.push(root->right);

    path.push(root);
    root = root->left;
  }
}

vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> result;
  if (!root)
    return result;
  stack<TreeNode *> path;

  while (true)
  {
    while (root != NULL)
    {
      path.push(root);
      path.push(root);
      root = root->left;
    }
    if (path.empty())
      return result;
    root = path.top();
    path.pop();
    if (!path.empty() && path.top() == root)
      root = root->right;

    else
    {
      result.push_back(root->val);
      root = NULL;
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

  vector<int> v3 = postorderTraversal(v2);

  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
