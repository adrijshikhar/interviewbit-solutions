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

public:
  SegmentTrees(vector<int> &A) : head()
  {
    queue<TreeNode *> q;
    TreeNode *t1, *t2, *h;
    int n = A.size(), c = 0;
    for (int i = 0; i < n; i++)
      q.push(new TreeNode(A[i]));
    if (n % 2 == 1)
      q.push(NULL);

    while (!q.empty())
    {
      t1 = q.front();
      q.pop();
      t2 = q.front();
      q.pop();
      if (t2)
        c = t1->val + t2->val;
      else
        c = t1->val;

      h = new TreeNode(c);
      h->left = t1;
      h->right = t2;
      if (!q.empty())

        q.push(h);
    }
    head = h;
  }
  void showHead()
  {
    cout << head << endl;
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
};

int main()
{
  vector<int> v1{1, 2, 3, 4};
  SegmentTrees *temp = new SegmentTrees(v1);
  temp->showHead();
  temp->printLevelOrder();
  return 0;
}
