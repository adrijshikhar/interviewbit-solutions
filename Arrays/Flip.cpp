#include <bits/stdc++.h>

using namespace std;

vector<int> flip(string A)
{
  int flips = -1, maxFlips = INT_MIN, l = 0, r = 0, c = 0;
  vector<int> B;

  for (auto i = 0; i < A.size(); i++)
  {
    if (A[i] == 48)
    {
      if (flips < 0)
      {
        flips = 0;
        c = i;
      }
      flips++;

      if (maxFlips < flips)
      {
        maxFlips = flips;
        l = c + 1;
        r = i + 1;
      }
    }
    else
    {
      flips--;
    }
  }
  if (l != 0)
  {
    B.push_back(l);
    B.push_back(r);
  }

  return B;
}

int main()
{
  string A = "010";

  vector<int> v2 = flip(A);

  for (auto i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }
  return 0;
}
