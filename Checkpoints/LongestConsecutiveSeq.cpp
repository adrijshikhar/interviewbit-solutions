#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(const vector<int> &A)
{
  vector<int> B = A;
  sort(B.begin(), B.end());

  int len = 0, maxLen = 0;
  for (int i = 1; i < B.size(); i++)
  {
    if (B[i] - B[i - 1] == 1)
    {
      len++;
      if (len > maxLen)
      {
        maxLen = len;
      }
    }
    else if (B[i] == B[i - 1])
      continue;
    else
    {
      len = 0;
    }
  }
  return maxLen + 1;
}

int main()
{
  vector<int> v1{100, 4, 200, 1, 3, 2};
  int v2 = longestConsecutive(v1);

  cout << v2 << " ";

  return 0;
}
