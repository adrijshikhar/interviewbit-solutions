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

stack<TreeNode *> path;

void printLevelOrder(TreeNode *root)
{
  if (root == NULL)
    return;

  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    cout << node->val << " ";
    q.pop();

    if (node->left != NULL)
      q.push(node->left);
    if (node->right != NULL)
      q.push(node->right);
  }
}

vector<int> pathToGivenNode(TreeNode *A, int B)
{
  queue<TreeNode *> mq;
  vector<int> values, ans;
  TreeNode *nullNode = new TreeNode(-1);

  mq.push(A);
  while (!mq.empty())
  {
    TreeNode *fr = mq.front();
    mq.pop();

    values.push_back(fr->val);
    if (fr->left != NULL)
      mq.push(fr->left);
    else if (fr->val != -1)
      mq.push(nullNode);

    if (fr->right != NULL)
      mq.push(fr->right);
    else if (fr->val != -1)
      mq.push(nullNode);
  }
  int i, n = values.size(), c = 0;
  i = n - 1;
  while (0 <= i)
  {
    if (values[i] == B)
      break;
    i--;
  }
  c = i;
  ans.push_back(values[c]);
  while (0 < c)
  {
    c = (c - 1) / 2;
    ans.push_back(values[c]);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  vector<int> v1{1, 2, 3, -1, 4, -1, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1};

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);
  cout << v2 << endl;

  printLevelOrder(v2);
  cout << endl;

  vector<int> v3 = pathToGivenNode(v2, 5);
  for (int i = 0; i < v3.size(); i++)
  {
    cout << v3[i] << " ";
  }

  return 0;
}
