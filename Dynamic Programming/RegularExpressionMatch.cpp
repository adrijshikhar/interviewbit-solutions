#include <bits/stdc++.h>
#define ll long long
using namespace std;

int isMatch(string A, string B)
{
  int m = B.size(), n = A.size();

  vector<vector<int>> IL(n + 1, vector<int>(m + 1, 0));

  IL[0][0] = 1;
  for (int j = 1; j <= m; j++)
    if (B[j - 1] == '*')
      IL[0][j] = IL[0][j - 1];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (B[j - 1] == '*')
        IL[i][j] = IL[i][j - 1] ||
                   IL[i - 1][j];

      else if (B[j - 1] == '?' || A[i - 1] == B[j - 1])
        IL[i][j] = IL[i - 1][j - 1];

      else
        IL[i][j] = 0;
    }
  }

  return IL[n][m];
}

bool strmatch(string txt, string pat)
{
  // empty pattern can only
  // match with empty string.
  // Base Case :
  int n = txt.size(), m = pat.size();
  if (m == 0)
    return (n == 0);

  // step-1 :
  // initailze markers :
  int i = 0, j = 0, index_txt = -1,
      index_pat = -1;

  while (i < n)
  {

    // For step - (2, 5)
    if (j < m && txt[i] == pat[j])
    {
      i++;
      j++;
    }

    // For step - (3)
    else if (j < m && pat[j] == '?')
    {
      i++;
      j++;
    }

    // For step - (4)
    else if (j < m && pat[j] == '*')
    {
      index_txt = i;
      index_pat = j;
      j++;
    }

    // For step - (5)
    else if (index_pat != -1)
    {
      j = index_pat + 1;
      i = index_txt + 1;
      index_txt++;
    }

    // For step - (6)
    else
    {
      return false;
    }
  }

  // For step - (7)
  while (j < m && pat[j] == '*')
  {
    j++;
  }

  // Final Check
  if (j == m)
  {
    return true;
  }

  return false;
}

int main()
{
  string A = "baaabab";
  string B = "*ba*ab";
  int v2 = strmatch(A, B);

  cout << v2 << " ";

  return 0;
}
