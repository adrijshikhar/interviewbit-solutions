#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *A)
{
  if (!A || !A->next)
  {
    return A;
  }

  ListNode *head = new ListNode(-1);
  head->next = A;
  ListNode *curr = head;

  ListNode *temp, *curr_inner;
  int val;
  while (curr->next->next != NULL)
  {
    if (curr->next->val == curr->next->next->val)
    {
      val = curr->next->val;

      while (val == curr->next->val && curr->next->next != NULL)
      {
        temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
      }
    }
    else
    {
      curr = curr->next;
    }
  }
  if (val == curr->next->val)
  {
    free(curr->next);
    curr->next = NULL;
  }

  return A;
}

int main()
{
  vector<int> v1{2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  ListNode *v2 = deleteDuplicates(A);
  cout << v2->val << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
