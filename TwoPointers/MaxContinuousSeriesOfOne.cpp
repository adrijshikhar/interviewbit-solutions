#include <bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B) {
  vector<int> ans, temp;
  int right = 0, n = A.size(), c = B, t;

  while (right < n) {
    if (A[right] == 0)
      c--;
    if (c < 0) {

      if (ans.size() < temp.size()) {
        ans = temp;
      }

      while (temp.size()) {
        t = *temp.begin();
        temp.erase(temp.begin());
        if (A[t] == 0) {
          c++;
          break;
        }
      }
    }
    temp.push_back(right);

    right++;
  }
  if (ans.size() < temp.size())
    ans = temp;

  return ans;
}

int main() {
  vector<int> v1{
      1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,
  };
  int m = 4;

  vector<int> v2 = maxone(v1, m);
  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";

  return 0;
}
