#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

TreeNode *insertNode(TreeNode *root, int val) {
  if (root == NULL)
    root = new TreeNode(val);
  else if (val <= root->val)
    root->left = insertNode(root->left, val);
  else
    root->right = insertNode(root->right, val);
  return root;
}

TreeNode *makeBinaryTree(vector<int> &A) {
  TreeNode *root = NULL;
  for (int i = 0; i < A.size(); i++) {
    root = insertNode(root, A[i]);
  }
  return root;
}

void findSuccessor(TreeNode *root, int val, TreeNode **successorNode) {

  TreeNode *temp = *successorNode;
  int diff, minDiff;
  if (root == NULL)
    return;

  diff = root->val - val;
  if (temp == NULL)
    minDiff = root->val;
  else
    minDiff = temp->val - val;

  if (diff < minDiff && diff > 0) {
    *successorNode = root;
  }
  if (diff <= 0)
    findSuccessor(root->right, val, successorNode);
  else if (diff > 0)
    findSuccessor(root->left, val, successorNode);
}

TreeNode *getSuccessor(TreeNode *A, int B) {
  TreeNode *successorNode = NULL;
  findSuccessor(A, B, &successorNode);
  return successorNode;
}

int isSameTree(TreeNode *A, TreeNode *B) {
  if (A == NULL && B == NULL)
    return 1;
  if ((A == NULL && B != NULL) || (B == NULL && A != NULL))
    return 0;

  if (A->val == B->val) {
    int left = isSameTree(A->left, B->left);
    int right = isSameTree(A->right, B->right);
    if (left == 1 && right == 1)
      return 1;
    return 0;
  }

  return 0;
}

int main() {
  vector<int> v1{1, 2, 3};
  vector<int> v3{1, 2, 3};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  TreeNode *v4 = makeBinaryTree(v3);
  int t = isSameTree(v2, v4);
  cout << t;
  return 0;
}
