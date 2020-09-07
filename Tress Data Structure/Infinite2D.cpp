#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y) { return (0 <= x && 0 <= y); }

bool spi(int m, int n) {
  int i = m, j = n, t = 0;

  queue<pair<int, int>> q;
  q.push({i, j});
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    if (it.first == 1 && it.second == 1)
      return true;
    int a = it.first - it.second;
    if (isValid(a, it.second))
      q.push({a, it.second});
    if (isValid(it.first, a))
      q.push({it.first, a});
  }

  return false;
}

int main() {

  bool v2 = spi(12, 5);
  cout << v2 << endl;

  return 0;
}
