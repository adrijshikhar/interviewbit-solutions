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


vector<int> solve(TreeNode *A)
{
  queue<TreeNode *> q;
  vector<int> mp;
  q.push(A);
  q.push(NULL);
  int temp;
  while (!q.empty())
  {
    TreeNode *fr = q.front();
    q.pop();
    if (fr == NULL)
    {
      mp.push_back(temp);

      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      temp = fr->val;
      if (fr->left)
      {
        q.push(fr->left);
      }
      if (fr->right)
      {
        q.push(fr->right);
      }
    }
  }

  return mp;
}
int main()
{
  vector<int> v1{1, 2, 3, -1, 4, -1, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  TreeNode *root = new TreeNode(818);
  root->right = new TreeNode(2510);
  root->right->left = new TreeNode(212);
  root->right->left->right = new TreeNode(9881);

  vector<int> v3 = solve(v2);

  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}

