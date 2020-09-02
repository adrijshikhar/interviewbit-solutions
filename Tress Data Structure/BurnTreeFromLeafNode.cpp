#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

// Utility function to print the sequence of burning nodes
int burnTreeUtil(TreeNode *root, int target, queue<TreeNode *> &q) {
  // Base condition
  if (root == NULL) {
    return 0;
  }

  // Condition to check whether target
  // TreeNode is found or not in a tree
  if (root->val == target) {
    cout << root->val << endl;
    if (root->left != NULL) {
      q.push(root->left);
    }
    if (root->right != NULL) {

      q.push(root->right);
    }

    // Return statements to prevent
    // further function calls
    return 1;
  }

  int a = burnTreeUtil(root->left, target, q);

  if (a == 1) {
    int qsize = q.size();

    // Run while loop until size of queue
    // becomes zero
    while (qsize--) {
      TreeNode *temp = q.front();

      // Printing of burning TreeNodes
      cout << temp->val << " , ";
      q.pop();

      // Check if condition for left subtree
      if (temp->left != NULL)
        q.push(temp->left);

      // Check if condition for right subtree
      if (temp->right != NULL)
        q.push(temp->right);
    }

    if (root->right != NULL)
      q.push(root->right);

    cout << root->val << endl;

    // Return statement it prevents further
    // further function call
    return 1;
  }

  int b = burnTreeUtil(root->right, target, q);

  if (b == 1) {
    int qsize = q.size();
    // Run while loop until size of queue
    // becomes zero

    while (qsize--) {
      TreeNode *temp = q.front();

      // Printing of burning TreeNodes
      cout << temp->val << " , ";
      q.pop();

      // Check if condition for left subtree
      if (temp->left != NULL)
        q.push(temp->left);

      // Check if condition for left subtree
      if (temp->right != NULL)
        q.push(temp->right);
    }

    if (root->left != NULL)
      q.push(root->left);

    cout << root->val << endl;

    // Return statement it prevents further
    // further function call
    return 1;
  }
  return 0;
}

// Function will print the sequence of burning TreeNodes
void burnTree(TreeNode *root, int target) {
  queue<TreeNode *> q;

  // Function call
  burnTreeUtil(root, target, q);

  // While loop runs unless queue becomes empty
  while (!q.empty()) {
    int qSize = q.size();
    while (qSize > 0) {
      TreeNode *temp = q.front();

      // Printing of burning TreeNodes
      cout << temp->val;
      // Insert left child in a queue, if exist
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      // Insert right child in a queue, if exist
      if (temp->right != NULL) {
        q.push(temp->right);
      }

      if (q.size() != 1)
        cout << " , ";

      q.pop();
      qSize--;
    }
    cout << endl;
  }
}

int main() {
  /*      10
         /  \
        12  13
            / \
           14 15
          / \ / \
        21 22 23 24

      Let us create Binary Tree as shown
      above */

  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(12);
  root->right = new TreeNode(13);

  root->right->left = new TreeNode(14);
  root->right->right = new TreeNode(15);

  root->right->left->left = new TreeNode(21);
  root->right->left->right = new TreeNode(22);
  root->right->right->left = new TreeNode(23);
  root->right->right->right = new TreeNode(24);
  int targetNode = 14;

  // Function call
  burnTree(root, targetNode);

  return 0;
}
