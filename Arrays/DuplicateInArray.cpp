#include <bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &A)
{
  int n = A.size();
  vector<int> B(n - 1, 0);
  for (int i = 0; i < n; i++)
  {
    B[A[i] - 1]++;
    if (B[A[i] - 1] > 1)
    {
      return A[i];
    }
  }
  return -1;
}

int main()
{
  vector<int> A{3, 4, 1, 4, 1};

  int v2 = repeatedNumber(A);

  cout << v2 << " ";
  return 0;
}
