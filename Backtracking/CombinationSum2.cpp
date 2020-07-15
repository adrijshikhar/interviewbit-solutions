#include <bits/stdc++.h>

using namespace std;

void backtrack(int start, vector<int> &row, int sum, set<vector<int>> &res, vector<int> &A, int B)
{
  if (sum >= B)
  {
    if (sum == B)
      res.insert(row);
    return;
  }

  if (start == A.size())
    return;

  row.push_back(A[start]);
  sum += A[start];
  backtrack(start + 1, row, sum, res, A, B);
  sum -= row[row.size() - 1];
  row.pop_back();
  backtrack(start + 1, row, sum, res, A, B);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
  set<vector<int>> res;
  vector<int> row;
  sort(A.begin(), A.end());

  backtrack(0, row, 0, res, A, B);
  vector<vector<int>> v(res.begin(), res.end());
  return v;
}

int main()
{
  vector<int> v1{10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> v2 = combinationSum(v1, 8);

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
