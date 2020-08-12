#include <bits/stdc++.h>

using namespace std;

int path(int A, vector<int> &B, vector<int> &C) {
  int n = B.size();
  if (1 == A)
    return true;

  unordered_map<int, vector<int>> mp;

  for (int i = 0; i < n; i++)
    mp[C[i]].push_back(B[i]);

  vector<bool> visited(A + 1, false);

  queue<int> q;

  visited[A] = true;
  q.push(A);

  int s;
  while (!q.empty()) {
    s = q.front();
    q.pop();

    for (auto i = mp[s].begin(); i != mp[s].end(); ++i) {
      if (visited[*i] && mp[*i].size() != 0)
        return false;

      if (!visited[*i]) {
        visited[*i] = true;
        q.push(*i);
      }
    }
  }

  return true;
}

vector<int> g[100005];


void check_cycle(int u, int visited[], bool &f) {
  visited[u] = 1;
  for (auto v : g[u]) {
    if (visited[v] == 0) {
      check_cycle(v, visited, f);
    } else if (visited[v] == 1) {
      f = true;
    }
  }
  visited[u] = 2;
}

int solve(int N, vector<int> &B, vector<int> &C) {
  bool f = false;
  int visited[100005] = {0};
  for (int i = 1; i <= N; i++) {
    g[i].clear();
  }
  for (int i = 0; i < B.size(); i++) {
    g[B[i]].push_back(C[i]);
  }
  for (int i = 1; i <= N; i++) {
    if (visited[i] == 0) {
      check_cycle(i, visited, f);
      if (f) {
        break;
      }
    }
  }
  return !f;
}

int main() {
  vector<int> B{1, 2, 3}, C{2, 3, 1};
  int v2 = path(3, B, C);

  cout << v2 << " ";

  return 0;
}
