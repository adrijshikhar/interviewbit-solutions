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

TreeNode *buildTree(vector<int> &A)
{
  sort(A.begin(), A.end(), greater<int>());
  TreeNode *v2 = makeBinaryTree(A, v2, 0);
  return v2;
}

void printBinaryTree(TreeNode *root)
{
  if (root == NULL)
  {
    return;
  }
  printBinaryTree(root->left);
  printBinaryTree(root->right);
  cout << root->val << " ";
}

int main()
{
  vector<int> v1{1, 2, 3, 4, 5};
  TreeNode *temp;

  TreeNode *v2 = buildTree(v1);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(temp);

  return 0;
}
