#include <bits/stdc++.h>

using namespace std;

void backtrack(int A, int i, int j, string &row, vector<string> &res)
{
  if (row.size() == 2 * A)
  {
    res.push_back(row);
    return;
  }
  else
  {
    if (i < A)
    {
      row += "(";
      backtrack(A, i + 1, j, row, res);
      row.pop_back();
    }

    if (i > j)
    {
      row += ")";
      backtrack(A, i, j + 1, row, res);
      row.pop_back();
    }
  }
}

vector<string> letterCombinations(int A)
{
  string row;
  vector<string> res;

  backtrack(A, 0, 0, row, res);
  return res;
}

int main()
{
  int v1 = 3;
  vector<string> v2 = letterCombinations(v1);

  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " ";
  }

  return 0;
}
