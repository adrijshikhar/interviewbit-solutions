#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseLL(ListNode *head, ListNode *endLL)
{
  ListNode *prev = NULL, *curr = head, *temp;

  while (curr != endLL)
  {
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return curr;
}

ListNode *reverseList(ListNode *A)
{
  ListNode *curr = A, *next = NULL, *prev = NULL;

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  if (next != NULL)
  {
    A->next = reverseList(next);
  }
  return prev;
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
  ListNode *v2 = reverseList(A);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
