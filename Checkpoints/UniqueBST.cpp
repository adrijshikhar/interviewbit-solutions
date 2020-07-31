#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

vector<TreeNode *> constructTrees(int start, int end)
{
  vector<TreeNode *> list;
  if (start > end)
  {
    list.push_back(NULL);
    return list;
  }

  for (int i = start; i <= end; i++)
  {
    vector<TreeNode *> leftSubtree = constructTrees(start, i - 1);
    vector<TreeNode *> rightSubtree = constructTrees(i + 1, end);

    for (int j = 0; j < leftSubtree.size(); j++)
    {
      TreeNode *left = leftSubtree[j];
      for (int k = 0; k < rightSubtree.size(); k++)
      {
        TreeNode *right = rightSubtree[k];
        TreeNode *node = new TreeNode(i);
        node->left = left;
        node->right = right;
        list.push_back(node);
      }
    }
  }
  return list;
}

vector<TreeNode *> generateTrees(int A)
{
  return constructTrees(1, A);
}

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

int main()
{
  int v1 = 3;
  vector<TreeNode *> v3 = generateTrees(v1);
  for (int i = 0; i < v3.size(); i++)
  {
    printLevelOrder(v3[i]);
    cout << endl;
  }

  return 0;
}
