#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> longestConsecutive(vector<int> &A) {
  int n = A.size();
  vector<vector<int>> B(n, vector<int>(3, 0));

  for (int i = 0; i < n; i++) {
    B[i][0] = A[i];
  }

  stack<int> s;
  int i = n - 1;
  while (i >= 0) {
    if (s.empty()) {
      B[i][2] = n;
      s.push(i);
      i--;
    } else if (A[s.top()] > A[i]) {
      B[i][2] = s.top();
      s.push(i);
      i--;
    } else
      s.pop();
  }
  stack<int> s2;
  i = 0;
  while (i < n) {
    if (s2.empty()) {
      B[i][1] = 1;
      s2.push(i);
      i++;
    } else if (A[i] < A[s2.top()]) {
      B[i][1] = s2.top() + 2;
      s2.push(i);
      i++;
    } else
      s2.pop();
  }

  return B;
}

int main() {
  vector<int> v1{34, 35, 27, 42, 5, 28, 39, 20, 28};
  vector<vector<int>> v2 = longestConsecutive(v1);

  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v2[i].size(); j++) {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
