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

void getLevel(TreeNode *root, int level, vector<int> &row)
{
  if (root == NULL || root->val == -1)
    return;
  if (level == 1)
    row.push_back(root->val);

  if (level > 1)
  {
    getLevel(root->left, level - 1, row);
    getLevel(root->right, level - 1, row);
  }
}

int height(TreeNode *node)
{
  if (node == NULL)
    return 0;
  else
  {
    /* compute the height of each subtree */
    int lheight = height(node->left);
    int rheight = height(node->right);

    /* use the larger one */
    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}
//recursive approach
vector<vector<int>> solve(TreeNode *A)
{
  vector<int> row;
  vector<vector<int>> result;
  if (!A)
    return result;
  int h = height(A);
  int i = 1;
  while (i <= h)
  {
    getLevel(A, i, row);

    if (i % 2 == 0)
    {
      reverse(row.begin(), row.end());
    }
    result.push_back(row);

    row.clear();
    i++;
  }
  return result;
}

// queue approach

vector<vector<int>> solve2(TreeNode *A)
{
  queue<TreeNode *> q;
  vector<vector<int>> res;
  int i = 1;
  q.push(A);
  q.push(NULL);
  vector<int> temp;
  while (!q.empty())
  {
    TreeNode *fr = q.front();
    q.pop();
    if (fr == NULL)
    {
      if (i % 2 == 0)
      {
        reverse(temp.begin(), temp.end());
      }
      i++;
      res.push_back(temp);
      temp.clear();
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      temp.push_back(fr->val);
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

  return res;
}
int main()
{
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  TreeNode *root = new TreeNode(818);
  root->right = new TreeNode(2510);
  root->right->left = new TreeNode(212);
  root->right->left->right = new TreeNode(9881);

  vector<vector<int>> v3 = solve2(v2);

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

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
