#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(int A, vector<int> &B)
{
  vector<int> s(A + 1, 0);

  for (int i = 0; i < B.size(); i++)
  {
    s[i + 1] = s[i] + B[i];
  }
  long long int ans = 0;
  if (s[A] % 3 == 0)
  {
    long long int u = s[A] / 3, v = 2 * s[A] / 3;
    long long int cnt = 0;
    for (int i = 1; i < A; i++)
    {
      if (s[i] == v)
        ans += cnt;

      if (s[i] == u)
        cnt++;
    }
  }
  return ans;
}
int main()
{
  vector<int> v1{34, 35, 27, 42, 5, 28, 39, 20, 28};
  int v2 = longestConsecutive(v1.size(), v1);

  cout << v2 << " ";

  return 0;
}
