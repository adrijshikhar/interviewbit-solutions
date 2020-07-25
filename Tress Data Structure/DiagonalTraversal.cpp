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

TreeNode *makeBinaryTree(vector<int> &A)
{
  TreeNode *root = NULL;
  for (int i = 0; i < A.size(); i++)
  {
    root = insertNode(root, A[i]);
  }
  return root;
}

void traverseDiagonal(TreeNode *root, int d, map<int, vector<int>> &m)
{
  if (root == NULL)
    return;

  m[d].push_back(root->val);
  traverseDiagonal(root->left, d + 1, m);
  traverseDiagonal(root->right, d, m);
}

vector<int> solve(TreeNode *A)
{
  vector<int> result;
  if (!A)
    return result;
  map<int, vector<int>> m;
  traverseDiagonal(A, 0, m);

  for (auto it = m.begin(); it != m.end(); it++)
    result.insert(result.end(), it->second.begin(), it->second.end());

  return result;
}
int main()
{
  vector<int> v1{1, 2, 3, 4, 5};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
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

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
