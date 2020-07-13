#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *A, int B)
{
  ListNode *head = A;
  stack<int> s;
  int i = 0;
  while (head != NULL)
  {
    s.push(head->val);
    head = head->next;
  }
  i = s.size() - B;
  if (i <= 0)
  {
    A = A->next;
    return A;
  }
  int j = 0;
  ListNode *head2 = new ListNode(-1), *temp;
  head2->next = A;
  while (head2 != NULL)
  {
    if (j == i)
    {
      head2->next = head2->next->next;
      break;
    }

    head2 = head2->next;
    j++;
  }
  return A;
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
  ListNode *v2 = removeNthFromEnd(A, 10);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
