#include <bits/stdc++.h>

using namespace std;

int compareString(string A, string B)
{
  int flag = 1;
  for (int i = 0; i < A.size(); i++)
  {
    if (B[i] < A[i])
    {
      flag = 0;
      break;
    }

    if (B[i] > A[i])
    {
      break;
    }
  }
  return flag;
}

string nextSimilarNumber(string A)
{
  string B = A, C;

  int i, j;
  for (i = B.size() - 1; i > 0; i--)
  {
    if (B[i] > B[i - 1])
    {
      break;
    }
  }
  if (i == 0)
  {
    return "-1";
  }

  int x = B[i - 1], smallest = i;
  for (j = i + 1; j < B.size(); j++)
    if (B[j] > x && B[j] < B[smallest])
      smallest = j;

  swap(B[smallest], B[i - 1]);
  sort(B.begin() + i, B.end());
  return B;
}

int main()
{
  string v1 = "740948";
  string v2 = nextSimilarNumber(v1);
  cout << v2 << " ";
  return 0;
}
