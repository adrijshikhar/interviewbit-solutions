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

vector<vector<int>> levelOrder(TreeNode *A)
{
  vector<vector<int>> ans;
  queue<TreeNode *> mq;
  vector<int> temp;
  mq.push(A);
  mq.push(NULL);
  while (!mq.empty())
  {
    TreeNode *fr = mq.front();

    mq.pop();
    if (fr == NULL)
    {
      ans.push_back(temp);
      temp.clear();
      if (!mq.empty())
        mq.push(NULL);
    }
    else
    {
      temp.push_back(fr->val);
      if (fr->left)
      {
        mq.push(fr->left);
      }
      if (fr->right)
      {
        mq.push(fr->right);
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> v1{1, 2, 3, 4, 5, 6, 7};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;
  printBinaryTree(temp);
  cout << endl;
  vector<vector<int>> v3 = levelOrder(v2);
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
