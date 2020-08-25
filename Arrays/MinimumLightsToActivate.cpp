#include <bits/stdc++.h>

using namespace std;

int minLights(vector<int> &A, int B) {
  int n = A.size();
  vector<int> light(n + 1, 0);

  int x = 0;
  for (int y : A) {
    x++;
    if (y == 1) {
      int l = max(x - B + 1, 1);
      int r = x + B - 1;
      light[l - 1] = r;
    }
  }
  if (light[0] == 0)
    return -1;
  int cnt = 1;
  int maxReach = 0;
  int reach = light[0];
  for (int i = 1; i <= n; i++) {
    maxReach = max(maxReach, light[i]);
    if (reach == i && i != n) {
      cnt++;
      reach = maxReach;
    }
  }
  return cnt;
}

int main() {
  vector<int> A{1, 1, 1, 1};

  int v2 = minLights(A, 3);

  cout << v2;
  return 0;
}
