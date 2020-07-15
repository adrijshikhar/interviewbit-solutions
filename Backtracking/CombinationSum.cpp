#include <bits/stdc++.h>

using namespace std;

void backtrack(int start, vector<int> &row, int sum, vector<vector<int>> &res, vector<int> &A, int B)
{
  if (sum >= B)
  {
    if (sum == B)
      res.push_back(row);
    return;
  }

  if (start == A.size())
    return;

  row.push_back(A[start]);
  sum += A[start];
  backtrack(start, row, sum, res, A, B);
  sum -= row[row.size() - 1];
  row.pop_back();
  backtrack(start + 1, row, sum, res, A, B);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
  vector<vector<int>> res;
  vector<int> row, a;
  sort(A.begin(), A.end());

  a.push_back(A[0]);
  for (auto i = 1; i < A.size(); ++i)
    if (A[i - 1] != A[i])
      a.push_back(A[i]);

  backtrack(0, row, 0, res, a, B);

  return res;
}

int main()
{
  vector<int> v1{1, 2, 3, 4};
  vector<vector<int>> v2 = combinationSum(v1, 4);

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
