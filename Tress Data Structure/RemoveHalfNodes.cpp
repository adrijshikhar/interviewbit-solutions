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
  {
    root = new TreeNode(val);
  }
  else if (val <= root->val)
  {
    root->left = insertNode(root->left, val);
  }
  else
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}

TreeNode *makeBinaryTree(vector<int> &A)
{
  TreeNode *root = NULL;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i] != -1)
    {
      root = insertNode(root, A[i]);
    }
  }
  return root;
}

stack<TreeNode *> path;

void traverseBST(TreeNode *root, TreeNode *left, TreeNode *right)
{
  if (root == NULL || root->val == -1)
  {
    return;
  }
  if (left != NULL)
  {
    if (left->left != NULL && left->right == NULL)
    {
      root->left = left->left;
    }
    if (left->right != NULL && left->left == NULL)
    {
      root->left = left->right;
    }
  }

  if (right != NULL)
  {
    if (right->left != NULL && right->right == NULL)
    {
      root->right = right->left;
    }

    if (right->right != NULL && right->left == NULL)
    {
      root->right = right->right;
    }
  }

  traverseBST(root->left, root->left->right, root->left->right);
  traverseBST(root->right, root->right->left, root->right->right);
}

TreeNode *removeHaveNodes(TreeNode *root)
{
  if (root == NULL)
    return NULL;

  root->left = removeHaveNodes(root->left);
  root->right = removeHaveNodes(root->right);

  if (root->left == NULL && root->right == NULL)
    return root;

  /* if current nodes is a half node with left 
       child NULL left, then it's right child is 
       returned and replaces it in the given tree */
  if (root->left == NULL)
  {
    TreeNode *new_root = root->right;
    free(root); // To avoid memory leak
    return new_root;
  }

  /* if current nodes is a half node with right 
       child NULL right, then it's right child is 
       returned and replaces it in the given tree  */
  if (root->right == NULL)
  {
    TreeNode *new_root = root->left;
    free(root); // To avoid memory leak
    return new_root;
  }

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
  vector<int> v1{1, 2, 3, 4, 5, -1, 6, 10, -1, -1, -1, -1, -1, -1, 8};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;
  TreeNode *t2 = removeHaveNodes(temp);
  cout << t2 << endl;

  printBinaryTree(v2);

  return 0;
}
