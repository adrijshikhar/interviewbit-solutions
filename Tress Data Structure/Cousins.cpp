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

bool flag = false;
void getLevel(TreeNode *root, int level, int B, vector<int> &row)
{
  if (root == NULL)
    return;
  if (level == 1)
    row.push_back(root->val);

  if (level > 1)
  {
    getLevel(root->left, level - 1, B, row);
    getLevel(root->right, level - 1, B, row);
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
int findInRow(vector<int> &row, int num)
{
  for (int i = 0; i < row.size(); i++)
  {
    if (num == row[i])
    {
      return i;
    }
  }
  return -1;
}
vector<int> solve(TreeNode *A, int B)
{
  queue<TreeNode *> q;
  map<int, vector<int>> mp;
  int cur_level = 0;
  int level = 0;
  q.push(A);
  q.push(NULL);
  vector<int> temp;
  while (!q.empty())
  {
    TreeNode *fr = q.front();
    q.pop();
    if (fr == NULL)
    {
      mp[level] = temp;
      temp.clear();
      level++;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      temp.push_back(fr->val);
      if (fr->left and fr->left->val == B)
      {
        cur_level = level;
      }
      else if (fr->right and fr->right->val == B)
      {
        cur_level = level;
      }
      else
      {
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
  }

  vector<int> result = mp[cur_level + 1];
  return result;
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

  vector<int> v3 = solve(v2, 5);

  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
