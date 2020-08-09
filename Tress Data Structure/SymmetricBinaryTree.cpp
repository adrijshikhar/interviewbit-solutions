#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

TreeNode *insertNode(TreeNode *root, int val) {
  if (root == NULL) {
    root = new TreeNode(val);
  } else if (val <= root->val) {
    root->left = insertNode(root->left, val);
  } else {
    root->right = insertNode(root->right, val);
  }
  return root;
}

TreeNode *makeBinaryTree(vector<int> &A, TreeNode *root, int i) {
  if (i < A.size()) {
    TreeNode *temp = new TreeNode(A[i]);
    root = temp;
    root->left = makeBinaryTree(A, root->left, 2 * i + 1);
    root->right = makeBinaryTree(A, root->right, 2 * i + 2);
  }

  return root;
}

void printBinaryTree(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  printBinaryTree(root->left);
  printBinaryTree(root->right);
  cout << root->val << " ";
}

bool isPalin(vector<int> &t) {
  for (int i = 0; i < t.size() / 2; i++)
    if (t[i] != t[t.size() - i - 1])
      return false;
  return true;
}

int isSymmetric(TreeNode *A) {
  queue<TreeNode *> mq;
  vector<int> temp;
  TreeNode *nullNode = new TreeNode(-1);
  mq.push(A);
  mq.push(NULL);
  while (!mq.empty()) {
    TreeNode *fr = mq.front();

    mq.pop();
    if (fr == NULL) {

      if (!isPalin(temp))
        return 0;
      temp.clear();
      if (!mq.empty())
        mq.push(NULL);
    } else {
      temp.push_back(fr->val);
      if (fr->left) {
        mq.push(fr->left);
      } else if (fr->val != -1)
        mq.push(nullNode);

      if (fr->right) {
        mq.push(fr->right);
      } else if (fr->val != -1)
        mq.push(nullNode);
    }
  }

  return true;
}

int main() {
  vector<int> v1{1, 1, -1, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;
  printBinaryTree(temp);
  cout << endl;
  int v3 = isSymmetric(v2);
  cout << v3;

  return 0;
}
