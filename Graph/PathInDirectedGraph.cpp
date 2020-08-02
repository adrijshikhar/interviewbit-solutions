#include <bits/stdc++.h>

using namespace std;

int path(int A, vector<vector<int>> &B)
{
  int n = B.size();
  if (1 == A)
    return true;

  unordered_map<int, vector<int>> mp;

  for (int i = 0; i < n; i++)
    mp[B[i][0]].push_back(B[i][1]);

  vector<bool> visited(A + 1, false);

  queue<int> q;


  visited[1] = true;
  q.push(1);

  int s;
  while (!q.empty())
  {
    s = q.front();
    q.pop();

    for (auto i = mp[s].begin(); i != mp[s].end(); ++i)
    {
      if (*i == A)
        return true;

      if (!visited[*i])
      {
        visited[*i] = true;
        q.push(*i);
      }
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> v1{{1, 3}, {2, 3}, {3, 1}};
  int v2 = path(3, v1);

  cout << v2 << " ";

  return 0;
}
