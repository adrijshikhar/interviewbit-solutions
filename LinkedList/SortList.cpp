#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *A, ListNode *B) {
  if (A == NULL) {
    return B;
  }
  if (B == NULL) {
    return A;
  }

  ListNode *head = NULL;

  if (A->val < B->val) {
    head = A;
    A = A->next;
  } else {
    head = B;
    B = B->next;
  }

  ListNode *temp = head;

  while (A != NULL && B != NULL) {
    if (A->val < B->val) {
      temp->next = A;
      A = A->next;
    } else {
      temp->next = B;
      B = B->next;
    }
    temp = temp->next;
  }

  if (A != NULL) {
    temp->next = A;
  } else {
    temp->next = B;
  }

  return head;
}
ListNode *sortList(ListNode *A) {

  ListNode *head = A;

  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *start = A;
  ListNode *end = A->next;

  while (end != NULL && end->next != NULL) {
    start = start->next;
    end = (end->next)->next;
  }

  end = start->next;
  start->next = NULL;

  return merge(sortList(head), sortList(end));
}

int main() {
  vector<int> v1{2, 3, 4, 1, 2, 1};
  ListNode *temp = new ListNode(v1[0]);
  ListNode *A = temp;
  ListNode *prevTemp = temp;
  for (int i = 1; i < v1.size(); i++) {
    temp = new ListNode(v1[i]);
    prevTemp->next = temp;
    prevTemp = temp;
  }

  ListNode *v2 = sortList(A);
  cout << v2 << endl;
  temp = v2;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }

  return 0;
}
