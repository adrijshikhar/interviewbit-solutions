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

void findSuccessor(TreeNode *root, int val, TreeNode **successorNode)
{

  TreeNode *temp = *successorNode;
  int diff, minDiff;
  if (root == NULL)
    return;

  diff = root->val - val;
  if (temp == NULL)
    minDiff = root->val;
  else
    minDiff = temp->val - val;

  if (diff < minDiff && diff > 0)
  {
    *successorNode = root;
  }
  if (diff <= 0)
    findSuccessor(root->right, val, successorNode);
  else if (diff > 0)
    findSuccessor(root->left, val, successorNode);
}

TreeNode *getSuccessor(TreeNode *A, int B)
{
  TreeNode *successorNode = NULL;
  findSuccessor(A, B, &successorNode);
  return successorNode;
}
int main()
{
  vector<int> v1{430, 244, 505, 103, 385, 454, 547, 91, 223, 328, 388, 436, 457, 529, 565, 58, 100, 217, 238, 256, 352, -1, 397, 433, 451, -1, 490, 526, 532, 550, 634, 55, 76, 97, -1, 214, 220, 235, 241, 247, 259, 346, 370, 391, 412, -1, -1, 445, -1, 472, 493, 508, -1, -1, 538, -1, 556, 580, 646, 10, -1, 67, 82, 94, -1, 166, -1, -1, -1, 226, -1, -1, -1, -1, 250, -1, 268, 334, 349, 367, 373, -1, 394, 409, 427, 442, 448, 463, 478, -1, 502, -1, 514, 535, 544, 553, 559, 571, 601, 637, -1, 4, 52, 61, 73, 79, 85, -1, -1, 157, 190, -1, 232, -1, 253, 262, 316, 331, 340, -1, -1, 358, -1, -1, 382, -1, -1, 403, -1, 415, -1, 439, -1, -1, -1, 460, 469, 475, 481, 499, -1, 511, 517, -1, -1, 541, -1, -1, -1, -1, 562, 568, 577, 598, 622, -1, 640, 1, 7, 34, -1, -1, 64, 70, -1, -1, -1, -1, 88, 139, 163, 175, 205, 229, -1, -1, -1, -1, 265, 286, 325, -1, -1, 337, 343, 355, 364, 376, -1, 400, 406, -1, 424, -1, -1, -1, -1, 466, -1, -1, -1, -1, 487, 496, -1, -1, -1, -1, 523, -1, -1, -1, -1, -1, -1, 574, -1, 595, -1, 616, 631, -1, 643, -1, -1, -1, -1, 16, 37, -1, -1, -1, -1, -1, -1, 118, 154, 160, -1, 172, 184, 196, 208, -1, -1, -1, -1, 274, 304, 319, -1, -1, -1, -1, -1, -1, -1, 361, -1, -1, 379, -1, -1, -1, -1, 421, -1, -1, -1, 484, -1, -1, -1, 520, -1, -1, -1, 586, -1, 613, 619, 625, -1, -1, -1, 13, 25, -1, 46, 109, 136, 145, -1, -1, -1, 169, -1, 181, 187, 193, 199, -1, 211, 271, 280, 301, 310, -1, 322, -1, -1, -1, -1, 418, -1, -1, -1, -1, -1, 583, 592, 610, -1, -1, -1, -1, 628, -1, -1, 19, 28, 40, 49, 106, 112, 127, -1, 142, 151, -1, -1, 178, -1, -1, -1, -1, -1, -1, 202, -1, -1, -1, -1, 277, 283, 298, -1, 307, 313, -1, -1, -1, -1, -1, -1, 589, -1, 607, -1, -1, -1, -1, 22, -1, 31, -1, 43, -1, -1, -1, -1, -1, 115, 121, 130, -1, -1, 148, -1, -1, -1, -1, -1, -1, -1, -1, -1, 289, -1, -1, -1, -1, -1, -1, -1, 604, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 124, -1, 133, -1, -1, -1, 292, -1, -1, -1, -1, -1, -1, -1, 295, -1, -1};
  TreeNode *temp;

  TreeNode *v2 = makeBinaryTree(v1);
  cout << v2 << endl;
  temp = v2;
  temp = getSuccessor(temp, 454);
  cout << temp->val;
  return 0;
}

//https://gist.github.com/mycodeschool/6515e1ec66482faf9d79
