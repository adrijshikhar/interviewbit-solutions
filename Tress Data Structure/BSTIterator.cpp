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
    root = insertNode(root, A[i]);
  }
  return root;
}


stack<TreeNode *> path;
void pushall(TreeNode *root)
{
  while (root)
  {
    path.push(root);
    root = root->left;
  }
}
class BSTIterator
{
public:
  BSTIterator(TreeNode *root);

  static bool hasNext();
  static int next();
};

BSTIterator::BSTIterator(TreeNode *root)
{
  pushall(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
  return !path.empty();
}

/** @return the next smallest number */
int BSTIterator::next()
{
  TreeNode *tmp = path.top();
  path.pop();
  pushall(tmp->right);
  return tmp->val;
}

int main()
{
  vector<int> v1{2, 1, 3, -1, -1, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  return 0;
}
