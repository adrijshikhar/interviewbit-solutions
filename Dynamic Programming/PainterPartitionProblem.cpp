#include <bits/stdc++.h>
#define ll long long
using namespace std;

int getSum(vector<int> A) {
  int total = 0, n = A.size();
  for (int i = 0; i < n; i++) {
    total += A[i];
  }
  return total;
}

int numberOfPainters(vector<int> A, int maxlen) {
  int total = 0, numPainters = 1;
  int n = A.size();
  for (int i = 0; i < n; i++) {
    total += A[i];
    if (total > maxlen) {
      total = A[i];
      numPainters++;
    }
  }
  return numPainters;
}

int paint(int A, int B, vector<int> &C) {
  long long int n = C.size();
  int lo = *max_element(C.begin(), C.end());
  long int hi = getSum(C);

  while (lo < hi) {
    long long int mid = lo + (hi - lo) / 2;
    long long int requires = numberOfPainters(C, mid);

    if (requires <= A) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  lo = (lo * B) % 10000003;
  return lo;
}

bool isPossible(int A, int B, vector<int> &C, long long int X) {
  int n = C.size();
  long long int t = X;
  int i = 0, cnt = 1;
  while (i < n) {
    if (cnt > A)
      return false;
    if (C[i] > t) {
      cnt++;
      t = X;
    } else {
      t = t - C[i];
      i++;
    }
  }
  return true;
}

int paint2(int A, int B, vector<int> &C) {
  int n = C.size();
  long long int sum = 0;
  for (int i = 0; i < n; i++)
    sum = sum % 10000003 + C[i] % 10000003;
    
  long long int low = 0, high = sum * B;
  long long int ans = high % 10000003;
  while (low <= high) {
    // cout<<low<<" "<<high<<" "<<ans<<endl;
    long long int mid = low + (high - low) / 2;
    if (isPossible(A, B, C, mid / B)) {
      // cout<<"Hi\n";
      ans = mid % 10000003;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return ans % 10000003;
}
int main() {
  vector<int> v{
      {1, 8, 11, 3},
  };

  int v2 = paint(2, 1, v);

  cout << v2 << " ";

  return 0;
}
