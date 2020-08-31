#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubArrayOfSizeK(vector<int> &A, int k) {
  int n = A.size();
  deque<int> Qi(k);
  vector<int> B;
  int i;
  for (i = 0; i < k; ++i) {
    while ((!Qi.empty()) && A[i] >= A[Qi.back()])
      Qi.pop_back();

    Qi.push_back(i);
  }

  // Process rest of the elements, i.e., from A[k] to A[n-1]
  for (; i < n; ++i) {
    // The element at the front of the queue is the largest element of
    // previous window, so print it
    B.push_back(A[Qi.front()]);

    // Remove the elements which are out of this window
    while ((!Qi.empty()) && Qi.front() <= i - k)
      Qi.pop_front(); // Remove from front of queue

    // Remove all elements smaller than the currently
    // being added element (remove useless elements)
    while ((!Qi.empty()) && A[i] >= A[Qi.back()])
      Qi.pop_back();

    // Add current element at the rear of Qi
    Qi.push_back(i);
  }

  // Print the maximum element of last window
  B.push_back(A[Qi.front()]);
  return B;
}

int main() {
  vector<int> A{2, 1, 13, 87, 5, 12, 11, 43};
  int k = 3;
  vector<int> v2 = maxOfSubArrayOfSizeK(A, k);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << ' ';
  }

  return 0;
}
