#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *A)
{

  if (A == NULL || A->next == NULL)
  {
    return NULL;
  }

  ListNode *slow = A;
  ListNode *fast = A;

  while (slow != NULL && fast != NULL)
  {
    slow = slow->next;
    if (fast->next == NULL)
    {
      return NULL;
    }
    else
    {
      fast = (fast->next)->next;
    }
    if (slow == fast)
    {
      break;
    }
  }

  if (slow == NULL || fast == NULL)
  {
    return NULL;
  }

  ListNode *curr = A;
  while (curr != slow)
  {
    curr = curr->next;
    slow = slow->next;
  }

  return curr;
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
  temp->next = A;
  ListNode *v2 = detectCycle(A);
  cout << v2->val << endl;

  return 0;
}
