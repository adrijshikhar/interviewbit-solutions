#include <bits/stdc++.h>

using namespace std;

int minnode(vector<int> &keyval, vector<bool> &mstset) {
  int mini = INT_MAX, mini_index = 0, n = keyval.size();

  for (int i = 0; i < n; i++) {
    if (mstset[i] == false && keyval[i] < mini) {
      mini = keyval[i];
      mini_index = i;
    }
  }
  return mini_index;
}

int commutableIslands(int A, vector<vector<int>> &B) {

  vector<int> parent(A, 0), keyval(A, INT_MAX);
  vector<bool> mstset(A, false);
  vector<vector<int>> island(A, vector<int>(A, 0));

  for (int i = 0; i < B.size(); i++) {
    island[B[i][0] - 1][B[i][1] - 1] = B[i][2];
    island[B[i][1] - 1][B[i][0] - 1] = B[i][2];
  }

  parent[0] = -1;
  keyval[0] = 0;
  for (int i = 0; i < A - 1; i++) {

    int u = minnode(keyval, mstset);
    mstset[u] = true;
    for (int v = 0; v < A; v++) {

      if (island[u][v] && mstset[v] == false && island[u][v] < keyval[v]) {
        keyval[v] = island[u][v];
        parent[v] = u;
      }
    }
  }

  int cost = 0;
  for (int i = 1; i < A; i++)
    cost += keyval[i];
  return cost;
}

int commutableIslands2(int A, vector<vector<int>> &B) {
  vector<int> nodes;
  set<pair<int, int>> graph[A];

  for (int i = 0; i < B.size(); ++i) {
    graph[--B[i][0]].insert({B[i][2], --B[i][1]});
    graph[B[i][1]].insert({B[i][2], B[i][0]});
  }
  
  nodes.push_back(0);
  unordered_set<int> snodes;
  snodes.insert(0);
  set<pair<int, pair<int, int>>> currmin;
  int sum = 0;
  while (nodes.size() != A) {
    int newid = nodes.back();
    for (auto it = graph[newid].begin(); it != graph[newid].end(); ++it)
      currmin.insert({it->first, {it->second, newid}});

    int id = currmin.begin()->second.first;
    int nd = currmin.begin()->second.second;
    int wt = currmin.begin()->first;

    if (snodes.find(nd) != snodes.end() && snodes.find(id) != snodes.end()) {
      currmin.erase(currmin.begin());
      while (true) {
        id = currmin.begin()->second.first;
        nd = currmin.begin()->second.second;
        wt = currmin.begin()->first;
        if (snodes.find(nd) != snodes.end() && snodes.find(id) != snodes.end())
          currmin.erase(currmin.begin());
        else
          break;
      }
    }
    sum += wt;

    nodes.push_back(id);
    snodes.insert(id);
    currmin.erase(currmin.begin());
    if (currmin.find({wt, {nd, id}}) != currmin.end())
      currmin.erase(currmin.find({wt, {nd, id}}));
    graph[nd].erase({wt, id});
    graph[id].erase({wt, nd});
  }
  return sum;
}
int main() {
  vector<vector<int>> v1{
      {1, 2, 1}, {2, 3, 4}, {1, 4, 3}, {4, 3, 2}, {1, 3, 10},
  };
  int v2 = commutableIslands(4, v1);

  cout << v2 << " ";

  return 0;
}
