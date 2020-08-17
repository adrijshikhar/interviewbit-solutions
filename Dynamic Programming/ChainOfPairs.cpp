#include <bits/stdc++.h>
using namespace std;

int chainOfPairs(vector<vector<int>> &A) {
  vector<int> lis(A.size(), 1);
  for (int i = 1; i < A.size(); i++)
    for (int j = 0; j < i; j++)
      if (A[j][1] < A[i][0] && lis[j] + 1 > lis[i])
        lis[i] = lis[j] + 1;
  return *max_element(lis.begin(), lis.end());
}

int main() {
  vector<vector<int>> v1{
      {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90},
  };
  int v2 = chainOfPairs(v1);

  cout << v2 << " ";

  return 0;
}
