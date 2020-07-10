#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string A)
{
  int low = 0, high = 0, s = A.size();
  string ans;
  int maxLen = 1, maxLenIndex = 0;
  if (s == 1)
  {
    return A;
  }

  for (int i = 0; i < A.size() - 2; i++)
  {
    low = i;
    high = i + 2;
    if (A[low] == A[high])
    {
      while (0 <= low && high <= s - 1)
      {
        if (A[low] != A[high])
        {
          break;
        }

        low--;
        high++;
      }
      low++;
      high--;
      if (maxLen < high - low + 1)
      {
        maxLen = high - low + 1;
        maxLenIndex = low;
      }
    }
  }
  for (int i = 0; i < A.size() - 1; i++)
  {
    low = i;
    high = i + 1;
    if (A[low] == A[high])
    {
      while (0 <= low && high <= s - 1)
      {
        if (A[low] != A[high])
        {
          break;
        }

        low--;
        high++;
      }
      low++;
      high--;
      if (maxLen < high - low + 1)
      {
        maxLen = high - low + 1;
        maxLenIndex = low;
      }
    }
  }
  cout << maxLenIndex << " " << maxLen;
  for (int k = maxLenIndex; k < maxLenIndex + maxLen; k++)
  {
    ans.push_back(A[k]);
  }

  return ans;
}

int main()
{
  string v1 = "ac";
  string v2 = longestPalindrome(v1);
  cout << v2;

  return 0;
}
