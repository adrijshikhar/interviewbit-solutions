#include <bits/stdc++.h>

using namespace std;
bool isPalindrome(const string s, int i, int j)
{
  while (i < j)
  {
    if (s[i] == s[j])
    {
      ++i;
      --j;
    }
    else
      return false;
  }
  return true;
}
void backtrack(const string &A, int i, vector<string> &row, vector<vector<string>> &res)
{
  if (i == A.length())
  {
    res.push_back(row);
    return;
  }

  for (int x = i; x < A.length(); ++x)
  {
    if (isPalindrome(A, i, x))
    {
      row.push_back(A.substr(i, x - i + 1));
      backtrack(A, x + 1, row, res);
      row.pop_back();
    }
  }
}

vector<vector<string>> letterCombinations(string A)
{
  vector<string> row;
  vector<vector<string>> res;
  backtrack(A, 0, row, res);
  return res;
}

int main()
{
  string v1 = "aab";
  vector<vector<string>> v2 = letterCombinations(v1);

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
