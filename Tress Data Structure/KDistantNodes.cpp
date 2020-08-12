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

TreeNode *makeBinaryTree(vector<int> &A, TreeNode *root, int i) {
  if (i < A.size()) {
    if (A[i] == -1) {
      return NULL;
    }

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
  cout << root->val << " ";
  printBinaryTree(root->left);
  printBinaryTree(root->right);
}

void go_down(TreeNode *root, int h, vector<int> &a) {
  if (!root)
    return;
  if (h == 0) {
    a.push_back(root->val);
    return;
  }
  go_down(root->left, h - 1, a);
  go_down(root->right, h - 1, a);
}

int traverse(TreeNode *root, int target, int k, vector<int> &a) {
  if (!root)
    return 0;
  if (root->val == target) {
    go_down(root, k, a);
    return 1;
  }
  int l = traverse(root->left, target, k, a);
  if (l && l <= k) {
    if (l == k)
      a.push_back(root->val);
    else
      go_down(root->right, k - l - 1, a);
    return l + 1;
  }
  int r = traverse(root->right, target, k, a);
  if (r && r <= k) {
    if (r == k)
      a.push_back(root->val);
    else
      go_down(root->left, k - r - 1, a);
    return r + 1;
  }
  return 0;
}

vector<int> kDistantNodes(TreeNode *root, int target, int k) {
  vector<int> a;
  traverse(root, target, k, a);
  sort(a.begin(), a.end());
  return a;
}

int main() {
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1, v2, 0);

  cout << v2 << endl;
  temp = v2;

  printBinaryTree(v2);
  cout << endl;
  int k = 2, target = 3;
  vector<int> v3 = kDistantNodes(v2, target, k);
  for (int i = 0; i < v3.size(); i++) {
    cout << v3[i] << " ";
  }

  return 0;
}
