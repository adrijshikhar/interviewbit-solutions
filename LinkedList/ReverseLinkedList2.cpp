#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
  ListNode *prev = NULL;
  ListNode *curr = head;
  while (curr)
  {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

ListNode *reverseBetween(ListNode *A, int B, int C)
{
  ListNode *prev = NULL, *next = NULL, *revs = NULL, *curr = A, *end = NULL;
  if (B == C)
  {
    return A;
  }

  int i = 1;
  while (curr && i <= C)
  {
    if (i < B)
    {
      prev = curr;
    }
    if (i == B)
    {
      revs = curr;
    }

    if (i == C)
    {
      end = curr;
      next = curr->next;
    }
    curr = curr->next;
    i++;
  }
  end->next = NULL;
  end = reverse(revs);

  if (prev)
  {
    prev->next = end;
  }
  else
  {
    A = end;
  }
  revs->next = next;

  return A;
}

int main()
{
  vector<int> v1{1, 2, 3, 4, 5, 6};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  ListNode *v2 = reverseBetween(A, 2, 5);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
