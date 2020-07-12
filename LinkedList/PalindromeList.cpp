#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int lPalin(ListNode *A)
{
  ListNode *slow = A;
  stack<int> s;
  while (slow != NULL)
  {
    s.push(slow->val);
    slow = slow->next;
  }

  while (A != NULL)
  {
    int test = s.top();
    s.pop();
    if (A->val != test)
    {
      return 0;
    }
    A = A->next;
  }
  return 1;
}

int main()
{
  vector<int> v1{
      1, 2, 3, 4, 5, 6, 7};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  int v2 = lPalin(A);
  cout << v2 << endl;
  temp = A;
  while (temp->next != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
