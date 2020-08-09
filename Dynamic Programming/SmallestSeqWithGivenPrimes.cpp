#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> minSum(int A, int B, int C, int D) {
  vector<int> res;
  set<int> q;
  int t;
  q.insert(A);
  q.insert(B);
  q.insert(C);
  while (D--) {
    t = *q.begin();
    q.erase(q.begin());
    res.push_back(t);
    q.insert(t * A);
    q.insert(t * B);
    q.insert(t * C);
  }

  return res;
}

vector<int> minSum2(int A, int B, int C, int D) {
  vector<int> ans;
  ans.push_back(1);
  int x, y, z;
  x = y = z = 0;
  while (ans.size() <= D) {
    int t;
    t = min(ans[x] * A, min(ans[y] * B, ans[z] * C));
    ans.push_back(t);
    if (ans[x] * A == t)
      x++;
    if (ans[y] * B == t)
      y++;
    if (ans[z] * C == t)
      z++;
  }
  ans.erase(ans.begin());
  return ans;
}

int main() {
  int A = 2, B = 3, C = 5, D = 5;
  vector<int> v2 = minSum(A, B, C, D);

  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
