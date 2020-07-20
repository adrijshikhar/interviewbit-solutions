#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> A, int B)
{
  sort(A.begin(), A.end());
  vector<vector<int>> res;
  auto size = A.size();
  for (auto i = 0; i < size - 3; ++i)
  {
    if (i > 0 && A[i] == A[i - 1])
      continue;
    for (auto j = i + 1; j < size - 2; ++j)
    {
      if (j > i + 1 && A[j] == A[j - 1])
        continue;

      int ptr1 = j + 1, ptr2 = size - 1;
      while (ptr1 < ptr2)
      {
        auto sum = A[i] + A[j] + A[ptr1] + A[ptr2];
        if (sum == B)
        {
          vector<int> temp;
          temp.emplace_back(A[i]);
          temp.emplace_back(A[j]);
          temp.emplace_back(A[ptr1]);
          temp.emplace_back(A[ptr2]);
          res.emplace_back(temp);
          ++ptr1;
          while (ptr1 < ptr2 && A[ptr1] == A[ptr1 - 1])
            ++ptr1;
        }
        else if (sum > B)
          --ptr2;
        else if (sum < B)
          ++ptr1;
      }
    }
  }
  return res;
}

int main()
{
  vector<int> v1{9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2};
  vector<vector<int>> v2 = fourSum(v1, 0);
  for (int i = 0; i < v2.size(); i++)
  {
    for (int j = 0; j < v2[i].size(); j++)
    {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
