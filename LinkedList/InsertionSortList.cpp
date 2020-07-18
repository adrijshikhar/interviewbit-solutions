#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *Insert(ListNode *A, ListNode *x)
{
  if (A == NULL)
  {
    A = x;
    return A;
  }
  if (x->val < A->val)
  {
    x->next = A;
    A = x;
    return A;
  }
  ListNode *temp = A;
  while (temp != NULL && temp->next != NULL && temp->next->val < x->val)
    temp = temp->next;

  ListNode *next = NULL;
  if (temp != NULL)
    next = temp->next;
  temp->next = x;
  x->next = next;

  return A;
}

ListNode *insertionSortList(ListNode *A)
{
  ListNode *B = NULL, *x = A, *save = A->next;
  while (x != NULL)
  {
    x->next = NULL;
    B = Insert(B, x);

    x = save;
    if (x != NULL)
      save = x->next;
  }
  return B;
}

int main()
{
  vector<int> v1{2, 3, 4, 1, 2, 1};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  ListNode *v2 = insertionSortList(A);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
