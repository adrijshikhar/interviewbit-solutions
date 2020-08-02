#include <bits/stdc++.h>

using namespace std;

int goodPath(vector<int> &A, vector<vector<int>> &B, int C)
{
  int n = B.size(), ans = 0, f = 0;

  map<int, vector<int>> mp;

  for (int i = 0; i < n; i++)
  {
    mp[B[i][0]].push_back(B[i][1]);
    mp[B[i][1]].push_back(B[i][0]);
  }

  vector<bool> visited(A.size() + 1, false);
  vector<int> cost = A;
  queue<int> q;

  visited[1] = true;
  q.push(1);

  cost.insert(cost.begin(), 0);
  int s;
  while (!q.empty())
  {
    s = q.front();
    q.pop();
    f = 1;
    for (auto i = mp[s].begin(); i != mp[s].end(); ++i)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        cost[*i] = cost[s] + A[*i - 1];
        q.push(*i);
        f = 0;
      }
    }
    if (f)
    {
      if (cost[s] <= C)
        ans++;
    }
  }

  return ans;
}

int main()
{
  vector<vector<int>> v1{
      {8, 2},
      {6, 3},
      {5, 2},
      {3, 1},
      {4, 2},
      {7, 2},
      {2, 1},
  };
  vector<int> v3{1, 1, 1, 0, 1, 0, 1, 0};
  int v2 = goodPath(v3, v1, 2);

  cout << v2 << " ";

  return 0;
}
