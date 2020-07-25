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
  stack<TreeNode *> nodeStack;
  vector<int> result;
  //base case
  if (root == NULL)
    return result;
  nodeStack.push(root);
  while (!nodeStack.empty())
  {
    TreeNode *node = nodeStack.top();
    result.push_back(node->val);
    nodeStack.pop();
    if (node->left)
      nodeStack.push(node->left);
    if (node->right)
      nodeStack.push(node->right);
  }
  reverse(result.begin(), result.end());
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
