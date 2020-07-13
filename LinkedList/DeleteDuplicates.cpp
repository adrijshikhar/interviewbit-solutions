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
  ListNode *curr = A;
  if (curr == NULL)
  {
    return A;
  }

  ListNode *temp;
  while (curr->next != NULL)
  {
    if (curr->val == curr->next->val)
    {
      temp = curr->next->next;
      free(curr->next);
      curr->next = temp;
    }
    else
    {
      curr = curr->next;
    }
  }
  return A;
}

int main()
{
  vector<int> v1{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
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
  ListNode *v2 = deleteDuplicates(A);

  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
