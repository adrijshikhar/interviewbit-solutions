#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *subtract(ListNode *A)
{
  ListNode *curr = A;
  stack<int> s;
  while (curr != NULL)
  {
    s.push(curr->val);
    curr = curr->next;
  }
  curr = A;
  int n = s.size() / 2;
  for (int i = 0; i < n; i++)
  {
    int v = s.top();
    s.pop();
    curr->val = v - curr->val;
    curr = curr->next;
  }

  return A;
}

int main()
{
  vector<int> v1{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  prevTemp->next = NULL;
  ListNode *v2 = subtract(A);

  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
