#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), right(NULL), left(NULL) {}
};

class SegmentTrees
{
private:
  TreeNode *head;
  vector<int> values;
  vector<int> tree;

public:
  SegmentTrees(vector<int> &A) : head()
  {
    values = A;
    int s = 2 * (values.size()) - 1;
    tree.resize(s);
    build(0, 0, values.size() - 1);
  }
  void build(int i, int start, int end)
  {
    if (start == end)
      tree[i] = values[start];
    else
    {
      int mid = start + (end - start) / 2;
      build(2 * i + 1, start, mid);
      build(2 * i + 2, mid + 1, end);
      tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
  }
  void showHead()
  {
    cout << head << endl;
  }
  vector<int> getTree()
  {
    return tree;
  }
  TreeNode *getHead()
  {
    return head;
  }
  void printLevelOrder()
  {
    queue<TreeNode *> mq;
    mq.push(head);
    mq.push(NULL);
    while (!mq.empty())
    {
      TreeNode *fr = mq.front();
      mq.pop();
      if (fr == NULL)
      {
        cout << endl;
        if (!mq.empty())
          mq.push(NULL);
      }
      else
      {
        cout << fr->val << " ";
        if (fr->left)
          mq.push(fr->left);

        if (fr->right)
          mq.push(fr->right);
      }
    }
  }
  void insert(int val, int position)
  {
    int n = values.size();
    if (position >= n)
      throw "out of bounds";

    update(0, 0, values.size() - 1, position, val);
  }

  void update(int i, int start, int end, int idx, int val)
  {
    if (start == end)
    {
      values[idx] += val;
      tree[i] += val;
    }
    else
    {
      int mid = (start + end) / 2;
      if (start <= idx and idx <= mid)
        update(2 * i + 1, start, mid, idx, val);
      else
        update(2 * i + 2, mid + 1, end, idx, val);
      tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
  }

  TreeNode *insertNodes(TreeNode *root, int i)
  {
    if (i < tree.size())
    {
      TreeNode *temp = new TreeNode(tree[i]);
      root = temp;
      root->left = insertNodes(root->left, 2 * i + 1);
      root->right = insertNodes(root->right, 2 * i + 2);
    }

    return root;
  }

  void makeBinaryTree()
  {
    TreeNode *root = insertNodes(root, 0);
    head = root;
  }
};

int main()
{
  vector<int> v1{1, 2, 3, 4, 5};
  SegmentTrees *temp = new SegmentTrees(v1);
  temp->showHead();
  vector<int> t = temp->getTree();
  for (int i = 0; i < t.size(); i++)
  {
    cout << t[i] << " ";
  }
  cout << endl;
  temp->insert(6, 2);
  temp->makeBinaryTree();
  temp->printLevelOrder();
  return 0;
}
