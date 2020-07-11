#include <bits/stdc++.h>
#include <string.h>

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

  string C;
  int start = 0;
  for (int i = 0; i < B.size(); i++)
  {
    if (B[i] == ' ')
    {
      start++;
    }
    else
    {
      break;
    }
  }

  for (int j = start; j < B.size(); j++)
  {
    C.push_back(A[j]);
  }

  return C;
}
string reverseString(string A)
{
  string B = removeTrailingSpaces(A), word, C;
  int s = B.size();
  if (B[s - 1] == '.')
  {
    s -= 1;
  }

  int high = s - 1;
  string res = "";

  for (int i = high; i >= 0; i--)
  {
    if (B[i] == ' ' && B[i + 1] != ' ')
    {
      for (int j = i + 1; (B[j] != ' ' && j <= high); j++)
      {
        res.push_back(B[j]);
      }
      res.push_back(' ');
    }
  }
  for (int i = 0; (B[i] != ' ' && i <= high); i++)
  {
    res.push_back(B[i]);
  }
  if (res.size() == 0 && high + 1 > 0)
  {
    for (int i = 0; i <= high; i++)
    {
      res.push_back(B[0]);
    }
  }
  return res;
}

int main()
{
  string v1 = "                             sn                                       myq igjgip iwfcqq";
  string v2 = reverseString(v1);
  cout << v2;

  return 0;
}
