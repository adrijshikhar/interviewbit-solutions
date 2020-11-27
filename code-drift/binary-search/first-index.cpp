#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
  vector<int> ans;

  for (int i = 0; i < B.size(); i++) {
    int v = B[i];
    int f = 1;
    for (int j = 0; j < A.size(); j++) {
      if (v <= A[j]) {
        ans.push_back(j);
        f = 0;
        break;
      }
    }
    if (f) {
      ans.push_back(-1);
    }
  }

  return ans;
}

int main() {

  vector<int> A{2, 3, 4}, B{2, 3, 4};

  vector<int> C = solve(A, B);

  for (int i = 0; i < C.size(); i++) {
    cout << C[i] << " ";
  }

  return 0;
}
