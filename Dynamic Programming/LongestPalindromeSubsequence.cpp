#include <bits/stdc++.h>

using namespace std;

struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

int lps(string A)
{
  int n = A.size();
  int i, j, cl;
  int L[n][n];
  for (i = 0; i < n; i++)
    L[i][i] = 1;

  for (cl = 2; cl <= n; cl++)
  {
    for (i = 0; i < n - cl + 1; i++)
    {
      j = i + cl - 1;
      if (A[i] == A[j] && cl == 2)
        L[i][j] = 2;
      else if (A[i] == A[j])
        L[i][j] = L[i + 1][j - 1] + 2;
      else
        L[i][j] = max(L[i][j - 1], L[i + 1][j]);
    }
  }

  return L[0][n - 1];
}

unordered_map<pair<int, int>, int, hash_pair> mp;

int lps2(string A, int i, int j)
{
  if (i == j)
    return 1;

  if (A[i] == A[j] && i + 1 == j)
    return 2;
  if (A[i] == A[j])
  {
    if (mp.find(make_pair(i + 1, j - 1)) == mp.end())
      return lps2(A, i + 1, j - 1) + 2;
    return mp[make_pair(i + 1, j - 1)];
  }
  if (mp.find(make_pair(i, j - 1)) == mp.end())
    mp[make_pair(i, j - 1)] = lps2(A, i, j - 1);
  if (mp.find(make_pair(i, j - 1)) == mp.end())
    mp[make_pair(i + 1, j)] = lps2(A, i + 1, j);

  return max(mp[make_pair(i, j - 1)], mp[make_pair(i + 1, j)]);
}

int main()
{
  string v = "bedeeed";
  int v2 = lps2(v, 0, v.size() - 1);

  cout << v2 << " ";

  return 0;
}
