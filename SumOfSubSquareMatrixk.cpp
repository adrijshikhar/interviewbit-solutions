#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printSumSimple(vector<vector<int>> &A, int k) {
  int n = A.size();
  int a = 0, b = 0;

  vector<vector<int>> s(n - k + 1, vector<int>(n - k + 1, 0));

  for (int i = 0; i < n - k + 1; i++) {
    b = 0;
    for (int j = 0; j < n - k + 1; j++) {
      int sum = 0;
      for (int p = i; p < k + i; p++)
        for (int q = j; q < k + j; q++)
          sum += A[p][q];
      s[a][b] = sum;
      b++;
    }
    a++;
  }

  return s;
}
vector<vector<int>> printSumTricky(vector<vector<int>> &A, int k) {
  int n = A.size();
  int a = 0, b = 0;
  // k must be smaller than or equal to n

  // 1: PREPROCESSING
  // To store sums of all strips of size k x 1
  vector<vector<int>> stripSum(n, vector<int>(n, 0));

  vector<vector<int>> s(n - k + 1, vector<int>(n - k + 1, 0));

  // Go column by column
  for (int j = 0; j < n; j++) {
    // Calculate sum of first k x 1 rectangle in this column
    int sum = 0;
    for (int i = 0; i < k; i++)
      sum += A[i][j];
    stripSum[0][j] = sum;

    // Calculate sum of remaining rectangles
    for (int i = 1; i < n - k + 1; i++) {
      sum += (A[i + k - 1][j] - A[i - 1][j]);
      stripSum[i][j] = sum;
    }
  }

  // 2: CALCULATE SUM of Sub-Squares using stripSum[][]
  for (int i = 0; i < n - k + 1; i++) {
    // Calculate and print sum of first subsquare in this row
    b = 0;
    int sum = 0;
    for (int j = 0; j < k; j++)
      sum += stripSum[i][j];
    s[i][b++] = sum;

    b = 0;
    for (int j = 1; j < n - k + 1; j++) {
      sum += (stripSum[i][j + k - 1] - stripSum[i][j - 1]);
      s[i][b++] = sum;
    }
  }
  return stripSum;
}

int main() {
  vector<vector<int>> v1{{1, 1, 1, 1, 1},
                         {2, 2, 2, 2, 2},
                         {3, 3, 3, 3, 3},
                         {4, 4, 4, 4, 4},
                         {5, 5, 5, 5, 5}};
  int k = 3;
  vector<vector<int>> v2 = printSumTricky(v1, k);

  for (int i = 0; i < v2.size(); i++) {
    for (int j = 0; j < v2[i].size(); j++) {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
