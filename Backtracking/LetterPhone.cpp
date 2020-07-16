#include <bits/stdc++.h>

using namespace std;

string getString(char ch)
{
  switch (ch)
  {
  case '1':
    return "1";
  case '2':
    return "abc";
  case '3':
    return "def";
  case '4':
    return "ghi";
  case '5':
    return "jkl";
  case '6':
    return "mno";
  case '7':
    return "pqrs";
  case '8':
    return "tuv";
  case '9':
    return "wxyz";
  default:
    return "0";
  }
}
void backtrack(vector<string> str, int st, vector<string> &v, string &v1, int limit)
{
  if (v1.size() == limit)
  {
    v.push_back(v1);
    return;
  }
  for (int i = 0; i < str[st].size(); i++)
  {
    v1.push_back(str[st][i]);
    backtrack(str, st + 1, v, v1, limit);
    v1.pop_back();
  }
}

vector<string> letterCombinations(string A)
{
  vector<string> v;
  string v1;
  vector<string> str;
  int n = A.size();
  for (int i = 0; i < A.size(); i++)
  {
    str.push_back(getString(A[i]));
  }

  backtrack(str, 0, v, v1, n);

  return v;
}

int main()
{
  string v1 = "10";
  vector<string> v2 = letterCombinations(v1);

  for (int i = 0; i < v2.size(); i++)
  {
    cout << v2[i] << " | ";
  }

  return 0;
}
