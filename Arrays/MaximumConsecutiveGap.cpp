#include <bits/stdc++.h>
using namespace std;

int maximumGap(vector<int> &A) {
  if (A.size() < 2) {
    return 0;
  }
  int n = A.size();
  int maxVal = A[0], minVal = A[0];

  for (int i = 1; i < n; i++) {
    maxVal = max(maxVal, A[i]);
    minVal = min(minVal, A[i]);
  }
  vector<int> maxBucket(n - 1, INT_MIN);
  vector<int> minBucket(n - 1, INT_MAX);

  float delta = (float)(maxVal - minVal) / (float)(n - 1);
  for (int i = 0; i < n; i++) {
    if (A[i] == maxVal || A[i] == minVal) {
      continue;
    }
    int index = (float)(floor(A[i] - minVal) / delta);

    if (maxBucket[index] == INT_MIN) {
      maxBucket[index] = A[i];
    } else {
      maxBucket[index] = max(maxBucket[index], A[i]);
    }

    if (minBucket[index] == INT_MAX) {
      minBucket[index] = A[i];
    } else {
      minBucket[index] = min(minBucket[index], A[i]);
    }
  }

  int prev_val = minVal;
  int max_gap = 0;
  for (int i = 0; i < n - 1; i++) {
    if (minBucket[i] == INT_MAX)
      continue;
    max_gap = max(max_gap, minBucket[i] - prev_val);
    prev_val = maxBucket[i];
  }
  max_gap = max(max_gap, maxVal - prev_val);

  return max_gap;
}

int main() {
  vector<int> v1{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int v2 = maximumGap(v1);
  cout << v2;
  return 0;
}
