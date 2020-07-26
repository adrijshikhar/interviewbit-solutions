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

void findPathSum(TreeNode *A, int sum, vector<vector<int>> &res, vector<int> &path)
{
  if (!A)
    return;
  sum -= A->val;
  path.emplace_back(A->val);
  if (!A->left && !A->right && sum == 0)
    res.emplace_back(path);
  findPathSum(A->left, sum, res, path);
  findPathSum(A->right, sum, res, path);
  path.pop_back();
}
vector<vector<int>> pathsum(TreeNode *A, int B)
{
  vector<vector<int>> res;
  vector<int> path;
  if (!A)
    return res;

  findPathSum(A, B, res, path);
  return res;
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
  cout << endl;
  vector<vector<int>> v3 = pathsum(v2, 7);
  for (int i = 0; i < v3.size(); i++)
  {
    for (int j = 0; j < v3[i].size(); j++)
    {
      cout << v3[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
