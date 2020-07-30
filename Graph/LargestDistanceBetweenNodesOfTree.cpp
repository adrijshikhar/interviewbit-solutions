#include <bits/stdc++.h>

using namespace std;

int largestDistance(vector<int> &A)
{
  vector<int> subleaves(A.size(), 0);
  int ans = 0;
  // calculating max number of sub nodes for every node
  for (int i = A.size() - 1; i > 0; i--)
  {
    ans = max(ans, subleaves[A[i]] + subleaves[i] + 1);
    subleaves[A[i]] = max(subleaves[i] + 1, subleaves[A[i]]);
  }

  return ans;
}

int ans;

int maxLen(int u, vector<int> adj[], int p)
{
  vector<int> v;

  for (auto x : adj[u])
  {
    if (x != p)
    {
      v.push_back(maxLen(x, adj, u));
    }
  }

  int nv = v.size();

  if (nv == 0)
  {
    ans = max(ans, 1);
    return 1;
  }

  if (nv == 1)
  {
    ans = max(ans, v[0] + 1);
    return v[0] + 1;
  }

  sort(v.rbegin(), v.rend());

  ans = max(ans, v[0] + v[1] + 1);
  return v[0] + 1;
}

int solve(vector<int> &A)
{
  int n = A.size();

  vector<int> adj[n];

  for (int i = 0; i < n; i++)
  {
    if (A[i] == -1)
      continue;

    adj[A[i]].push_back(i);
    adj[i].push_back(A[i]);
  }

  ans = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  maxLen(0, adj, -1);

  return ans - 1;
}
int main()
{
  vector<int> v1{-1, 0, 1, 1, 2, 0, 5, 0, 3, 0, 0, 2, 3, 1, 12, 14, 0, 5, 9, 6, 16, 0, 13, 4, 17, 2, 1, 22, 14, 20, 10, 17, 0, 32, 15, 34, 10, 19, 3, 22, 29, 2, 36, 16, 15, 37, 38, 27, 31, 12, 24, 29, 17, 29, 32, 45, 40, 15, 35, 13, 25, 57, 20, 4, 44, 41, 52, 9, 53, 57, 18, 5, 44, 29, 30, 9, 29, 30, 8, 57, 8, 59, 59, 64, 37, 6, 54, 32, 40, 26, 15, 87, 49, 90, 6, 81, 73, 10, 8, 16};
  vector<int> v3{-1, 0, 0, 0, 3};
  int v2 = largestDistance(v3);
  cout << v2;

  return 0;
}
