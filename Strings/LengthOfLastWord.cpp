#include <bits/stdc++.h>

using namespace std;
string removeTrailingSpaces(string A)
{
  string B;
  int end = A.size() - 1;
  for (int i = A.size() - 1; i >= 0; i--)
  {
    if (A[i] == ' ')
    {
      end--;
    }
    else
    {
      break;
    }
  }
  for (int j = 0; j <= end; j++)
  {
    B.push_back(A[j]);
  }
  return B;
}
int lengthOfLastWord(string A)
{
  string B = removeTrailingSpaces(A);
  int len = 0, s = B.size();
  if (B[s - 1] == '.')
  {
    s -= 1;
  }

  for (int i = s - 1; i >= 0; i--)
  {
    if (B[i] != ' ')
    {
      len++;
    }
    else
    {
      break;
    }
  }

  return len;
}

int main()
{
  string v1 = " H Kv Scy GX eUKm FwiY RGjNRDz ZXYNVdNSfKjf nMX ";
  int v2 = lengthOfLastWord(v1);
  cout << v2;

  return 0;
}
