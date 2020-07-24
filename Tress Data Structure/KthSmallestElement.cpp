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

void traverseBST(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &pq)
{
  if (root == NULL || root->val == -1)
  {
    return;
  }
  pq.push(root->val);
  traverseBST(root->left, pq);
  traverseBST(root->right, pq);
}

int kthsmallest(TreeNode *A, int B)
{
  priority_queue<int, vector<int>, greater<int>> pq;
  traverseBST(A, pq);
  int i = 0, num;

  while (i < B && !pq.empty())
  {
    num = pq.top();
    pq.pop();
    cout << num << " ";
    i++;
  }
  return num;
}

int main()
{
  vector<int> v1{2, 1, 3, -1, -1, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;
  int val = kthsmallest(temp, 2);
  cout << val;
  return 0;
}
