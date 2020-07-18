#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reorderList(ListNode *A)
{

  if (!A || !A->next)
    return A;

  //find middle: O(n)
  ListNode *slw = A, *fst = A;
  while (fst->next && fst->next->next)
  {
    slw = slw->next;
    fst = fst->next->next;
  }

  // cut from the middle and reverse the second half: O(n)
  ListNode *mid = slw, *preCurr = slw->next;
  while (preCurr->next)
  {
    ListNode *curr = preCurr->next;
    preCurr->next = curr->next;
    curr->next = mid->next;
    mid->next = curr;
  }

  // merge two lists: O(n)
  ListNode *p1 = A, *p2 = mid->next;
  while (p1 != mid)
  {
    mid->next = p2->next;
    p2->next = p1->next;
    p1->next = p2;
    p1 = p2->next;
    p2 = mid->next;
  }

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

  ListNode *v2 = reorderList(A);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
