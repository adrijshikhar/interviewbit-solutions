#include <bits/stdc++.h>

using namespace std;

int kthsmallest(const vector<int> &A, int B)
{
  int ans = 0, s = A.size();
  vector<int> C = A;
  make_heap(C.begin(), C.end());

  for (int i = 0; i < s - B; i++)
  {
    pop_heap(C.begin(), C.end());
    C.pop_back();
  }
  ans = C.front();
  return ans;
}

int main()
{
  vector<int> v1{
      1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int v2 = kthsmallest(v1, 3);

  cout << v2;

  return 0;
}
