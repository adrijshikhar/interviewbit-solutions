#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *A, int B)
{
  ListNode *head = A, *curr = A;
  stack<int> s;
  int i = 0;
  while (head->next != NULL)
  {
    s.push(head->val);
    head = head->next;
  }
  s.push(head->val);
  if (B % s.size() == 0)
  {
    return A;
  }
  head->next = A;
  B = B % s.size();
  i = s.size() - B;
  int j = 1;
  while (curr != NULL)
  {
    if (i == j)
    {
      break;
    }
    curr = curr->next;
    j++;
  }
  head = curr->next;
  curr->next = NULL;
  return head;
}

int main()
{
  vector<int> v1{
      1};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++)
  {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }
  ListNode *v2 = rotateRight(A, 1);
  cout << v2 << endl;
  temp = v2;
  // while (temp != NULL)
  // {
  //   cout << temp->val << " ";
  //   temp = temp->next;
  // }

  return 0;
}
