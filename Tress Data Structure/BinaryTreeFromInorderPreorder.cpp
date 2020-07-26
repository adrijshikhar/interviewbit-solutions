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

TreeNode *makeBST(const vector<int> &A, TreeNode *root, int low, int high)
{
  int mid = low + (high - low) / 2;
  if (low <= high)
  {
    cout << low << " " << mid << " " << high << endl;
    root = new TreeNode(A[mid]);
  }
  else
  {
    return NULL;
  }

  root->left = makeBST(A, root->left, low, mid - 1);
  root->right = makeBST(A, root->right, mid + 1, high);
  return root;
}

int findIndex(vector<int> &inorder, int i, int j, int val)
{
  for (auto b = i; b <= j; ++b)
    if (inorder[b] == val)
      return b;

  return -1;
}

TreeNode *buildUtil(vector<int> &in, vector<int> &pre, int inStrt, int inEnd, int &pIndex)
{
  if (inStrt > inEnd)
    return NULL;

  TreeNode *root = new TreeNode(pre[pIndex++]);

  if (inStrt == inEnd)
    return root;

  int iIndex = findIndex(in, inStrt, inEnd, root->val);

  root->left = buildUtil(in, pre, inStrt, iIndex - 1, pIndex);
  root->right = buildUtil(in, pre, iIndex + 1, inEnd, pIndex);

  return root;
}

TreeNode *buildTree(vector<int> &A, vector<int> &B)
{

  int p = 0;
  return buildUtil(A, B, 0, A.size() - 1, p);
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
  vector<int> v1{4, 2, 5, 1, 3};
  vector<int> v4{1, 2, 4, 5, 3};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(v2);
  cout << endl;
  TreeNode *v3 = buildTree(v4, v1);
  printBinaryTree(v3);

  return 0;
}
