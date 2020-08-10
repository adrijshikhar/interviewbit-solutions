#include <bits/stdc++.h>

using namespace std;

int atMost(vector<int> &A, int B) {
  int count = 0, left = 0, right = 0, n = A.size();
  map<int, int> mp;

  while (right < n) {
    if (mp.find(A[right]) == mp.end())
      mp[A[right]] = 0;
    mp[A[right]]++;
    while (B < mp.size()) {
      mp[A[left]]--;
      if (mp[A[left]] == 0)
        mp.erase(A[left]);
      left++;
    }
    count += right - left + 1;
    right++;
  }
  return count;
}

int numSumArrays(vector<int> &A, int B) {
  return atMost(A, B) - atMost(A, B - 1);
}

int main() {
  vector<int> v1{
      1, 2, 1, 3, 4,
  };
  int v2 = 3;
  int v3 = numSumArrays(v1, v2);
  cout << v3;

  return 0;
}
