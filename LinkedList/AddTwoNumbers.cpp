#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *A, ListNode *B)
{
  ListNode *currA = A, *currB = B, *head = NULL, *temp = new ListNode(-1);
  head = temp;
  int pointVal = 0;

  while (currA != NULL && currB != NULL)
  {
    pointVal = currA->val + currB->val;
    if (pointVal >= 10)
    {
      temp->next = new ListNode(pointVal - 10);

      if (currA->next != NULL)
      {
        currA->next->val += 1;
      }
      else if (currB->next != NULL)
      {
        currB->next->val += 1;
      }
      else
      {
        temp->next->next = new ListNode(1);
      }
    }
    else
    {
      temp->next = new ListNode(pointVal);
    }

    temp = temp->next;
    currA = currA->next;
    currB = currB->next;
  }
  while (currA != NULL)
  {
    if (currA->val >= 10)
    {
      currA->val = 0;
      if (currA->next != NULL)
      {
        currA->next->val += 1;
      }
      else
      {
        currA->next = new ListNode(1);
      }
    }
    temp->next = currA;
    temp = temp->next;
    currA = currA->next;
  }

  while (currB != NULL)
  {
    if (currB->val >= 10)
    {
      currB->val = 0;
      if (currB->next != NULL)
      {
        currB->next->val += 1;
      }
      else
      {
        currB->next = new ListNode(1);
      }
    }
    temp->next = currB;
    temp = temp->next;
    currB = currB->next;
  }

  return head->next;
}

int main()
{
  vector<int> v1{1};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  vector<int> v3{9, 9, 9};
  temp = new ListNode(v3[0]);
  ListNode *B = temp;
  prevTemp = temp;
  for (int i = 1; i < v3.size(); i++)
  {
    temp = new ListNode(v3[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  ListNode *v2 = addTwoNumbers(A, B);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
