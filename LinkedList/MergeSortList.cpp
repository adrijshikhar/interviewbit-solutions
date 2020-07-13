#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *A, ListNode *B)
{
  ListNode *prev = A, *currA = A, *currB = B, *head = new ListNode(-1);
  if (currA->val > currB->val)
  {
    prev = currB;
    head = currB;
    currB = currB->next;
  }
  else
  {
    prev = currA;
    head = currA;
    currA = currA->next;
  }

  while (currA && currB)
  {
    if (currA->val > currB->val)
    {
      prev->next = currB;
      prev = prev->next;
      if (currB)
      {
        currB = currB->next;
      }
    }
    else
    {
      prev->next = currA;
      prev = prev->next;
      if (currA)
      {
        currA = currA->next;
      }
    }
  }
  if (currA)
  {
    prev->next = currA;
  }
  if (currB)
  {
    prev->next = currB;
  }
  return head;
}

int main()
{
  vector<int> v1{8, 10, 12};
  vector<int> v2{4, 7, 11};

  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  temp = new ListNode(v2[0]);
  ListNode *B = temp;
  prevTemp = temp;
  for (int i = 1; i < v2.size(); i++)
  {
    temp = new ListNode(v2[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  ListNode *v3 = mergeTwoLists(A, B);

  temp = v3;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
