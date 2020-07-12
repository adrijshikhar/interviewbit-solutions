#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &A)
{
  int i = 0, j = 0, flag = 0;
  if (A.size() == 0)
  {
    return 0;
  }

  while (i < A.size() - 1)
  {
    if (A[i] == A[i + 1])
    {
      flag = 1;
    }
    else
    {
      flag = 0;
      i++;
    }

    if (flag)
    {
      A.erase(A.begin() + i);
    }

    // if (A[i] == A[i + 1])
    // {
    //   j = i + 1;
    //   int num = A[i];
    //   while (num == A[j] && j < A.size())
    //   {
    //     A.erase(A.begin() + j);
    //   }
    // }
  }

  return A.size();
}

int main()
{
  vector<int> v1{};
  int v3 = removeDuplicates(v1);
  cout << v3 << endl;
  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }

  return 0;
}
