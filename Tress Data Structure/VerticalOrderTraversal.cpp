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

TreeNode *makeBinaryTree(vector<int> &A)
{
  TreeNode *root = NULL;
  for (int i = 0; i < A.size(); i++)
  {
    root = insertNode(root, A[i]);
  }
  return root;
}

vector<vector<int>> verticalOrderTraversal(TreeNode *A)
{
  vector<vector<int>> result;
  // Base case
  if (!A)
    return result;
  // Create a map of horizontalDistance, ListOfTreeNodes(at that horizontalDistance)
  map<int, vector<int>> m;

  // Create queue to do level order traversal.
  // Every item of queue contains node and horizontal distance.
  queue<pair<TreeNode *, int>> q;
  q.push(make_pair(A, 0)); // root's horizontalDistance is zero
  while (!q.empty())
  {
    // get the queue front
    pair<TreeNode *, int> front = q.front();
    q.pop();
    int currentHorizontalDistance = front.second;
    TreeNode *currentTreeNode = front.first;

    // insert current node to hash map
    m[currentHorizontalDistance].push_back(currentTreeNode->val);

    if (currentTreeNode->left != NULL)
    {
      q.push(make_pair(currentTreeNode->left, currentHorizontalDistance - 1));
    }
    if (currentTreeNode->right != NULL)
    {
      q.push(make_pair(currentTreeNode->right, currentHorizontalDistance + 1));
    }
  }
  // Traverse the map and print nodes at every horigontal distance
  for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++)
  {
    result.push_back(it->second);
  }
  return result;
}
int main()
{
  vector<int> v1{1, 2, 3, 4, 5};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;

  TreeNode *root = new TreeNode(818);
  root->right = new TreeNode(2510);
  root->right->left = new TreeNode(212);
  root->right->left->right = new TreeNode(9881);

  vector<vector<int>> v3 = verticalOrderTraversal(root);

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
