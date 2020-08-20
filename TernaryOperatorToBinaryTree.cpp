#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  char val;
  TreeNode *left, *right;
  TreeNode(char x) : val(x), right(NULL), left(NULL) {}
};

TreeNode *stringtotree(string A, int &i) {

  TreeNode *root = new TreeNode(A[i]);
  if (A.size() - 1 == i)
    return root;
  i++;
  if (A[i] == '?') {
    i++;
    root->left = stringtotree(A, i);
    i++;
    root->right = stringtotree(A, i);
  }
  return root;
}

void printBinaryTree(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  printBinaryTree(root->left);
  printBinaryTree(root->right);
}

int main() {
  string v1 = "a?b?c:d:e";
  int i = 0;
  TreeNode *v3 = stringtotree(v1, i);
  printBinaryTree(v3);
  return 0;
}
