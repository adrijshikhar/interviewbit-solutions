#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *link;
};

int main()
{
  node *A = nullptr;
  node *temp = new node();
  temp->data = 3;
  temp->link = nullptr;
  cout << A;
  A = temp;
  cout << A->data;
  return 0;
}
