#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partitionList(ListNode *A, int B)
{
  ListNode *lessCurr = new ListNode(-1), *greaterCurr = new ListNode(-1), *curr = A;
  ListNode *lessHead = lessCurr, *greaterHead = greaterCurr;
  if (curr == NULL)
  {
    return A;
  }

  while (curr != NULL)
  {
    if (curr->val < B)
    {
      lessCurr->next = curr;
      lessCurr = lessCurr->next;
    }
    else
    {
      greaterCurr->next = curr;
      greaterCurr = greaterCurr->next;
    }
    curr = curr->next;
  }
  lessCurr->next = greaterHead->next;
  greaterCurr->next = NULL;
  return lessHead->next;
}

int main()
{
  vector<int> v1{
      1, 2, 3, 4, 5};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  ListNode *v2 = partitionList(A, 5);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
